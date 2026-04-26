#ifndef PLAYER_H
#define PLAYER_H

class Player{
public:
    virtual void load() = 0;
    virtual void save() = 0;
    virtual ~ISerializable() = default;
};

#endif // PLAYER_H
