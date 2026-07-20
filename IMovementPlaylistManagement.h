#ifndef IMOVEMENTPLAYLISTMANAGEMENT_H
#define IMOVEMENTPLAYLISTMANAGEMENT_H

template <typename T>
class IMovementPlaylistManagement{
public:
    virtual T* getNextItem(T*) const = 0;
    virtual T* getPreviousItem(T*) const = 0;
};

#endif // IMOVEMENTPLAYLISTMANAGEMENT_H
