#ifndef EDITORFORM_H
#define EDITORFORM_H

#include <QWidget>
#include "playlist.h"
#include "songs_data.h"
#include "navigation_controller.h"

namespace Ui {
class EditorForm;
}

class EditorForm : public QWidget
{
    Q_OBJECT

public:
    explicit EditorForm(QWidget *parent, NavigationController *navigation_controller);
    ~EditorForm();
    void setTracks(Playlist*);

private:
    Ui::EditorForm *ui;
    Playlist* playlist;
    NavigationController* navigation_controller;

};

#endif // EDITORFORM_H
