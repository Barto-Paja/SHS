#ifndef ITEM_H
#define ITEM_H

#include "myqlabel.h"

#include <QPixmap>
#include <QObject>
#include <QString>
#include <QUrl>
#include <QFile>
#include <QTextStream>
#include <QVector>

class Item
{
public:
    Item();

    void import(QVector<Item> &tab, QString& f);
    int ilewierszy(QFile& plik, int& i);

    void SetImg(QString x);
    void SetWsk(QString y);
    void SetName(QString z);

    QPixmap SeeImg();
    QString SeeWsk();
    QString SeeName();

private:
    QPixmap img;
    QString wsk;
    QString name;
};

#endif // ITEM_H
