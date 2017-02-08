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

        for(int i=0; i<9; i++)
        {
            tab1[i]->setPixmap(basa[i].SeeImg().scaled(222,102,Qt::KeepAspectRatio));
            tab1[i]->SetRef(i);
        }
    }
    else
    {
        ui->label->setText("Coś się wykrzacza!");
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
    tab1[0]= ui->label;
    tab1[1]= ui->label_2;
    tab1[2]= ui->label_3;
    tab1[3]= ui->label_4;
    tab1[4]= ui->label_5;
    tab1[5]= ui->label_6;
    tab1[6]= ui->label_7;
    tab1[7]= ui->label_8;
    tab1[8]= ui->label_9;

    for(int i=0; i<9; i++)
        {
            connect(tab1[i],SIGNAL(Pressed(int)),this,SLOT(Pressed(int)));
        }

}
