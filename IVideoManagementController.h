#ifndef IVIDEOMANAGEMENTCONTROLLER_H
#define IVIDEOMANAGEMENTCONTROLLER_H
#include <QtMultimediaWidgets/QVideoWidget>

class IVideoManagementController{
public:
    virtual void setVideoOutput(QVideoWidget*) = 0;
};

#endif // IVIDEOMANAGEMENTCONTROLLER_H
