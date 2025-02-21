#ifndef SEARCHFOR_H
#define SEARCHFOR_H

#include <QWidget>
#include <QObject>
#include <QPushButton>

#include "src/tool/Database.h"

namespace Ui {
class SearchFor;
}

class SearchFor : public QWidget
{
    Q_OBJECT

public:
    explicit SearchFor(QWidget *parent = nullptr);
    ~SearchFor();

    void performDatabaseQuery(const QString &searchText);

public slots:
    void downloadSong(const QString &songUrl);

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    Ui::SearchFor *ui;

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
    Database *db;

    void onIdButtonClicked(const Song& song);
};

#endif // SEARCHFOR_H
