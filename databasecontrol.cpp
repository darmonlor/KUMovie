#include "databasecontrol.h"
#include <QDebug>
#include <QFileInfo>
#include <QSqlError>
#include <QSql>
#include <QStandardPaths>
#define DBFILEPATH ":/database/movies.db"

databaseControl::databaseControl(QObject *parent) : QObject(parent)
{

QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
qDebug() << QStandardPaths::AppDataLocation;
QString path=QStandardPaths::writableLocation(QStandardPaths::ConfigLocation)+"/movies.db";
db.setDatabaseName(path);
qWarning()<<path;

QFileInfo file(DBFILEPATH);
qWarning()<<file.exists();

qWarning()<<db.open();
qWarning()<<db.lastError();
if (db.open())
{
    QSqlQuery query(db);
    query.exec("CREATE TABLE movie_list (ID INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, year TEXT ,genres TEXT, plot TEXT);");
    query.exec("CREATE TABLE program (ID INTEGER PRIMARY KEY AUTOINCREMENT, air, year TEXT ,genres TEXT, plot TEXT);");

}
    qWarning()<<"Database opened";
db.close();
}

void databaseControl::addMovie(QString name, QString year, QString genres, QString plot)
{
    QSqlDatabase db = QSqlDatabase::database();
    qDebug()<< "opened?"<<db.open();
    QSqlQuery query(db);
    qWarning()<<db.lastError();
    QString querystring = QString("INSERT INTO movie_list (name, year, genres, plot) VALUES ('%1','%2','%3','%4');").arg(name, year, genres, plot);
    query.exec(querystring);
    qWarning()<<query.lastError();
    qWarning()<<querystring;
}

