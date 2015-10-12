#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QNetworkReply>
#include <QMainWindow>

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
    void on_searchListWidget_currentRowChanged(int currentRow);

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager networkManager;
    QNetworkRequest request;
    QNetworkAccessManager manager2;

};

#endif // MAINWINDOW_H
