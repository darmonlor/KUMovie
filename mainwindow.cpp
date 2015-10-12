#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(on_get_result(QNetworkReply*)));
    connect(&manager2, SIGNAL(finished(QNetworkReply*)), this, SLOT(on_get_result(QNetworkReply*)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_searchButton_clicked()
{

    QUrl url(QString("%1%2").arg("http://csfdapi.cz/movie?search=").arg(ui->searchEdit->text()));
    qWarning()<<url;
    request.setUrl(url);
    qWarning()<<url.path();
    networkManager.get(request);  // GET
    //connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(on_get_result(QNetworkReply*)));

}

void MainWindow::on_get_result(QNetworkReply * reply)
{
    ui->searchListWidget->clear();
    if (reply->error() != QNetworkReply::NoError)
    {
        ui->searchText->setText("Chyba hledání");
    }
    //ui->textEdit->setText((QString) reply->readAll());
    //ui->textEdit->setText("Done");
    QJsonDocument movieDocument=QJsonDocument::fromJson(reply->readAll());
    if (movieDocument.isArray())
    {
        qWarning() <<"test";
        QJsonArray movieList=movieDocument.array();
        qWarning() << movieList.isEmpty();
        qWarning() << movieList.size();
        foreach (const QJsonValue & value, movieList) {
            QJsonObject obj = value.toObject();
            QString name;
            name = QString("%1 (%2)").arg(obj.value("names").toObject().value("cs").toString()).arg(obj.value("year").toInt());
            QListWidgetItem * item = new QListWidgetItem(name);
            item->setData(Qt::UserRole,obj.value("id").toInt());
            ui->searchListWidget->addItem(item);
            qWarning() << obj.value("id").toInt();


        }
    } else {
        QJsonObject obj = movieDocument.object();
        qWarning()<<obj;
        ui->searchText->setText(obj.value("plot").toString());
    }
    reply->deleteLater();
}

void MainWindow::on_searchListWidget_currentRowChanged(int currentRow)
{
    QUrl url(QString("%1%2").arg("http://csfdapi.cz/movie/").arg(ui->searchListWidget->currentItem()->data(Qt::UserRole).toString()));
    //qWarning()<<ui->searchListWidget->indexAt(currentRow)->data(Qt::UserRole);
    qWarning()<<url;
    request.setUrl(url);
    qWarning()<<url.isValid();
//    qWarning()<<url.path();
    manager2.get(request);  // GET
}
