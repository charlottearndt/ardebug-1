#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <vector>

#include <QObject>
#include <QString>
#include <QStringList>
#include <QStringListModel>

#include "robotdata.h"

#define PACKET_TYPE_WATCHDOG        0
#define PACKET_TYPE_STATE           1
#define PACKET_TYPE_POSITION        2
#define PACKET_TYPE_PROXIMITY       3
#define PACKET_TYPE_BACKGROUND_IR   4
#define PACKET_TYPE_MSG             5
#define PACKET_TYPE_CUSTOM          6
#define PACKET_TYPE_INVALID         7

class DataModel : public QObject
{
    Q_OBJECT
    QStringListModel* robotListModel;
    std::vector<RobotData*> robotDataList;

public:
    int selectedRobotID;

    Vector2D averageRobotPos;

    explicit DataModel(QObject *parent = 0);
    ~DataModel(void);

    RobotData* getRobotByIndex(int idx);
    RobotData* getRobotByID(int id);

    QStringListModel* getRobotList(void);

    int getRobotIndex(int id, bool create = true);
    int getRobotCount(void);

private:
    void parsePositionPacket(RobotData* robot, QString xString, QString yString, QString aString);
    void parseProximityPacket(RobotData* robot, QStringList data, bool background);
    void updateAveragePosition(void);

signals:
    void modelChanged(bool listChanged);

public slots:
    void newData(const QString &);
    void deleteRobot(int ID);
};

#endif // DATAMODEL_H
