#include "Player.h"
#include <QDebug>

#include <QDir>
#include <QFileInfo>

// #include <QFileInfo>

Player::Player(QObject *parent) : QObject(parent),
    mediaPlayer(new QMediaPlayer(this)),
    audioOutput(new QAudioOutput(this)),
    currentIndex(0),
    currentState(QMediaPlayer::StoppedState)
{
    mediaPlayer->setAudioOutput(audioOutput);  // 将音频输出与媒体播放器关联
    connectPlayerSignals();  // 连接媒体播放器的信号

    // 创建一个包含单个路径的 QStringList
    QStringList folderList;
    folderList << "E://音乐";

    setPlaylist(folderList);  // 调用 setPlaylist 方法

    // 创建一个数据库对象，避免每次查询时都连接
    QSqlDatabase db = Database::getGlobalConnection();

}

Player::~Player()
{
    delete mediaPlayer;  // 删除媒体播放器对象
    delete audioOutput;  // 删除音频输出对象
}

void Player::uploadToRecentlyPlayed()
{

    QString filePath = mediaPlaylist[currentIndex];
    QFileInfo fileInfo(filePath);
    QString fileName = fileInfo.fileName();  // 文件名，如 "徐良,汪苏泷 - 后会无期.mp3"

    // 按 " - " 分隔歌曲名和歌手名
    QStringList parts = fileName.split(" - ");  // 使用正确的分隔符
    QString artist;
    QString songName;
    if (parts.size() >= 2) {
        QString singers = parts[0];  // 歌手名，例如 "徐良,汪苏泷"
        QString songWithExt = parts[1];  // 歌曲名带扩展名，例如 "后会无期.mp3"

        // 分离出第一个歌手
        QStringList singerList = singers.split(",");
        if (singerList.size() > 0) {
            artist = singerList.first().trimmed();  // 提取第一个歌手并去除空格
            songName = songWithExt.split(".").first();  // 去掉文件扩展名

            // qDebug() << "歌手:" << artist << ", 歌曲:" << songName;
        } else {
            qDebug() << "歌手名格式不正确";
        }
    } else {
        qDebug() << "文件名格式不正确，无法提取歌手和歌曲名";
    }

    // 查询数据库表 music
    QString condition = QString("artist LIKE '%1%' AND song_name LIKE '%2%'")
                            .arg(artist)
                            .arg(songName);
    // 查询所有字段
    QSqlQuery query = database.select("music", {}, condition);

    if (query.isActive()) {
        // 将查询到的数据插入到 recentlyPlayed 表
        int insertedCount = 0;
        while (query.next()) {
            // 提取字段值
            QString songNameValue = query.value("song_name").toString();
            QString artistValue = query.value("artist").toString();
            QString albumValue = query.value("album").toString();
            int isVipValue = query.value("is_vip").toInt();
            QString durationValue = query.value("duration").toString();

            // 插入到 recentlyPlayed 表
            QStringList insertFields = {"song_name", "artist", "album", "is_vip", "duration" };
            QVariantList insertValues = {songNameValue, artistValue, albumValue, isVipValue, durationValue };

            if (database.insert("recentlyPlayed", insertFields, insertValues)) {
                insertedCount++;
            } else {
                qDebug() << "插入失败: " << songNameValue << " - " << artistValue;
            }
        }

        qDebug() << "成功插入" << insertedCount << "条记录到 recentlyPlayed 表。";
    } else {
        qDebug() << "查询失败: " << query.lastError().text();
    }

}

void Player::addSongToPlaylist(const Song &song)
{
    QString songName = song.songName;
    QString artist = song.artist;

    // 检查播放列表中是否已存在相同歌曲（根据songName和artist判断）
    for (const QString &filePath : mediaPlaylist) {
        QFileInfo fileInfo(filePath);
        QString fileName = fileInfo.baseName();  // 获取文件名（不包括扩展名）

        // 假设文件名格式为 "songName - artist"，根据实际情况调整
        QStringList parts = fileName.split(" - ");
        if (parts.size() == 2 && parts[0] == songName && parts[1] == artist) {
            qDebug() << "歌曲已存在于播放列表：" << songName << " - " << artist;
            return;  // 如果已存在相同歌曲，则不再添加
        }
    }

    QString filePath = findAudioFile("E:/音乐", songName);
    if (!filePath.isEmpty()) {
        mediaPlaylist.append(filePath);
        qDebug() << "添加歌曲到播放列表：" << filePath;
        // qDebug() << "当前播放列表大小：" << mediaPlaylist.size();
        // qDebug() << "当前播放列表：";
        // for (const QString &path : mediaPlaylist) {
        //     qDebug() << path;
        // }
    } else {
        qDebug() << "未找到歌曲：" << songName;
    }

    emit playlistChanged();  // 发出播放列表改变信号

}

