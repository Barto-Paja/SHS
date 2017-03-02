#include "myqlabel.h"

myQLabel::myQLabel(QWidget *parent) : QLabel(parent), img(),wsk("Text"),name("myQLabel z konstruktora")
{    
}

void myQLabel::import(QVector<myQLabel> &tab, QString &f)
{
    QString bufor;
    QFile plik(f);
    QTextStream stream(&plik);
    stream.setCodec("UTF-8");

    int size(ileWierszy(plik));
    plik.open(QFile::ReadOnly);
    for(int i=0;i<size;i++)
    {

        bufor = stream.readLine();
        tab[i].sImg(bufor);

        bufor= stream.readLine();
        tab[i].sWsk(bufor);

        bufor= stream.readLine();
        tab[i].sName(bufor);

        //tab.append(nosnik);
     }
    size=0;
    plik.close();
}

// Ustawianie i zwracanie zmiennych --------- //

void myQLabel::sImg(QString i)
{   img = i; }
void myQLabel::sWsk(QString w)
{   wsk = w; }
void myQLabel::sName(QString n)
{   name = n; }
QPixmap myQLabel::Img()
{ return img; }
QString myQLabel::Wsk()
{ return wsk; }
QString myQLabel::Name()
{ return name; }

// Ustawianie i zwracanie zmiennych --------------- Koniec //

// Sygnały, kliknięcie, nr Referencyjny
void myQLabel::mousePressEvent(QMouseEvent *event)
{
    int q = SeeRef();
    emit Pressed(q);
}

void myQLabel::SetRef(int i)
{
    RefCode = i;
}
int myQLabel::SeeRef()
{ return RefCode; }
// ---------------------------------------- //
int myQLabel::ileWierszy(QFile &f)
{
    f.open(QFile::ReadOnly);
    int i;
    QString b;
    QTextStream str(&f);
    while(!f.atEnd())
    {
        b = str.readLine();
        i++;
    }
    f.close();
    return i;
}

