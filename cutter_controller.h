#ifndef CUTTER_CONTROLLER_H
#define CUTTER_CONTROLLER_H
#include <QObject>
#include "cutter_item.h"
#include "media_cutter.h"
#include <taglib/fileref.h>

class CutterController : public QObject
{
    Q_OBJECT
    int player_type;
public:
    CutterController(QObject *parent = nullptr);
    ~CutterController();

    void cut(const CutterItem&);

signals:

};

#endif // CUTTER_CONTROLLER_H
