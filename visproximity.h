#ifndef VISPROXIMITY_H
#define VISPROXIMITY_H

#include "viselement.h"
#include "proximitysettingsdialog.h"

#include <QDialog>

class VisProximity : public VisElement
{
public:
    VisProximity();
    ~VisProximity();

    virtual QString toString(void);

    virtual void render(cv::Mat image, RobotData *robot, bool selected);

    virtual QDialog* getSettingsDialog(void);

    void setSelectedOnly(bool enable);
    bool getSelectedOnly(void);

    void setHeatMode(bool enable);
    bool getHeatMode(void);

    // Sensor Angles
    int sensorAngles[8] = {12, 45, 90, 135, 225, 270, 315, 348};

private:
    ProximitySettingsDialog* settingsDialog;

    // Settings
    bool selectedOnly;
    bool heatMode;
};

#endif // VISPROXIMITY_H
