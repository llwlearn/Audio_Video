#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QWidget>
#include <QList>
#include <QFileInfo>
#include <QMediaPlayer>
#include <QMediaMetaData>

#include "src/tool/Database.h"

namespace Ui {
class Download;
}

class Download : public QWidget
{
    Q_OBJECT

public:
    explicit Download(QWidget *parent = nullptr);
    ~Download();

    // 查询本地音乐文件
    void loadMusicFiles(const QString &directoryPath);

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    void onMetaDataReady(const QMediaMetaData &meta);
    void onRefreshClicked();

private:
    Ui::Download *ui;

    void populateList(const QList<QMediaMetaData> &metaDataList);
    QList<QMediaMetaData> musicMetaDataList;
    QMediaPlayer *mediaPlayer;

    void saveMetaDataToFile(const QList<QMediaMetaData>& metaDataList, const QString& filePath);
    QList<QMediaMetaData> loadMetaDataFromFile(const QString& filePath);

    void onIdButtonClicked(const QMediaMetaData &meta);

    // 数据库对象作为成员变量，避免每次都重新连接
    Database *db;
};

#endif // DOWNLOAD_H
