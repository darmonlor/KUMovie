#include "addmovie.h"
#include "ui_addmovie.h"

AddMovie::AddMovie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMovie)
{
    ui->setupUi(this);
}

AddMovie::~AddMovie()
{
    delete ui;
}
