#include "kategorie.h"
#include "ui_kategorie.h"

Kategorie::Kategorie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Kategorie)
{
    ui->setupUi(this);
    form = new Album(this);
    form2 = new DialogT(this);

    zestaw = ":/txt/txt/zestawy.txt";
    Item::import(baza,zestaw);

    // Spawanie na sztywno wskaźników z myQlabel
    tab[0]= ui->label;
    tab[1]= ui->label_2;
    tab[2]= ui->label_3;
    tab[3]= ui->label_4;
    tab[4]= ui->label_5;
    tab[5]= ui->label_6;
    tab[6]= ui->label_7;
    tab[7]= ui->label_8;
    tab[8]= ui->label_9;

    for(int i=0; i<9; i++)
    {
        //tab[i]->setPixmap(baza[i].SeeImg().scaled(212,102,Qt::KeepAspectRatio));
        tab[i]->setPixmap(baza[i].img.scaled(212,102,Qt::KeepAspectRatio));
        tab[i]->SetRef(i);
    }
    for(int i=0; i<9; i++)
    {
        connect(tab[i],SIGNAL(Pressed(int)),this,SLOT(Pressed(int)));

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
    QString ns=baza[t].SeeWsk();
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
