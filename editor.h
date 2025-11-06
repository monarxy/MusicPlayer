#ifndef EDITOR_H
#define EDITOR_H

#include <vector>
#include <QString>
#include "sound_effect.h"

class Editor{
private:
    QString current_track;
    std::vector<SoundEffect*> vector_of_effects;
    SoundEffect* current_effect;
public:
    Editor();
    setCurrentTrack(QString);
    setCurrentEffect(int);
    cutTrack(double start, double end);
}

#endif // EDITOR_H
