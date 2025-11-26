#include "editorform.h"
#include "ui_editorform.h"

EditorForm::EditorForm(QWidget *parent, NavigationController *_navigation_controller)
    : QWidget(parent)
    , ui(new Ui::EditorForm)
{
    ui->setupUi(this);
    navigation_controller = _navigation_controller;
}

EditorForm::~EditorForm()
{
    delete ui;
}
