#ifndef EDITORFORM_H
#define EDITORFORM_H

#include <QWidget>

namespace Ui {
class EditorForm;
}

class EditorForm : public QWidget
{
    Q_OBJECT

public:
    explicit EditorForm(QWidget *parent);
    ~EditorForm();

private:
    Ui::EditorForm *ui;
};

#endif // EDITORFORM_H
