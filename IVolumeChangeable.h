#ifndef IVOLUMECHANGEABLE_H
#define IVOLUMECHANGEABLE_H

class IVolumeChangeable{
public:
    virtual void changeVolume(const int) = 0;
    virtual ~IVolumeChangeable() = default;
};

#endif // IVOLUMECHANGEABLE_H
