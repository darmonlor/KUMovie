#ifndef DATABASECONTROL_H
#define DATABASECONTROL_H
#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDriver>



class DatabaseControl : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseControl(QObject *parent = 0);
    void addMovie(QString name, QString year, QString genres,QString plot);

protected:

signals:

public slots:
};

#endif // DATABASECONTROL_H
