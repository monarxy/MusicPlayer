#ifndef EDITORFORM_H
#define EDITORFORM_H

#include <QWidget>
#include "playlist.h"
#include "songs_data.h"

namespace Ui {
class EditorForm;
}

class EditorForm : public QWidget
{
    Q_OBJECT

public:
    explicit EditorForm(QWidget *parent);
    ~EditorForm();
    void setTracks(Playlist*);

private:
    Ui::EditorForm *ui;
    Playlist* playlist;

};

#endif // EDITORFORM_H
