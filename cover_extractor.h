#ifndef COVER_EXTRACTOR_H
#define COVER_EXTRACTOR_H
#include <taglib/fileref.h>
#include <taglib/tag.h>
#include <taglib/attachedpictureframe.h>
#include <taglib/flacfile.h>
#include <taglib/mpegfile.h>
#include <taglib/oggfile.h>
#include <taglib/mp4file.h>
#include <taglib/xiphcomment.h>
#include <taglib/id3v2tag.h>
#include <QPixmap>

class CoverExtractor
{
public:
    CoverExtractor();
    QPixmap extractCoverUniversal(const QString &filePath);
};

#endif // COVER_EXTRACTOR_H