void Player::loadMusicFromDatabase()
{
    mediaPlaylist.clear();  // 清空当前播放列表
    QStringList fields;
    QString condition;

    QSqlQuery query = database.select("playlist", fields, condition);

    while (query.next()) {
        int songId = query.value("id").toInt();
        QString songName = query.value("song_name").toString();
        QString artist = query.value("artist").toString();
        bool isVip = query.value("is_vip").toBool();
        QString duration = query.value("duration").toString();

        Song song(songId, songName, artist, isVip, duration);

        QString filePath = findAudioFile("E:/音乐",songName);
        mediaPlaylist.append(filePath);
    }
    // db->close();

    // qDebug() << "当前播放列表：";
    // for (const QString &path : mediaPlaylist) {
    //     qDebug() << path;
    // }

    emit playlistChanged();  // 发出播放列表改变信号
}

QString Player::findAudioFile(const QString &folderPath, const QString &songName)
{
    QDir dir(folderPath);
    QStringList filters;
    filters << "*.mp3" << "*.wav" << "*.flac";  // 可以根据需要添加其他音乐文件格式
    dir.setNameFilters(filters);

    QFileInfoList fileList = dir.entryInfoList(QDir::Files);
    for (const QFileInfo &fileInfo : fileList) {
        QString fileName = fileInfo.baseName();  // 获取文件名（不包括扩展名）

        // 使用QString::contains进行模糊匹配
        if (fileName.toLower().contains(songName.toLower())) {
            // qDebug() << "找到音乐文件：" << songName << " - 路径：" << fileInfo.absoluteFilePath();
            return fileInfo.absoluteFilePath();
        }
    }

    qDebug() << "未找到音乐文件：" << songName;
    return QString();  // 如果未找到文件，返回空字符串
}

void Player::setPosition(int position)
{
    mediaPlayer->setPosition(position);  // 设置媒体播放器的播放位置
}

void Player::play()
{
    if (mediaPlayer->playbackState() == QMediaPlayer::PausedState)
    {
        mediaPlayer->setPosition(pausePosition);  // 恢复到暂停位置
        mediaPlayer->play();
        pausePosition = 0;  // 重置暂停位置
        return;
    }

    if (mediaPlaylist.isEmpty())
    {
        qWarning() << "播放列表为空";
        return;
    }

    if (mediaPlaylist[currentIndex] != mediaPlaylist[lastPlayedSong])
    {
        lastPlayedSong = currentIndex;
        emit currentSongChanged(mediaPlaylist[currentIndex]);
    }

    mediaPlayer->setSource(QUrl::fromLocalFile(mediaPlaylist[currentIndex]));
    mediaPlayer->play();
    qDebug() << "播放歌曲：" << mediaPlaylist[currentIndex];

    this->uploadToRecentlyPlayed(); // 上传当前播放的歌曲信息

}

void Player::pause()
{
    pausePosition = mediaPlayer->position();  // 记录当前播放位置
    pausedIndex = currentIndex;  // 保存当前歌曲的索引
    mediaPlayer->pause();  // 暂停播放
}

void Player::stop()
{
    mediaPlayer->stop();  // 停止播放
}

void Player::next()
{
    loadMusicFromDatabase(); //刷新播放列表
    // currentIndex = currentIndex + 1;

    // 如果当前播放歌曲为播放列表最后一首，则切换到播放列表第一首歌曲
    qDebug() << mediaPlaylist.size();
    if (currentIndex == mediaPlaylist.size() - 1) {
        currentIndex = 0;
    } else {
        currentIndex = currentIndex + 1;
    }

    qDebug() << currentIndex;
    qDebug() << "下一首歌曲的路径：" << mediaPlaylist[currentIndex];
    // qDebug() << "当前播放列表：";
    // for (const QString &path : mediaPlaylist) {
    //     qDebug() << path;
    // }
    mediaPlayer->setSource(QUrl::fromLocalFile(mediaPlaylist[currentIndex]));
    this->play();
    pausedIndex = currentIndex; // 保存当前歌曲的索引
        // qDebug() << "切换到下一首歌曲，当前索引：" << currentIndex;
}

void Player::previous()
{
    loadMusicFromDatabase(); //刷新播放列表
    // 如果当前播放歌曲为播放列表第一首，则切换到播放列表末尾歌曲
    qDebug() << mediaPlaylist.size();
    qDebug() << currentIndex;
    if (currentIndex == 0) {
        currentIndex = mediaPlaylist.size() - 1;
        qDebug() << mediaPlaylist.size();
    } else {
        currentIndex = currentIndex - 1;
    }

    qDebug() << currentIndex;
    qDebug() << "上一首歌曲的路径：" << mediaPlaylist[currentIndex];
    // qDebug() << "当前播放列表大小：" << mediaPlaylist.size();
    // qDebug() << "当前播放列表：";
    // for (const QString &path : mediaPlaylist) {
    //     qDebug() << path;
    // }
    mediaPlayer->setSource(QUrl::fromLocalFile(mediaPlaylist[currentIndex]));
    this->play();
    pausedIndex = currentIndex; // 保存当前歌曲的索引
        // qDebug() << "切换到上一首歌曲，当前索引：" << currentIndex;
}

