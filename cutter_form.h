#ifndef CUTTER_FORM_H
#define CUTTER_FORM_H

#include <QWidget>
#include <QFileDialog>
#include "cutter_item.h"

namespace Ui {
class CutterForm;
}

class CutterForm : public QWidget
{
    Q_OBJECT

public:
    explicit CutterForm(QWidget *parent = nullptr);
    ~CutterForm();

signals:
    void FormClicked(const QString&);
    void CutRequest(const CutterItem&);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::CutterForm *ui;
    CutterItem cutter_item;
};

#endif // CUTTER_FORM_H
