#include "dialogt.h"
#include "ui_dialogt.h"


DialogT::DialogT(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogT)
{
    ui->setupUi(this);
    QString file(":/txt/txt/zle_odpowiedzi.txt");
    import(v_badanswers,file);
    player = new QMediaPlayer(this);
    connect(player,SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),this,SLOT(statusChanged(QMediaPlayer::MediaStatus)));
    connect(ui->label,SIGNAL(Pressed(int)),this,SLOT(play()));

    cleanButton();
}

DialogT::~DialogT()
{
    delete ui;
}

void DialogT::setAnswers(QString a, QString b, QString c)
{
    AnsA = a; AnsB = b; AnsC = c;
}

void DialogT::setAnswerA(QString a)
{
    AnsA = a;
}

void DialogT::setAnswerB(QString a)
{
    AnsB = a;
}

void DialogT::setAnswerC(QString a)
{
    AnsC = a;
}

void DialogT::cleanButton()
{
    ui->pOdpA->isDefault();
    ui->pOdpB->isDefault();
    ui->pOdpC->isDefault();
    ui->l_Odp->setText("");
}

QString& DialogT::showAnswer(int x)
{
    switch(x)
    {
        case 1:
        return AnsA;
        break;

        case 2:
        return AnsB;
        break;

        case 3:
        return AnsC;
        break;

    default:
        break;
    }
    //return 0;
}

void DialogT::checkAnswer(QString &chosenAnswer, int &ifq)
{
    if(chosenAnswer==v_categoryitems[ifq].SeeName())
    {
        ui->l_Odp->setText("Dobrze! :) Przejdź do następnego pytania");
    }
    else
    {
        ui->l_Odp->setText("Zastanów się i wybierz jeszcze raz odpowiedź ;)");
    }
}
void DialogT::questsource(QString source)
{
    v_categoryitems.clear();
    if(source!=0)
    {
        Item::Import( v_categoryitems, source);
        ui->label->setPixmap(v_categoryitems[index].SeeImg().scaled(640,300,Qt::KeepAspectRatio));
        setAnswer(v_categoryitems[index].SeeName());
        player->setMedia(QUrl(v_categoryitems[index].SeePtr()));
    }
    else
    {
        ui->l_Odp->setText("Coś się wykrzacza!");
    }
}
void DialogT::on_pOdpA_clicked()
{
    checkAnswer(showAnswer(1),index);
}

void DialogT::on_pOdpB_clicked()
{
    checkAnswer(showAnswer(2),index);
}

void DialogT::on_pOdpC_clicked()
{
    checkAnswer(showAnswer(3),index);
}

void DialogT::on_pNext_clicked()
{
    index++;
    ui->label->setPixmap(QPixmap(v_categoryitems[index].SeeImg().scaled(640,300,Qt::KeepAspectRatio)));
    setAnswer(v_categoryitems[index].SeeName());
    player->setMedia(QUrl(v_categoryitems[index].SeePtr()));
    cleanButton();

    if(index==9)
    {
        index=0;
        player->stop();
        cleanButton();
        delete ui;
        this->close();

    }
}
void DialogT::setAnswer(QString oa)
{
    // Zakładamy, że oa to dobra nasza odpowiedz
    int f;
    int pom = v_badanswers.size();

    QString ob(QString::number(pom));
    QString oc;

    oc = v_badanswers[qrand()%(v_badanswers.size()-1) ];
    ob = v_badanswers[qrand()%(v_badanswers.size()-1) ];

    f=(qrand()%3);
    switch(f)
    {
        // Dobra odpowiedz A
        case 0:
        setAnswers(oa, ob, oc);
        ui->pOdpA->setText(oa);
        ui->pOdpB->setText(ob);
        ui->pOdpC->setText(oc);
        break;
        // Dobra odpowiedz B
        case 1:
        setAnswers(ob, oa, oc);
        ui->pOdpA->setText(ob);
        ui->pOdpB->setText(oa);
        ui->pOdpC->setText(oc);
        break;
        // Dobra odpowiedz C
        case 2:
        setAnswers(oc,ob,oa);
        ui->pOdpA->setText(oc);
        ui->pOdpB->setText(ob);
        ui->pOdpC->setText(oa);
        break;
    default:
        ui->l_Odp->setText("Wybieg poza zakres switch'a");
        break;
    }

}

void DialogT::import(QVector<QString>& v_category, QString &f)
{
    QString buffer;
    QFile file(f);
    QTextStream stream(&file);
    stream.setCodec("UTF-8");
    file.open(QFile::ReadOnly);
    do
    {
        buffer=stream.readLine();
        v_category.append(buffer);
    }
    while(buffer!=NULL);

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

