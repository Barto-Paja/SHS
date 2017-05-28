#include "item.h"

Item::Item():img(),ptr("txt"),name("txt")
{
}

void Item::Import(QVector<Item>& v_item, QString& f)
{
    QString buffer;
    QFile file(f);
    QTextStream stream(&file);
    stream.setCodec("UTF-8");

    int size;
    CountLines(file, size=0);
    file.open(QFile::ReadOnly);
    for(int i=0;i<(size/3);i++)
    {
        Item carrier;
        buffer = stream.readLine();
        carrier.SetImg(buffer);

        buffer = stream.readLine();
        carrier.SetPtr(buffer);

        buffer = stream.readLine();
        carrier.SetName(buffer);

        v_item.append(carrier);
    }
    size=0;
    file.close();
}

int Item::CountLines(QFile &f, int& i)
{
    QString buffer;
    QTextStream stream(&f);

    i=0; // <-- resetowanie zmiennej
    f.open(QFile::ReadOnly);
    while(!stream.atEnd())
    {
        buffer = stream.readLine();
        i++;
    }
    f.close();
    return i;
}
void Item::SetImg(QString x)
{ img = x; }
void Item::SetPtr(QString y)
{ ptr = y; }
void Item::SetName(QString z)
{ name = z; }

QPixmap Item::SeeImg() const
{ return img; }
QString Item::SeePtr() const
{ return ptr; }
QString Item::SeeName() const
{ return name; }
