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

//    for(int i=0; i<9; i++)
//    {
//        connect(tab[i],SIGNAL(Pressed(int)),this,SLOT(Pressed(int)));

//    }
    connect(this,SIGNAL(send(QString)),form,SLOT(odbiornik(QString)));
    connect(this,SIGNAL(send(QString)),form2,SLOT(odbiornik(QString)));
/* Notatka ------------------------
    myQLabel *labi = new myQLabel;
    labi->setText("I'm labi :*");
    labi->setFrameStyle(2);
    myQLabel *labos = new myQLabel;
    labos->setText("I'm Labos ^^");
    labos->setFrameStyle(3);
    myQLabel *gringo = new myQLabel;
    gringo->setText("Hi! I'm gringo!");
    gringo->setFrameStyle(2);
    ui->gridLayout_2->addWidget(labi,0,0);
    ui->gridLayout_2->setSpacing(10);
    ui->gridLayout_2->addWidget(labos,0,1);
    ui->gridLayout_2->addWidget(gringo,1,0);

-------------------------------------------------*/
}

Kategorie::~Kategorie()
{
    info=false;
    delete ui;
}
void Kategorie::Pressed(int t)
{
    //QString ns=baza[t].SeeWsk();
    //emit send(ns);

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
