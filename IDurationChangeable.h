#ifndef IDURATIONCHANGEABLE_H
#define IDURATIONCHANGEABLE_H

class IDurationChangeable{
public:
    virtual void changeDuration(const int) = 0;
    virtual ~IDurationChangeable() = default;
};

#endif // IDURATIONCHANGEABLE_H
