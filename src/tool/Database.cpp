#include "Database.h"

#include <QSqlQuery>
#include <QSqlRecord>

int Database::connectionCounter = 0;

Database::Database()
{
}

Database::~Database()
{
    this->close();
}

void Database::close()
{
    if (isConnected()) {
        db.close();
        QSqlDatabase::removeDatabase(db.connectionName());
        connected = false;
    }
}

bool Database::isConnected() const
{
    return connected && db.isOpen();
}

QSqlDatabase Database::getGlobalConnection() {
    static QSqlDatabase Globaldb = QSqlDatabase::addDatabase("QODBC");

    QString connectionString = QString(
                                   "Driver={MySQL ODBC 9.1 Unicode Driver};"  // 注意，这里是指定 MySQL ODBC 驱动
                                   "Server=%1;"
                                   "Database=%2;"
                                   "Uid=%3;"
                                   "Pwd=%4;"
                                   ).arg("localhost").arg("Audio_Video").arg("root").arg("123456");
    Globaldb.setDatabaseName(connectionString);// 设置数据库连接字符串
    if (!Globaldb.open()) {
        qDebug() << "数据库连接失败: " << Globaldb.lastError().text();
    }
    return Globaldb;
}

bool Database::connect(const QString &host, const QString &dbName, const QString &user, const QString &password)
{
    // if (isConnected()) {
    //     return true;
    // }
    // QString connectionName = QString("mysql_connection_%1").arg(++connectionCounter);
    db = QSqlDatabase::addDatabase("QODBC");
    // 设置ODBC数据源名称（DSN），或者直接设置连接字符串
    // db.setDatabaseName("Mysql");  // 使用已有的ODBC数据源
    // 设置其他信息，如用户名和密码（如果未在连接字符串中设置）
    // db.setUserName(user);  // 设置用户名
    // db.setPassword(password);  // 设置密码
    // 如果你没有设置数据源，也可以直接提供连接字符串
    // 使用 MySQL 的 ODBC 连接字符串，注意 MySQL 驱动名要正确
    QString connectionString = QString(
                                   "Driver={MySQL ODBC 9.1 Unicode Driver};"  // 注意，这里是指定 MySQL ODBC 驱动
                                   "Server=%1;"
                                   "Database=%2;"
                                   "Uid=%3;"
                                   "Pwd=%4;"
                                   ).arg(host).arg(dbName).arg(user).arg(password);
    db.setDatabaseName(connectionString);// 设置数据库连接字符串
    // qDebug() << QSqlDatabase::drivers();

    if (!db.open()) {
        qDebug() << "数据库连接失败: " << db.lastError().text();
        return false;
    }
    connected = true;
    return true;
}

bool Database::insert(const QString &table, const QStringList &fields, const QVariantList &values)
{
    if (fields.size() != values.size()) {
        qDebug() << "字段数量和值数量不匹配!";
        return false;
    }

    QString queryStr = "INSERT INTO " + table + " (" + fields.join(", ") + ") VALUES (";
    for (int i = 0; i < values.size(); ++i) {
        queryStr += "?"; // 使用 ? 作为占位符
        if (i < values.size() - 1) {
            queryStr += ", ";
        }
    }
    queryStr += ")";

    QSqlQuery query;
    query.prepare(queryStr);

    for (int i = 0; i < values.size(); ++i) {
        query.addBindValue(values.at(i));
    }

    if (!query.exec()) {
        qDebug() << "插入失败: " << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQuery Database::select(const QString &table, const QStringList &fields, const QString &condition)
{
    // 如果fields为空，使用 "*" 来选择所有字段
    QString queryStr = "SELECT " + (fields.isEmpty() ? "*" : fields.join(", ")) + " FROM " + table;

    // 如果有条件，添加WHERE子句
    if (!condition.isEmpty()) {
        queryStr += " WHERE " + condition;
    }

    // qDebug() << "Executing query: " << queryStr;  // 可以加一个调试信息，查看最终的查询语句

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
        queryStr += fields.at(i) + " = ?"; // 使用 ? 作为占位符
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
        query.addBindValue(values.at(i));
    }

     // qDebug() << "Executing query: " << queryStr;  // 可以加一个调试信息，查看最终的查询语句

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
