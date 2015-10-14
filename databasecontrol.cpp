#include "databasecontrol.h"
#include <QDebug>
#include <QFileInfo>
#include <QSqlError>
#include <QSql>
#include <QStandardPaths>
#define DBFILEPATH ":/database/movies.db"

DatabaseControl::DatabaseControl(QObject *parent) : QObject(parent)
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
    query.exec("CREATE TABLE program (ID INTEGER PRIMARY KEY AUTOINCREMENT, movie_id INTEGER, datetime INTEGER, price INTEGER, FOREIGN KEY(movie_id) REFERENCES movie_list(ID));");
    qWarning()<<query.lastError();

}
    qWarning()<<"Database opened";

}

void DatabaseControl::addMovie(QString name, QString year, QString genres, QString plot)
{
    QSqlQuery query;
    QString querystring = QString("INSERT INTO movie_list (name, year, genres, plot) VALUES ('%1','%2','%3','%4');").arg(name, year, genres, plot);
    query.exec(querystring);
    qWarning()<<query.lastError();
    qWarning()<<querystring;
}

