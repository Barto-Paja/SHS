#include "dialogt.h"
#include "ui_dialogt.h"

DialogT::DialogT(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogT)
{
    ui->setupUi(this);
    QString file(":/txt/txt/zle_odpowiedzi.txt");
    import(zleOdp,file);
    //ui->label->setPixmap(bassa[2].SeeImg());
}

DialogT::~DialogT()
{
    delete ui;
}

void DialogT::ustawOdp(QString a, QString b, QString c)
{
    OdpA = a; OdpB = b; OdpC = c;
}

void DialogT::ustawOdpinA(QString a)
{
    OdpA = a;
}

void DialogT::ustawOdpinB(QString a)
{
    OdpB = a;
}

void DialogT::ustawOdpinC(QString a)
{
    OdpC = a;
}

QString DialogT::beltOdp(int x)
{
    switch(x)
    {
        case 1:
        return OdpA;
        break;

        case 2:
        return OdpB;
        break;

        case 3:
        return OdpC;
        break;

    default:
        break;
    }
    return 0;
}

void DialogT::spr_odpowiedz(QString &o, int &w)
{
    if(o==bassa[w].SeeName())
    {
        ui->l_Odp->setText("Dobrze! :) Przejdź do następnego pytania");
    }
    else
    {
        ui->l_Odp->setText("Zastanów się i wybierz jeszcze raz odpowiedź ;)");
    }
}
void DialogT::odbiornik(QString n2)
{
    bassa.clear();
    if(n2!=0)
    {
        ns=n2;
        Item::import( bassa, ns);
        ui->label->setPixmap(bassa[t].SeeImg());
        umiescOdp(bassa[t].SeeName());
    }
    else
    {
        ui->l_Odp->setText("Coś się wykrzacza!");
    }
}
// Trzeba tutaj wstawic wywoalnie klikniecia ze zmienna
// do bazy patrz album.cpp
void DialogT::on_pOdpA_clicked()
{
    QString pom(beltOdp(1));
    spr_odpowiedz(pom,t);
}

void DialogT::on_pOdpB_clicked()
{
    QString pom(beltOdp(2));
    spr_odpowiedz(pom,t);
}

void DialogT::on_pOdpC_clicked()
{
    QString pom(beltOdp(3));
    spr_odpowiedz(pom,t);
}

void DialogT::on_pNext_clicked()
{
    t++;
    ui->label->setPixmap(bassa[t].SeeImg());
    umiescOdp(bassa[t].SeeName());


    if(t>9)
    {
        t=0;
        delete ui;
        this->close();

    }
}
void DialogT::umiescOdp(QString oa)
{
    // Zakładamy, że oa to dobra nasza odpowiedz
    int f;
    int pom=zleOdp.size();
    QString ob(QString::number(pom));
    QString oc;
    //int pom=zleOdp.size();
    oc = zleOdp[qrand()%(zleOdp.size()-1) ];
    ob = zleOdp[qrand()%(zleOdp.size()-1) ];
//    do{
//    ob = zleOdp[qrand()% zleOdp.size()];
//    }
//    while(ob==oc && ob==oa)
//    {
//        ob = zleOdp[qrand()% zleOdp.size()];
//        //oc = zleOdp[qrand()% zleOdp.size()];
//    }


    f=(qrand()%3);
    switch(f)
    {
        // Dobra odpowiedz A
        case 0:
        ustawOdp( oa, ob, oc);
        ui->pOdpA->setText(oa);
        ui->pOdpB->setText(ob);
        ui->pOdpC->setText(oc);
        break;
        // Dobra odpowiedz B
        case 1:
        ustawOdp( ob, oa, oc);
        ui->pOdpA->setText(ob);
        ui->pOdpB->setText(oa);
        ui->pOdpC->setText(oc);
        break;
        // Dobra odpowiedz C
        case 2:
        ustawOdp(oc,ob,oa);
        ui->pOdpA->setText(oc);
        ui->pOdpB->setText(ob);
        ui->pOdpC->setText(oa);
        break;
    default:
        ui->l_Odp->setText("Wybieg poza zakres switch'a");
        break;
    }

}

void DialogT::import(QVector<QString> &db, QString &f)
{
    QString bufor;
    QFile plik(f);
    QTextStream stream(&plik);
    stream.setCodec("UTF-8");
    plik.open(QFile::ReadOnly);
    do
    {
        bufor=stream.readLine();
        db.append(bufor);
    }
    while(bufor!=NULL);

}
// Wczytanie tablicy napisz funkcje, mozna zastosowac tablice typu wektor
// wybierzemy wtedy losowe linie ( czyt. elementy tablicy )
// potem porownamy, czy nie jest przypadkiem to taka sama nazwa jak odpowiedz poprawna
// jezeli jest to losuj inna, a jak nie to zostaw
// buziaki :**, pa
// DAMY RADĘ !!!
// P.S - trzeba zacząc komnetowac ten kod i pomyslec 2 razy nad nazwami zmiennych itd

// Na niedziele - wczytywanie zrobione, teraz potrzeba tylko podpiac wyswietlanie i podpisy
// Nie łam się - jeszcze tylko testy i estetyczne/kosmetyczne poprawki
// Trzymam kciuki!
// :**, pa <3
