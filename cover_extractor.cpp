#include "cover_extractor.h"

CoverExtractor::CoverExtractor() {}


QPixmap CoverExtractor::extractCoverUniversal(const QString &filePath) {
    std::string localPath = filePath.toLocal8Bit().toStdString();
    TagLib::FileRef fileRef(localPath.c_str());

    if (fileRef.isNull() || !fileRef.file()) {
        return QPixmap();
    }

    TagLib::File *file = fileRef.file();
    TagLib::ByteVector pictureData;


    if (TagLib::MPEG::File *mpegFile = dynamic_cast<TagLib::MPEG::File*>(file)) {
        if (TagLib::ID3v2::Tag *tag = mpegFile->ID3v2Tag()) {
            TagLib::ID3v2::FrameListMap frameMap = tag->frameListMap();
            TagLib::ID3v2::FrameList frames = frameMap["APIC"];
            if (frames.isEmpty()) {
                frames = frameMap["PIC"];
            }
            if (!frames.isEmpty()) {
                TagLib::ID3v2::AttachedPictureFrame *pictureFrame =
                    dynamic_cast<TagLib::ID3v2::AttachedPictureFrame*>(frames.front());
                if (pictureFrame) {
                    pictureData = pictureFrame->picture();
                }
            }
        }
    }

    else if (TagLib::FLAC::File *flacFile = dynamic_cast<TagLib::FLAC::File*>(file)) {
        auto pictures = flacFile->pictureList();
        if (!pictures.isEmpty()) {
            pictureData = pictures.front()->data();
        }
    }

    else if (TagLib::Ogg::File *oggFile = dynamic_cast<TagLib::Ogg::File*>(file)) {
        TagLib::Ogg::XiphComment *comment = static_cast<TagLib::Ogg::XiphComment*>(oggFile->tag());
        if (comment) {
            TagLib::StringList keys = comment->fieldListMap()["METADATA_BLOCK_PICTURE"];
            if (!keys.isEmpty()) {
                pictureData = TagLib::ByteVector::fromBase64(keys.front().toCString());
            }
        }
    }

    else if (TagLib::MP4::File *mp4File = dynamic_cast<TagLib::MP4::File*>(file)) {
        TagLib::MP4::Tag *mp4Tag = mp4File->tag();
        if (mp4Tag) {
            TagLib::MP4::ItemMap itemMap = mp4Tag->itemMap();
            TagLib::MP4::ItemMap::Iterator it = itemMap.find("covr");
            if (it != itemMap.end()) {
                TagLib::MP4::CoverArtList coverArtList = it->second.toCoverArtList();
                if (!coverArtList.isEmpty()) {
                    pictureData = coverArtList.front().data();
                }
            }
        }
    }

    if (!pictureData.isEmpty()) {
        QImage image;
        if (image.loadFromData(reinterpret_cast<const uchar*>(pictureData.data()), pictureData.size())) {
            return QPixmap::fromImage(image);
        }
    }

    return QPixmap();
}
