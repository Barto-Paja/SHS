#include "album.h"
#include "ui_album.h"

Album::Album(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Album)
{
    ui->setupUi(this);
    //tab = new QList<myQLabel *>;
    form = new Dialog(this);

    connect(this,SIGNAL(info(QPixmap,QString,QString)),form,SLOT(odbior(QPixmap,QString,QString)));

}

Album::~Album()
{
//    tab.clear();
//    while(tab.isEmpty()==false)
//    {
//        tab.removeLast();
//    }
//    for(int i=0; i<n; i++)
//    {
//        ui->gridLayout->removeWidget(tabx.at(i));
//    }
//    tabx.clear();
    delete ui;
}

void Album::odbiornik(QString n1)
{
    basa.clear();

    if(n1!=0)
    {
      ns=n1;
      Item::import(basa,ns);
    }
    else
    {
       // ui->label->setText("Coś się wykrzacza!");
    }

}

void Album::Pressed(int t)
{
//    QPixmap img = basa[t].SeeImg();
//    QString name = basa[t].SeeName();
//    QString sound = basa[t].SeeWsk();

//    emit info(img,name,sound);

//    form->setModal(true);
//    form->exec();

}

void Album::spawanie(QString &f)
{
    int n;
    QFile p(f);
    Item::ilewierszy(p,n=0);

//    tab << new myQLabel(this);
//    tab.at(0)->setText("Bla bla bla!");

//    ui->gridLayout->addWidget(tab.at(0));

}
