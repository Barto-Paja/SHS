#ifndef KATEGORIE_H
#define KATEGORIE_H

#include <item.h>
#include <myqlabel.h>
#include <album.h>
#include <dialogt.h>

#include <QDialog>
#include <QVector>


namespace Ui {
class Kategorie;
}
class Album;
class DialogT;
class Kategorie : public QDialog
{
    Q_OBJECT

public:
    explicit Kategorie(QWidget *parent = 0);
    ~Kategorie();

    QString zestaw;
    myQLabel *tab[9];
    Album* form;
    bool info=false;
    DialogT* form2;

signals:
    void send(QString);
private slots:
    void Pressed(int);
    void qOdbior(bool);
private:
    Ui::Kategorie *ui;
};

#endif // KATEGORIE_H
