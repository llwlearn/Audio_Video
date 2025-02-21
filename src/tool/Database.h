#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QString>
#include <QVariant>
#include <QDebug>

class Database
{
public:
    Database();
    ~Database();

    static QSqlDatabase getGlobalConnection();

    // 连接到数据库
    bool connect(const QString &host, const QString &dbName, const QString &user, const QString &password);

    // 增
    bool insert(const QString &table, const QStringList &fields, const QVariantList &values);

    // 查
    QSqlQuery select(const QString &table, const QStringList &fields = {"*"}, const QString &condition = "");

    // 改
    bool update(const QString &table, const QStringList &fields, const QVariantList &values, const QString &condition);

    // 删
    bool remove(const QString &table, const QString &condition);

    // 检查数据库连接是否成功
    bool isConnected() const;

    void close();  // 声明 close 方法

private:
    QSqlDatabase db;
    bool connected = false;
    static int connectionCounter;  // 静态成员，用于生成唯一的连接名称
};

#endif // DATABASE_H
