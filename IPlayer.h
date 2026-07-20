#ifndef IPLAYER_H
#define IPLAYER_H

template<typename T>
class IPlayer {
public:
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
    virtual void next() = 0;
    virtual void previous()=0;
    virtual void setCurrent(const int) = 0;
    virtual const T* getCurrentItem() const = 0;
    virtual void deleteCurrent() = 0;

    virtual ~IPlayer() = default;
};

#endif // IPLAYER_H
