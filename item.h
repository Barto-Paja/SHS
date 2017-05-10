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

    void Import(QVector<Item>& v_item, QString& f);
    int CountLines(QFile& f, int& i);

    void SetImg(QString x);
    void SetPtr(QString y);
    void SetName(QString z);

    QPixmap SeeImg();
    QString SeePtr();
    QString SeeName();

private:
    QPixmap img;
    QString ptr;  // Ptr -> pointer
    QString name;
};

#endif // ITEM_H
