#include "album.h"
#include "ui_album.h"

Album::Album(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Album)
{
    ui->setupUi(this);
    form = new Dialog(this);
    spawanie();
    connect(this,SIGNAL(info(QPixmap,QString,QString)),form,SLOT(odbior(QPixmap,QString,QString)));

}

Album::~Album()
{
    delete ui;
}

void Album::odbiornik(QString n1)
{
    basa.clear();
    if(n1!=0)
    {
        ns=n1;

        Item::import(basa,ns);
        QFile zp(ns);
        Item::ilewierszy(zp,n=0);
        n=n/3;
        for(int i=0; i<n; i++)
        {
            tab << new myQLabel(this);
            //tab.at(i)->setText("I'm label nr: "+QString::number(n));
            tab.at(i)->setPixmap(tablica[i].SeeImg().scaled(300,164,Qt::KeepAspectRatio));
            tab.at(i)->setFrameStyle(3);
        }

//        for(int i=0;i<n;i++)
//        {
//            ui->gridLayout->addWidget(tab.at(i),(i/3),(i%3));
//            connect(tab.at(i),SIGNAL(Pressed(int)),this,SLOT(Pressed(int)));
//        }

    }
    else
    {
       // ui->label->setText("Coś się wykrzacza!");
    }

}

void Album::Pressed(int t)
{
    QPixmap img = basa[t].SeeImg();
    QString name = basa[t].SeeName();
    QString sound = basa[t].SeeWsk();

    emit info(img,name,sound);

    form->setModal(true);
    form->exec();

}

void Album::spawanie()
{


//    for(int i=0; i<9; i++)
//        {
//            connect(tab1[i],SIGNAL(Pressed(int)),this,SLOT(Pressed(int)));
//        }

}
