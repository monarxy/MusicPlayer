#ifndef LIST_OF_RADIOPLAYLIST_ITEMS_H
#define LIST_OF_RADIOPLAYLIST_ITEMS_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class ListOfRadioPlaylistItems;
}

class ListOfRadioPlaylistItems : public QWidget
{
    Q_OBJECT

public:
    explicit ListOfRadioPlaylistItems(QWidget *parent = nullptr);
    ~ListOfRadioPlaylistItems();
signals:
    void FormClicked(const QString&);
    void ItemsListClicked(const int);
private slots:
    void on_songsView_clicked(const QModelIndex &index);

private:
    Ui::ListOfRadioPlaylistItems *ui;
    QStandardItemModel  *m_playListModel;
};

#endif // LIST_OF_RADIOPLAYLIST_ITEMS_H
