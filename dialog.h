#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPixmap>
#include <QMediaPlayer>
#include <QString>

#include <QMediaPlaylist>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    QPixmap ns1;
    QString ns2,ns3;

    void closeEvent ( QCloseEvent * event );

public slots:
    void odbior(QPixmap,QString,QString);
    void Pressed(int);
private slots:
    void statusChanged(QMediaPlayer::MediaStatus);  // obsługa zmian statusów
    void play();					// reakcje na wciśnięcie:	// odtwórz/pauza
    void stop();
private:
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    Ui::Dialog *ui;
};

#endif // DIALOG_H
