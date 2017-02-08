#ifndef DIALOGT_H
#define DIALOGT_H

#include <myqlabel.h>
#include <kategorie.h>
#include <item.h>

#include <QDialog>
#include <QPixmap>
#include <QMediaPlayer>
#include <QString>
#include <QVector>
#include <QTextStream>
#include <QFile>
#include <QObject>


namespace Ui {
class DialogT;
}

class DialogT : public QDialog, private Item
{
    Q_OBJECT

public:
    explicit DialogT(QWidget *parent = 0);
    ~DialogT();

    QString ns;
    QVector<Item> bassa;
    QVector<QString> zleOdp;
    myQLabel *tabl1[9];
    int t=0;

    // Ustawienie odpowiedzi
    void ustawOdp(QString a,QString b, QString c);
    void ustawOdpinA(QString a);
    void ustawOdpinB(QString a);
    void ustawOdpinC(QString a);

    void cleanWindow();

    QString beltOdp(int x);
    void spr_odpowiedz(QString &o, int &w);

public slots:
    void odbiornik(QString);
    void Pressed(int);

private slots:
    // Przyciski
    void on_pOdpA_clicked();
    void on_pOdpB_clicked();
    void on_pOdpC_clicked();
    void on_pNext_clicked();

    void statusChanged(QMediaPlayer::MediaStatus);  // obsługa zmian statusów
    void play();					// reakcje na wciśnięcie:	// odtwórz/pauza
    void stop();

    void umiescOdp(QString oa);
    void import(QVector<QString> &db, QString &f);
private:
    // Odpowiedzi
    QString OdpA,OdpB,OdpC;

    QMediaPlayer *player;
    Ui::DialogT *ui;
};

#endif // DIALOGT_H
