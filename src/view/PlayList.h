#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QWidget>
#include "src/tool/EventFilter.h"
#include "src/tool/Database.h"

namespace Ui {
class PlayList;
}

class PlayList : public QWidget
{
    Q_OBJECT

public:
    explicit PlayList(QWidget *parent = nullptr);
    ~PlayList();

    static PlayList* getInstance(QWidget *parent = nullptr);  // 获取单例窗口实例

protected:
    // 重载 showEvent 事件处理函数
    void showEvent(QShowEvent *event) override;

public slots:
    void downloadSong(const QString &songUrl);

private:
    Ui::PlayList *ui;
    EventFilter *filter;  // 存储过滤器对象的指针

    struct Song {
        int id;            // 歌曲ID
        QString songName;  // 歌曲名
        QString artist;    // 歌手
        bool isVip;        // 是否VIP
        QString duration;  // 时长

        // 构造函数方便初始化
        Song(int id, const QString& songName, const QString& artist, bool isVip, const QString& duration)
            : id(id), songName(songName), artist(artist), isVip(isVip), duration(duration) {}
    };

    void query();
    void populateList(const QList<Song>& songs);
    void initializeStyle();
    void clear();

    // 数据库对象作为成员变量，避免每次都重新连接
    Database *db;
};

#endif // PLAYLIST_H
