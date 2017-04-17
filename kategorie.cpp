#include "kategorie.h"
#include "ui_kategorie.h"

#include <fstream>
#include <string>

Kategorie::Kategorie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Kategorie)
{
    ui->setupUi(this);
    form = new Album(this);
    form2 = new DialogT(this);


// Importowanie kategorii , łączenie sygnałów i tworzenie interfejsu
    zestaw = ":/txt/txt/zestawy.txt";
    QFile zp(zestaw); // <-- zmienna pomocnicza, do wyliczenia wierszy
    Item::import(tablica,zestaw);
    Item::ilewierszy(zp,n=0);

    ui->gridLayout->setSpacing(10);
    n=n/3;
    for(int i=0;i<n;i++)
    {
        int q;
        QFile qs(tablica[i].SeeWsk());
        tab << new myQLabel(this);
        tab.at(i)->SetRef(i);
        tab.at(i)->setPixmap(tablica[i].SeeImg().scaled(300,164,Qt::KeepAspectRatio));
        tab.at(i)->setFrameStyle(3);
    }

    for(int i=0;i<n;i++)
    {
        ui->gridLayout->addWidget(tab.at(i),(i/3),(i%3));
        connect(tab.at(i),SIGNAL(Pressed(int)),this,SLOT(Pressed(int)));
    }

        connect(this,SIGNAL(send(QString)),form,SLOT(odbiornik(QString)));
        connect(this,SIGNAL(send(QString)),form2,SLOT(odbiornik(QString)));
}

Kategorie::~Kategorie()
{
    info=false;
    delete ui;
}
void Kategorie::Pressed(int t)
{
    QString ns=tablica[t].SeeWsk();
    emit send(ns);

    if(info==false)
    {
        form->setModal(true);
        form->exec();
    }
    else
    {
        form2->setModal(true);
        form2->exec();
    }
}
void Kategorie::qOdbior(bool r)
{
    info = r;
}
