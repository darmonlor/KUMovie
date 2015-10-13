#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDate>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    database = new(databaseControl);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_searchButton_clicked()
{
    networkManager = new QNetworkAccessManager(this);
    QUrl url(QString("%1%2").arg("http://csfdapi.cz/movie?search=").arg(ui->searchEdit->text()));
    qWarning()<<url;
    qWarning()<<url.path();
    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(on_get_result(QNetworkReply*)));

    networkManager->get(QNetworkRequest(url));  // GET
    //connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(on_get_result(QNetworkReply*)));

}

void MainWindow::on_get_result(QNetworkReply * reply)
{
    if (reply->error() != QNetworkReply::NoError)
    {
        ui->searchPlotText->setText("Chyba hledání");
    }
    //ui->textEdit->setText((QString) reply->readAll());
    //ui->textEdit->setText("Done");
    QJsonDocument movieDocument=QJsonDocument::fromJson(reply->readAll());
    if (movieDocument.isArray())
    {
        ui->searchListWidget->clear();
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
        ui->searchPlotText->setText(obj.value("plot").toString());
        ui->searchYearSpinBox->setValue(obj.value("year").toInt());
        ui->searchNameEdit->setText(obj.value("names").toObject().value("cs").toString());
        QJsonArray genreList = obj.value("genres").toArray();
        QString genres;
        foreach (const QJsonValue & value, genreList) {
            qWarning()<<value.toString();
            genres+=value.toString();
            if (value.toString() != genreList.last().toString())
                genres+=", ";

        }
        ui->searchGenreEdit->setText(genres);
        qWarning()<<genres;
    }
    reply->deleteLater();

}




void MainWindow::on_searchListWidget_itemClicked(QListWidgetItem *item)
{
    qWarning() << "boohoo";
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(on_get_result(QNetworkReply*)));
    int linkId = item->data(Qt::UserRole).toInt();

    qWarning() << linkId;
    QUrl url(QString("%1/%2").arg("http://csfdapi.cz/movie").arg(linkId));
    //qWarning()<<ui->searchListWidget->indexAt(currentRow)->data(Qt::UserRole);
    qWarning()<<url;
    qWarning()<<url.isValid();
//    qWarning()<<url.path();
    networkManager->get(QNetworkRequest(url));  // GET
}

void MainWindow::on_SearchDbaddButton_clicked()
{
    database->addMovie(ui->searchNameEdit->text(),QString::number(ui->searchYearSpinBox->value()),ui->searchGenreEdit->text(),ui->searchPlotText->toPlainText());
}
