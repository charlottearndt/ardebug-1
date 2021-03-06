#ifndef VISELEMENT_H
#define VISELEMENT_H

#include <QString>
#include <QDialog>

#include "../DataModel/robotdata.h"

enum VisType { ID, NAME, STATE, POSITION, DIRECTION, PROXIMITY, PATH, CUSTOM };

class VisElement
{
private:
    VisType type;
    bool enabled;

public:
    virtual ~VisElement(void) { }

    void setType(VisType t) { type = t; }
    VisType getType(void) { return type; }

    void setEnabled(bool en) { enabled = en; }
    bool isEnabled(void) { return enabled; }

    virtual void render(QWidget* widget, QPainter* painter, RobotData* robot, bool selected, QRectF rect) = 0;

    virtual QDialog* getSettingsDialog(void) = 0;
};

Q_DECLARE_METATYPE(VisElement*)

#endif // VISELEMENT_H
