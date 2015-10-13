#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QNetworkReply>
#include <QMainWindow>
#include <QListWidgetItem>
#include "databasecontrol.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_searchButton_clicked();
    void on_get_result(QNetworkReply*);



    void on_searchListWidget_itemClicked(QListWidgetItem *item);

    void on_SearchDbaddButton_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *networkManager;
    databaseControl *database;
};

#endif // MAINWINDOW_H
