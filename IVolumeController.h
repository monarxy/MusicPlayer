#ifndef IVOLUMECONTROLLER_H
#define IVOLUMECONTROLLER_H

class IVolumeController{
public:
    virtual void changeVolumeReceive(const int) = 0;
};

#endif // IVOLUMECONTROLLER_H
