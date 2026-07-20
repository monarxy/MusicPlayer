#ifndef ICONTINUOUSPLAYER_H
#define ICONTINUOUSPLAYER_H

class IContinuousPlayer{
    virtual void automaticallyNextReceive(const qint64, const int) = 0;
};

#endif // ICONTINUOUSPLAYER_H
