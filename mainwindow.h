#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QNetworkReply>
#include <QMainWindow>
#include <QListWidgetItem>
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

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *networkManager;

};

#endif // MAINWINDOW_H
