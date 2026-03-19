#include "editorform.h"
#include "ui_editorform.h"

EditorForm::EditorForm()
    : ui(new Ui::EditorForm)
{
    ui->setupUi(this);
}

EditorForm::~EditorForm()
{
    delete ui;
}
