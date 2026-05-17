#ifndef RADIOFORM_H
#define RADIOFORM_H

#include <QWidget>

namespace Ui {
class RadioForm;
}

class RadioForm : public QWidget
{
    Q_OBJECT

public:
    explicit RadioForm(QWidget *parent = nullptr);
    ~RadioForm();
signals:
    void FormClicked(const QString& form_name);
    void PlayClicked();

private slots:
    void on_pushButton_clicked();

private:
    Ui::RadioForm *ui;
};

#endif // RADIOFORM_H
