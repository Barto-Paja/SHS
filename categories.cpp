#include "categories.h"
#include "ui_categories.h"

Categories::Categories(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Categories)
{
    ui->setupUi(this);
    form = new Album(this);
    form2 = new DialogT(this);

    SetupGui(v_items,t_setofcategory);
}

Categories::~Categories()
{
    info = false;
    delete ui;
}

void Categories::Pressed(int index)
{
    emit send(v_items[index].SeePtr());

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

void Categories::bInfo(bool b)
{
    info = b;
}

void Categories::SetupGui(QVector<Item>& v_it, QString& file)
{
    file = ":/txt/txt/zestawy.txt";

    QFile f(file);
    int n;

    Item::Import(v_it,file);
    Item::CountLines(f,n=0);

    ui->gridLayout->setSpacing(10);
    n=n/3;

    for(int i=0;i<n;i++)
    {
        l_myLabels << new myQLabel(this);
        l_myLabels.at(i)->SetRef(i);
        l_myLabels.at(i)->setPixmap(v_it[i].SeeImg().scaled(300,164,Qt::KeepAspectRatio));
        //l_myLabels.at(i)->setFrameStyle(3);
        l_myLabels.at(i)->setAlignment(Qt::AlignCenter);
    }

    for(int i=0;i<n;i++)
    {
        ui->gridLayout->addWidget(l_myLabels.at(i),(i/3),(i%3));
        connect(l_myLabels.at(i),SIGNAL(Pressed(int)),this,SLOT(Pressed(int)));
    }

        connect(this,SIGNAL(send(QString)),form,SLOT(Reception(QString)));
        connect(this,SIGNAL(send(QString)),form2,SLOT(questsource(QString)));
}
