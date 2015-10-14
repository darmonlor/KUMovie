#ifndef ADDMOVIE_H
#define ADDMOVIE_H
#include "databasecontrol.h"
#include <QDialog>
#include <QListWidgetItem>
namespace Ui {
class AddMovie;
}

class AddMovie : public QDialog
{
    Q_OBJECT

public:
    explicit AddMovie(QWidget *parent = 0);
    ~AddMovie();

private slots:
    void on_buttonBox_accepted();



    void on_movieListWidget_itemSelectionChanged();

    void on_afternoonToolButton_clicked();

    void on_eveningToolButton_clicked();

private:
    Ui::AddMovie *ui;
    DatabaseControl *database;

};

#endif // ADDMOVIE_H
