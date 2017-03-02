#ifndef MYQLABEL_H
#define MYQLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QEvent>

#include <QPixmap>
#include <QObject>
#include <QString>
#include <QUrl>
#include <QFile>
#include <QTextStream>
#include <QVector>

class myQLabel : public QLabel
{
    Q_OBJECT

    friend class Kategorie;

public:
    explicit myQLabel(QWidget *parent=0);

    void import(QVector<myQLabel> &tab, QString &f);

    // Ustawianie i zwracanie zmiennych

    void sImg(QString i);
    void sWsk(QString w);
    void sName(QString n);

    QPixmap Img();
    QString Wsk();
    QString Name();

    // Mechanika przechwytywania sygnału i kliknięcia

    void mousePressEvent(QMouseEvent *event);
    void SetRef(int i);
    int SeeRef();

    //********** KONIEC *********//
signals:
    void Pressed(int);
private:
    int RefCode; // <-- Kod referencyjny sygnału

    int ileWierszy(QFile &f);

    QPixmap img;
    QString wsk; // <-- wsk od "Wskaźnik" domyślnie ( wskazuj na ścieżkę utworu )
    QString name;

};

#endif // MYQLABEL_H
