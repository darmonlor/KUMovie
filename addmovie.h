#ifndef ADDMOVIE_H
#define ADDMOVIE_H
#include "databasecontrol.h"
#include <QDialog>

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

private:
    Ui::AddMovie *ui;
    DatabaseControl *database;

};

#endif // ADDMOVIE_H