void Player::setMedia(const QString &path)
{
    mediaPlayer->setSource(QUrl::fromLocalFile(path));  // 设置当前播放的媒体文件路径
}

QMediaPlayer::PlaybackState Player::getState() const
{
    return currentState;  // 返回当前播放状态
}

int Player::getCurrentPosition() const
{
    return mediaPlayer->position();  // 返回当前播放位置
}

int Player::getDuration() const
{
    return mediaPlayer->duration();  // 返回当前媒体文件的总时长
}

void Player::setPlaylist(const QStringList &folderList)
{
    mediaPlaylist.clear();  // 清空当前播放列表

    for (const QString &folderPath : folderList) {
        QDir dir(folderPath);
        QStringList filters;
        filters << "*.mp3" << "*.wav" << "*.flac";  // 可以根据需要添加其他音乐文件格式
        dir.setNameFilters(filters);

        QFileInfoList fileList = dir.entryInfoList(QDir::Files);
        for (const QFileInfo &fileInfo : fileList) {
            mediaPlaylist.append(fileInfo.absoluteFilePath());
        }
    }

    currentIndex = 0;  // 重置当前索引
    emit playlistChanged();  // 发出播放列表改变信号
}

QStringList Player::getPlaylist() const
{
    return mediaPlaylist;  // 返回当前播放列表
}

void Player::setCurrentIndex(int index)
{
    if (index >= 0 && index < mediaPlaylist.size())
    {
        currentIndex = index;  // 设置当前播放索引
        play();  // 开始播放
    }
}

int Player::getCurrentIndex() const
{
    return currentIndex;  // 返回当前播放索引
}

void Player::setVolume(int volume)
{
    audioOutput->setVolume(volume / 100.0);  // 设置音量，将音量范围从0-100转换为0-1
}

int Player::getVolume() const
{
    return static_cast<int>(audioOutput->volume() * 100);  // 获取当前音量，将音量范围从0-1转换为0-100
}

void Player::setPlaybackRate(qreal rate)
{
    mediaPlayer->setPlaybackRate(rate);  // 设置播放速度
}

qreal Player::getPlaybackRate() const
{
    return mediaPlayer->playbackRate();  // 返回当前播放速度
}

void Player::connectPlayerSignals()
{
    connect(mediaPlayer, &QMediaPlayer::playbackStateChanged, this, &Player::onStateChanged);  // 连接播放状态变化信号
    connect(mediaPlayer, &QMediaPlayer::positionChanged, this, &Player::onPositionChanged);  // 连接播放位置变化信号
    connect(mediaPlayer, &QMediaPlayer::durationChanged, this, &Player::onDurationChanged);  // 连接媒体文件总时长变化信号
}

void Player::onStateChanged(QMediaPlayer::PlaybackState state)
{
    currentState = state;  // 更新当前播放状态
    emit stateChanged(state);  // 发出播放状态改变信号

    if (state == QMediaPlayer::StoppedState && !mediaPlaylist.isEmpty())
    {
        playNextMedia();  // 如果播放结束且播放列表不为空，自动播放下一个媒体文件
    }
}

void Player::onPositionChanged(qint64 position)
{
    emit positionChanged(position);  // 发出当前播放位置改变信号
}

void Player::onDurationChanged(qint64 duration)
{
    emit durationChanged(duration);  // 发出媒体文件总时长改变信号
}

void Player::playNextMedia()
{
    // currentIndex = (currentIndex + 1) % mediaPlaylist.size();  // 更新当前播放索引
    // mediaPlayer->setSource(QUrl::fromLocalFile(mediaPlaylist[currentIndex]));  // 设置下一个媒体文件路径
    // mediaPlayer->play();  // 开始播放
    // emit currentSongChanged(mediaPlaylist[currentIndex]);  // 发出当前歌曲改变信号
}

void Player::playPreviousMedia()
{
    // currentIndex = (currentIndex - 1 + mediaPlaylist.size()) % mediaPlaylist.size();  // 更新当前播放索引
    // mediaPlayer->setSource(QUrl::fromLocalFile(mediaPlaylist[currentIndex]));  // 设置上一个媒体文件路径
    // mediaPlayer->play();  // 开始播放
    // emit currentSongChanged(mediaPlaylist[currentIndex]);  // 发出当前歌曲改变信号
}
