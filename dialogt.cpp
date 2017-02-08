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
    player = new QMediaPlayer(this);
    connect(player,SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),this,SLOT(statusChanged(QMediaPlayer::MediaStatus)));
    connect(ui->label,SIGNAL(Pressed(int)),this,SLOT(play()));

    cleanButton();


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

void DialogT::cleanButton()
{
    ui->pOdpA->isDefault();
    ui->pOdpB->isDefault();
    ui->pOdpC->isDefault();
    ui->l_Odp->setText("");
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
        player->setMedia(QUrl::fromLocalFile(bassa[t].SeeWsk()));
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
    player->setMedia(QUrl::fromLocalFile(bassa[t].SeeWsk()));
    cleanButton();

    if(t==9)
    {
        t=0;
        player->stop();
        cleanButton();
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
void DialogT::Pressed(int)
{
    player->play();
}
void DialogT::statusChanged(QMediaPlayer::MediaStatus status)
{
    switch(status)
    {
    case QMediaPlayer::EndOfMedia:
           play();
           break;

    default:
        break;
    }
}
void DialogT::play()
{
    if(player->state() != QMediaPlayer::PlayingState)
    {
        player->play();
    }
    else
    {
        player->stop();
    }
}
void DialogT::stop()
{
    player->stop();
}

