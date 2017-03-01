#include "myqlabel.h"

myQLabel::myQLabel(QWidget *parent) : QLabel(parent)
{    
}

void myQLabel::import(QVector<myQLabel> &tab, QString &f)
{
    QString bufor;
    QFile plik(f);
    QTextStream stream(&plik);
    stream.setCodec("UTF-8");

    int size;
    ilewierszy(plik, size); // funkcja zliczajaca ile jest elementow w pliku zrodlowym
    size = size/3;
    plik.open(QFile::ReadOnly);
    for(int i=0;i<size;i++)
    {
        Item nosnik;
        bufor = stream.readLine();
        nosnik.SetImg(bufor);

        bufor= stream.readLine();
        nosnik.SetWsk(bufor);

        bufor= stream.readLine();
        nosnik.SetName(bufor);

        tab.append(nosnik);
        }
    size=0;
    plik.close();
}

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
// Koniec SknR
