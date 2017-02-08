#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist();
    connect(player,SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),this,SLOT(statusChanged(QMediaPlayer::MediaStatus)));

    connect(ui->label,SIGNAL(Pressed(int)),this,SLOT(play()));

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::odbior(QPixmap n1, QString n2, QString n3)
{


    ns1 = n1; // img
    ns2 = n2; // name
    ns3 = n3; // sound


    ui->label->setPixmap(ns1);
    //player->setMedia(QUrl::fromLocalFile(/*ns3*/"C:/Users/Bartosz/Downloads/04 Oko do Oka.mp3")); // <-- Tutaj odkemntować ns3 i usunąć piosenkę
    playlist->addMedia(QUrl::fromLocalFile(/*ns3*/"C:/Users/Bartosz/Downloads/exd.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(playlist);
    ui->label_2->setText(ns2);

}

void Dialog::Pressed(int)
{
    player->play();
}
void Dialog::statusChanged(QMediaPlayer::MediaStatus status)
{
//    switch(status)
//    {
//    case QMediaPlayer::EndOfMedia:
//           play();
//           break;

//    default:
//        break;
//    }
}
void Dialog::play()
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
void Dialog::stop()
{
    player->stop();
}
void Dialog::closeEvent ( QCloseEvent * event )
{
    event->ignore();
    player->stop();
    event->accept();
}
