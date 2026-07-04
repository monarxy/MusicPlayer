#ifndef RADIOFORM_H
#define RADIOFORM_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class RadioForm;
}

class RadioForm : public QWidget
{
    Q_OBJECT

public:
    explicit RadioForm(QWidget *parent = nullptr);
    ~RadioForm();
    void setPlaylist(const QStringList& list_of_tracks);
signals:
    void FormClicked(const QString&);
    void PlayClicked();
    void PreviousClicked();
    void NextClicked();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::RadioForm *ui;
    QStandardItemModel  *m_playListModel;
};

#endif // RADIOFORM_H
