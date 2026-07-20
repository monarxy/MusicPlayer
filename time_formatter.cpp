#include "time_formatter.h"

TimeFormatter::TimeFormatter() {}

QString TimeFormatter::formatTime(qint64 milliseconds) {
    int seconds = milliseconds / 1000;
    int minutes = seconds / 60;
    seconds = seconds % 60;

    return QString("%1:%2")
        .arg(minutes, 2, 10, QChar('0'))
        .arg(seconds, 2, 10, QChar('0'));
}
