#ifndef DIALOGT_H
#define DIALOGT_H

#include <myqlabel.h>
#include <categories.h>
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

    QVector<Item> v_categoryitems;
    QVector<QString> v_badanswers;
    myQLabel *tabl1[9];
    int index=0;

    // Ustawienie odpowiedzi
    void setAnswers(QString a,QString b, QString c);
    void setAnswerA(QString a);
    void setAnswerB(QString a);
    void setAnswerC(QString a);

    void cleanButton();

    QString& showAnswer(int x);
    void checkAnswer(QString& chosenAnswer, int& ifq);

public slots:
    void questsource(QString);
    void Pressed(int);

private slots:
    // Przyciski -- Buttons
    void on_pOdpA_clicked(); // Answer A
    void on_pOdpB_clicked(); // Answer B
    void on_pOdpC_clicked(); // Answer C
    void on_pNext_clicked();

    void statusChanged(QMediaPlayer::MediaStatus);  // obsługa zmian statusów
    void play();					// reakcje na wciśnięcie:	// odtwórz/pauza
    void stop();

    void setAnswer(QString oa);
    void import(QVector<QString>& v_category, QString &f);
private:
    // Odpowiedzi
    QString AnsA,AnsB,AnsC;
    QMediaPlayer *player;
    Ui::DialogT *ui;
};

#endif // DIALOGT_H
