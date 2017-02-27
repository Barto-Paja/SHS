#include "item.h"

Item::Item():img(),wsk("txt"),name("txt")
{
}

void Item::import(QVector<Item> &tab, QString &f)
{
    QString bufor;
    QFile plik(f);
    QTextStream stream(&plik);
    stream.setCodec("UTF-8");

    //plik.open(QFile::ReadOnly);`
    int size ;
    ilewierszy(plik, size);
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

int Item::ilewierszy(QFile &plik, int &i)
{
    plik.open(QFile::ReadOnly);
       QString bufor;
       QTextStream stream(&plik);
       while(!plik.atEnd())
       {
           bufor = stream.readLine();
           i++;
       }
    plik.close();
    return i;
}
void Item::SetImg(QString x)
{ img = x; }
void Item::SetWsk(QString y)
{ wsk = y; }
void Item::SetName(QString z)
{ name = z; }

QPixmap Item::SeeImg()
{ return img; }
QString Item::SeeWsk()
{ return wsk; }
QString Item::SeeName()
{ return name; }
