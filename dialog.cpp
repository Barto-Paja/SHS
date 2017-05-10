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
void Dialog::SetItem(QPixmap image, QString name, QString sound)
{
    Dialog::windowTitle() = name;

    ui->label->setPixmap(image.scaled(760,430,Qt::KeepAspectRatio));
    player->setMedia(QUrl::fromLocalFile(sound));
    ui->label_2->setText(name);
}

void Dialog::Pressed(int)
{
    player->play();
}
void Dialog::statusChanged(QMediaPlayer::MediaStatus status)
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
