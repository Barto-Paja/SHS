#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gui = new Kategorie(this);
    connect(this,SIGNAL(quest(bool)),gui,SLOT(qOdbior(bool)));
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pView_clicked()
{
    Kategorie okno;
    okno.setModal(true);
    okno.exec();
}

void MainWindow::on_pTest_clicked()
{
    quiz = true;
    emit quest(quiz);
    gui->setModal(true);
    gui->exec();

}
