#ifndef FFMPEGWORKER_H
#define FFMPEGWORKER_H

#include <QObject>
#include <QFileInfoList>
#include <QMediaMetaData>

struct Song {
    int id;            // 歌曲ID
    QString songName;  // 歌曲名
    QString artist;    // 歌手
    bool isVip;        // 是否VIP
    QString duration;  // 时长

    // 构造函数方便初始化
    Song(int id = -1, const QString& songName = "", const QString& artist = "", bool isVip = false, const QString& duration = "")
        : id(id), songName(songName), artist(artist), isVip(isVip), duration(duration) {}
};

class FfmpegWorker : public QObject
{
    Q_OBJECT

public:
    explicit FfmpegWorker(const QFileInfoList &fileList, QObject *parent = nullptr);
    FfmpegWorker(); // 添加无参构造函数
    void processFiles();

    Song findSongBySongPath(const QString &songPath);

signals:
    void metaDataReady(const QMediaMetaData &meta);
    void finished();

private:
    QFileInfoList fileList;
};

#endif // FFMPEGWORKER_H
