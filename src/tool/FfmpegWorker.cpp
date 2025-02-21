#include "FfmpegWorker.h"

#include <QProcess>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QTime>

FfmpegWorker::FfmpegWorker(const QFileInfoList &fileList, QObject *parent)
    : QObject(parent), fileList(fileList)
{
}

FfmpegWorker::FfmpegWorker() {
    // 无参构造函数实现
}

Song FfmpegWorker::findSongBySongPath(const QString &songPath) {
    // 使用 ffprobe 获取音频文件的元数据
    QProcess process;
    QStringList arguments;
    arguments << "-v" << "quiet" << "-print_format" << "json" << "-show_format" << "-show_streams" << songPath;

    process.start("ffprobe", arguments);
    if (!process.waitForStarted()) {
        qDebug() << "Failed to start ffprobe process.";
        return Song();
    }

    if (!process.waitForFinished()) {
        qDebug() << "ffprobe process did not finish successfully.";
        return Song();
    }

    QString output = process.readAllStandardOutput();
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(output.toUtf8(), &parseError);
    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "JSON parse error:" << parseError.errorString();
        return Song();
    }

    if (doc.isObject()) {
        QJsonObject rootObj = doc.object();
        if (rootObj.contains("format") && rootObj["format"].isObject()) {
            QJsonObject formatObj = rootObj["format"].toObject();
            QString duration = formatObj["duration"].toString();
            int durationMilliseconds = static_cast<int>(duration.toDouble() * 1000);

            // 将毫秒转换为分钟和秒
            int minutes = durationMilliseconds / 60000;
            int seconds = (durationMilliseconds % 60000) / 1000;
            QString durationStr = QString("%1:%2").arg(minutes, 2, 10, QLatin1Char('0')).arg(seconds, 2, 10, QLatin1Char('0'));

            // 提取艺术家和歌曲名
            QString artist, title;
            if (formatObj.contains("tags") && formatObj["tags"].isObject()) {
                QJsonObject tagsObj = formatObj["tags"].toObject();
                artist = tagsObj["artist"].toString();
                title = tagsObj["title"].toString();
            }

            // qDebug() << "Found song:" << title << artist << durationStr;
            return Song(0, title, artist, false, durationStr); // 假设 ID 和 isVip 为默认值
        }
    }

    qDebug() << "Song information not found in ffprobe output.";
    return Song(); // 如果没有找到匹配的歌曲信息，返回无效的 Song 对象
}

void FfmpegWorker::processFiles()
{
    for (const QFileInfo &fileInfo : fileList) {
        QString filePath = fileInfo.absoluteFilePath();

        // 使用 ffprobe 获取文件信息
        QProcess process;
        QStringList arguments;
        arguments << "-v" << "quiet" << "-print_format" << "json" << "-show_format" << "-show_streams" << filePath;
        process.start("ffprobe", arguments);
        process.waitForFinished();

        // 获取 ffprobe 的输出
        QString output = process.readAllStandardOutput();
        // qDebug() << "FFprobe output:" << output;

        // 解析 JSON 输出
        QJsonParseError parseError;
        QJsonDocument doc = QJsonDocument::fromJson(output.toUtf8(), &parseError);
        if (parseError.error != QJsonParseError::NoError) {
            qDebug() << "JSON parse error:" << parseError.errorString();
            continue;
        }

        if (doc.isObject()) {
            QJsonObject obj = doc.object();
            QJsonObject format = obj["format"].toObject();

            // 提取元数据
            QString songName = format["tags"].toObject()["title"].toString();
            QString artist = format["tags"].toObject()["artist"].toString();
            QString album = format["tags"].toObject()["album"].toString();
            QJsonObject formatObj = doc.object()["format"].toObject();
            double durationSeconds = formatObj["duration"].toString().toDouble();

            // 计算分钟和秒
            int minutes = static_cast<int>(durationSeconds / 60);
            int seconds = static_cast<int>(durationSeconds) % 60;

            // 格式化为 mm:ss
            QString durationStr = QString("%1:%2").arg(minutes, 2, 10, QLatin1Char('0')).arg(seconds, 2, 10, QLatin1Char('0'));


            // 创建 QMediaMetaData 对象并填充信息
            QMediaMetaData meta;
            meta.insert(QMediaMetaData::Title, songName);
            meta.insert(QMediaMetaData::Author, artist);
            meta.insert(QMediaMetaData::AlbumTitle, album);
            meta.insert(QMediaMetaData::Duration, static_cast<qint64>(durationSeconds * 1000)); // 使用 durationSeconds 转换为毫秒

            // 将元数据对象添加到列表中
            emit metaDataReady(meta);
        }
    }
    emit finished();
}
