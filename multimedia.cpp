#include "multimedia.h"

MediaPlayer::MediaPlayer(QObject* parent, MediaLoader* loader)
    : QObject(parent)
    , m_player(nullptr)
    , playlist(nullptr)
    , current_item(nullptr)
    , serializer(loader)
{
}

MediaPlayer::~MediaPlayer()
{
}
