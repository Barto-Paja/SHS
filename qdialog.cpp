#include "qdialog.h"
#include "ui_qdialog.h"

qDialog::qDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qDialog)
{
    ui->setupUi(this);
}

qDialog::~qDialog()
{
    delete ui;
}
