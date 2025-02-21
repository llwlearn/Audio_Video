#ifndef RECENTLYPLAYED_H
#define RECENTLYPLAYED_H

#include <QWidget>

#include "src/tool/Database.h"

namespace Ui {
class RecentlyPlayed;
}

class RecentlyPlayed : public QWidget
{
    Q_OBJECT

public:
    explicit RecentlyPlayed(QWidget *parent = nullptr);
    ~RecentlyPlayed();

public slots:
    void downloadSong(const QString &songUrl);

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    Ui::RecentlyPlayed *ui;

    struct Song {
        int id;            // 歌曲ID
        QString songName;  // 歌曲名
        QString artist;    // 歌手
        QString album;     // 专辑
        bool isVip;        // 是否VIP
        QString duration;  // 时长

        // 构造函数方便初始化
        Song(int id, const QString& songName, const QString& artist,QString album, bool isVip, const QString& duration)
            : id(id), songName(songName), artist(artist),album(album), isVip(isVip), duration(duration) {}
    };

    void populateList(const QList<Song>& songs);
    void initializeStyle();

    // 数据库对象作为成员变量，避免每次都重新连接
    Database database;

    void query();

};

#endif // RECENTLYPLAYED_H
