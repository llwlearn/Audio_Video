#include "Database.h"

Database::Database()
{

}

Database::~Database()
{
    if (db.isOpen()) {
        db.close();
    }
}

bool Database::connect(const QString &host, const QString &dbName, const QString &user, const QString &password)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(host);  // 设置主机名
    db.setDatabaseName(dbName);  // 设置数据库名
    db.setUserName(user);  // 设置用户名
    db.setPassword(password);  // 设置密码

    if (!db.open()) {
        qDebug() << "数据库连接失败: " << db.lastError().text();
        return false;
    }
    return true;
}

bool Database::isConnected() const
{
    return db.isOpen();
}

bool Database::insert(const QString &table, const QStringList &fields, const QVariantList &values)
{
    if (fields.size() != values.size()) {
        qDebug() << "字段数量和值数量不匹配!";
        return false;
    }

    QString queryStr = "INSERT INTO " + table + " (" + fields.join(", ") + ") VALUES (";
    for (int i = 0; i < values.size(); ++i) {
        queryStr += ":value" + QString::number(i);
        if (i < values.size() - 1) {
            queryStr += ", ";
        }
    }
    queryStr += ")";

    QSqlQuery query;
    query.prepare(queryStr);

    for (int i = 0; i < values.size(); ++i) {
        query.bindValue(":value" + QString::number(i), values.at(i));
    }

    if (!query.exec()) {
        qDebug() << "插入失败: " << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQuery Database::select(const QString &table, const QStringList &fields, const QString &condition)
{
    QString queryStr = "SELECT " + fields.join(", ") + " FROM " + table;
    if (!condition.isEmpty()) {
        queryStr += " WHERE " + condition;
    }

    QSqlQuery query;
    if (!query.exec(queryStr)) {
        qDebug() << "查询失败: " << query.lastError().text();
    }

    return query;
}

bool Database::update(const QString &table, const QStringList &fields, const QVariantList &values, const QString &condition)
{
    if (fields.size() != values.size()) {
        qDebug() << "字段数量和值数量不匹配!";
        return false;
    }

    QString queryStr = "UPDATE " + table + " SET ";
    for (int i = 0; i < fields.size(); ++i) {
        queryStr += fields.at(i) + " = :value" + QString::number(i);
        if (i < fields.size() - 1) {
            queryStr += ", ";
        }
    }

    if (!condition.isEmpty()) {
        queryStr += " WHERE " + condition;
    }

    QSqlQuery query;
    query.prepare(queryStr);

    for (int i = 0; i < values.size(); ++i) {
        query.bindValue(":value" + QString::number(i), values.at(i));
    }

    if (!query.exec()) {
        qDebug() << "更新失败: " << query.lastError().text();
        return false;
    }
    return true;
}

bool Database::remove(const QString &table, const QString &condition)
{
    QString queryStr = "DELETE FROM " + table;
    if (!condition.isEmpty()) {
        queryStr += " WHERE " + condition;
    }

    QSqlQuery query;
    if (!query.exec(queryStr)) {
        qDebug() << "删除失败: " << query.lastError().text();
        return false;
    }
    return true;
}
