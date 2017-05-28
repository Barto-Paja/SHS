#include "album.h"
#include "ui_album.h"

Album::Album(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Album)
{
    ui->setupUi(this);
    form = new Dialog(this);
    connect(this,SIGNAL(item(QPixmap,QString,QString)),form,SLOT(SetItem(QPixmap,QString,QString)));
}

Album::~Album()
{
    delete ui;
}

void Album::Reception(QString s_iteminfo)
{
    v_categoryItems.clear();
    if(s_iteminfo!=0)
    {
      Item::Import(v_categoryItems,s_iteminfo);
      SetupGui(s_iteminfo);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Kategoria została niepoprawnie załadowana.");
        msgBox.exec();
        this->close();
    }

}

void Album::Pressed(int index)
{
    QPixmap img = v_categoryItems[index].SeeImg();
    QString name = v_categoryItems[index].SeeName();
    QString sound = v_categoryItems[index].SeePtr();

    emit item(img,name,sound);

    form->setModal(true);
    form->exec();
}


void Album::SetupGui(QString &f)
{
    int n;
    QFile p(f);
    Item::CountLines(p,n);

    for(int i=0; i<(n/3); i++)
    {
        l_myLabels << new myQLabel(this);
        l_myLabels.at(i)->SetRef(i);
        l_myLabels.at(i)->setPixmap(v_categoryItems[i].SeeImg().scaled(300,164,Qt::KeepAspectRatio));
        //l_myLabels.at(i)->setFrameStyle(3);
        l_myLabels.at(i)->setAlignment(Qt::AlignCenter);
        ui->gridLayout->addWidget(l_myLabels.at(i),(i/3),(i%3));
        connect(l_myLabels.at(i),SIGNAL(Pressed(int)),this,SLOT(Pressed(int)));
    }
}
