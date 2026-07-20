#ifndef TIME_FORMATTER_H
#define TIME_FORMATTER_H
#include <QString>

class TimeFormatter
{
public:
    TimeFormatter();
    QString formatTime(qint64);
};

#endif // TIME_FORMATTER_H
