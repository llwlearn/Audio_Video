#ifndef JSONMANAGER_H
#define JSONMANAGER_H

#include <QString>
#include <QJsonObject>
#include <QJsonDocument>

class JsonManager
{
public:
    static bool saveUserInfoToFile(const QString &filePath, const QJsonObject &userInfo);
    static QJsonObject loadUserInfoFromFile(const QString &filePath);
};

#endif // JSONMANAGER_H
