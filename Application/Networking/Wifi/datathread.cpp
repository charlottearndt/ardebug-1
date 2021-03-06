/* datathread.cpp
 *
 * This class encapsulates a threaded UDP packet receiver. Data
 * that is received is sent to the main thread via the Qt signals
 * and slots system.
 *
 * (C) Alistair Jewers Jan 2017
 */

#include "datathread.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include "QString"

/* Destructor
 * Delete necessary data.
 */
DataThread::~DataThread(void) { }

/* openUDPSocket
 * Opens a UDP socket on the given port, and begins listening for data.
 */
void DataThread::openUDPSocket(int port) {
    struct sockaddr_in sock_in;

    // Create the socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        fprintf(stderr, "Error creating socket\n");
        return;
    }

    // Zero the structure
    bzero(&sock_in, sizeof(sock_in));

    // Set up the socket structure
    sock_in.sin_addr.s_addr = htonl(INADDR_ANY);
    sock_in.sin_port = htons(port);
    sock_in.sin_family = AF_INET;

    // Bind the socket
    if (bind(sockfd, (struct sockaddr*)&sock_in, sizeof(sock_in)) < 0) {
        fprintf(stderr, "Error binding socket\n");
        return;
    }

    // Signal that the socket was opened successfully
    emit socketOpened(sockfd);

    // Start the data read timer
    readTimer = new QTimer(this);
    connect(readTimer, SIGNAL(timeout()), this, SLOT(listenForPacket()));
    readTimer->start(1);
}

/* listenForPacket
 * Listens for data on the UDP socket. Blocking.
 */
void DataThread::listenForPacket(void) {
    struct sockaddr_in si_other;
    int slen = sizeof(si_other), recv_len;
    char buffer[256];

    // Pause the timer
    readTimer->stop();

    // Clear the buffer
    bzero(buffer, 256);

    // Receive a packet (blocking)
    recv_len = recvfrom(sockfd, buffer, 255, 0, (struct sockaddr*)&si_other, (socklen_t *)&slen);
    if (recv_len < 0) {
        fprintf(stderr, "Error reading data\n");
        return;
    }

    // Check if close packet received
    if (strcmp(buffer, "close") == 0) {
        close(sockfd);
        delete readTimer;
    } else {
        // Emit received data through signal
        QString str;
        str.sprintf("%s", buffer);
        emit dataFromThread(str);

        // Restart the timer
        readTimer->start(1);
    }
}
