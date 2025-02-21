#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QStringList>
#include <QString>

#include "Database.h"

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = nullptr);
    ~Player();

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

    void uploadToRecentlyPlayed(); // 上传当前播放歌曲到最近播放数据库

    void addSongToPlaylist(const Song &song); // 添加新歌曲进入播放列表

    void loadMusicFromDatabase();//加载音乐列表

    // 播放控制
    void play();  // 开始播放当前媒体文件
    void pause(); // 暂停播放
    void stop();  // 停止播放
    void next();  // 播放下一个媒体文件
    void previous();  // 播放上一个媒体文件

    // 设置媒体源
    void setMedia(const QString &path);  // 设置当前播放的媒体文件路径

    // 获取播放状态
    QMediaPlayer::PlaybackState getState() const;  // 获取当前播放状态

    // 获取当前播放时间（毫秒）
    int getCurrentPosition() const;  // 获取当前播放位置

    // 获取总时长（毫秒）
    int getDuration() const;  // 获取当前媒体文件的总时长

    // 设置播放列表
    void setPlaylist(const QStringList &playlist);  // 设置播放列表

    // 获取播放列表
    QStringList getPlaylist() const;  // 获取当前播放列表

    // 设置当前播放索引
    void setCurrentIndex(int index);  // 设置当前播放的媒体文件索引

    // 获取当前播放索引
    int getCurrentIndex() const;  // 获取当前播放的媒体文件索引

    // 设置音量
    void setVolume(int volume);  // 设置播放音量

    // 获取音量
    int getVolume() const;  // 获取当前音量

    // 设置播放速度
    void setPlaybackRate(qreal rate);  // 设置播放速度

    // 获取播放速度
    qreal getPlaybackRate() const;  // 获取当前播放速度

    void setPosition(int position);  // 设置当前播放位置

    QString findAudioFile(const QString &folderPath, const QString &songName);

signals:

    // 信号：播放状态改变
    void stateChanged(QMediaPlayer::PlaybackState state);  // 播放状态发生变化时发出信号

    // 信号：当前播放时间改变
    void positionChanged(int position);  // 当前播放位置发生变化时发出信号

    // 信号：总时长改变
    void durationChanged(int duration);  // 媒体文件总时长发生变化时发出信号

    // 信号：当前歌曲改变
    void currentSongChanged(const QString &songName);  // 当前播放的歌曲发生变化时发出信号

    // 信号：播放列表改变
    void playlistChanged();  // 播放列表发生变化时发出信号

public slots:


private slots:
    void onStateChanged(QMediaPlayer::PlaybackState state);  // 处理播放状态变化
    void onPositionChanged(qint64 position);  // 处理播放位置变化
    void onDurationChanged(qint64 duration);  // 处理媒体文件总时长变化

private:
    // 数据库对象作为成员变量，避免每次都重新连接
    Database database;

    QMediaPlayer *mediaPlayer;  // 媒体播放器对象
    QAudioOutput *audioOutput;  // 音频输出对象
    QStringList mediaPlaylist;  // 播放列表
    int currentIndex;  // 当前播放索引
    int pausedIndex;   // 暂停时的歌曲索引
    int lastPlayedSong; // 记录切换播放前的歌曲索引
    int pausePosition;  // 记录暂停位置

    // 播放状态
    QMediaPlayer::PlaybackState currentState;  // 当前播放状态

    // 连接信号
    void connectPlayerSignals();  // 连接媒体播放器的信号

    // 播放下一个媒体文件
    void playNextMedia();  // 播放下一个媒体文件

    // 播放上一个媒体文件
    void playPreviousMedia();  // 播放上一个媒体文件
};

#endif // PLAYER_H
