#ifndef IDELETEITEMSINPLAYLISTMANAGEMENT_H
#define IDELETEITEMSINPLAYLISTMANAGEMENT_H

template <typename T>
class IDeleteItemsInPlaylistManagement{
public:
    virtual void deleteItem(T*) = 0;
};

#endif // IDELETEITEMSINPLAYLISTMANAGEMENT_H
