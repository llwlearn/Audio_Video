#include "JsonManager.h"
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QDebug>

bool JsonManager::saveUserInfoToFile(const QString &filePath, const QJsonObject &userInfo)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "无法打开文件进行写入：" << filePath;
        return false;
    }

    QJsonDocument doc(userInfo);
    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();
    return true;
}

QJsonObject JsonManager::loadUserInfoFromFile(const QString &filePath)
{
    QFile file(filePath);
    if (!file.exists() || !file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "无法打开文件进行读取：" << filePath;
        return QJsonObject();
    }

    // 使用 QTextStream 读取文件内容，并指定编码方式为 UTF-8
    QTextStream stream(&file);
    stream.setEncoding(QStringConverter::Utf8); // Qt 5 之后的正确方法
    QString jsonString = stream.readAll();
    file.close();

    QJsonParseError jsonError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8(), &jsonError);
    if (jsonError.error != QJsonParseError::NoError) {
        qDebug() << "JSON 解析错误：" << jsonError.errorString();
        return QJsonObject();
    }

    return doc.object();
}
