#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <categories.h>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool quiz = false;
    Categories* gui;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void quest(bool);
private slots:
    void on_pView_clicked();

    void on_pTest_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
