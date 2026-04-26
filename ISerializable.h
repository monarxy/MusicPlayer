#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H
#include <QString>

class ISerializable{
public:
    virtual void load() = 0;
    virtual void save() = 0;
    virtual ~ISerializable() = default;
};

#endif // ISERIALIZABLE_H
