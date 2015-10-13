#ifndef ADDMOVIE_H
#define ADDMOVIE_H

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

private:
    Ui::AddMovie *ui;
};

#endif // ADDMOVIE_H
