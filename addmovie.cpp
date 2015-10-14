#include "addmovie.h"
#include "ui_addmovie.h"
#include <QSql>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>
#include <QDebug>
#include <QSqlError>
#include <QPushButton>
#include <QTime>
AddMovie::AddMovie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMovie)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.setForwardOnly(true);
    query.exec("SELECT * FROM movie_list ORDER BY ID DESC");
    while(query.next())
        {
            QSqlRecord record;
            record = query.record();
            qDebug() << record.value(1).toString();
            QListWidgetItem * item = new QListWidgetItem(record.field("name").value().toString());
            item->setData(Qt::UserRole,record.field("ID").value().toInt());
            ui->movieListWidget->addItem(item);
        }
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

}

AddMovie::~AddMovie()
{
    delete ui;
}

void AddMovie::on_buttonBox_accepted()
{
    QSqlQuery query;
    QString id=QString::number(ui->movieListWidget->currentItem()->data(Qt::UserRole).toInt());
    QString price=QString::number(ui->priceSpinBox->value());
    QString date=QString::number(ui->movieDateTimeEdit->dateTime().toTime_t());
    QString querystring = QString("INSERT INTO program (movie_id, datetime, price) VALUES ('%1','%2','%3');").arg(id, date, price);
    qDebug()<<id<<price<<date;
    qDebug()<<querystring;
    query.exec(querystring);
    qWarning()<< query.lastError();

}



void AddMovie::on_movieListWidget_itemSelectionChanged()
{
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(ui->movieListWidget->selectedItems().count());
}

void AddMovie::on_afternoonToolButton_clicked()
{
    ui->movieDateTimeEdit->setTime(QTime(17,0,0));
}

void AddMovie::on_eveningToolButton_clicked()
{
    ui->movieDateTimeEdit->setTime(QTime(20,0,0));

}
