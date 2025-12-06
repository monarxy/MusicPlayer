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
    EditorForm(QWidget *parent);
    ~EditorForm();
signals:
    void HomeClicked();

private:
    Ui::EditorForm *ui;

};

#endif // EDITORFORM_H
