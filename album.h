#ifndef ALBUM_H
#define ALBUM_H

#include <myqlabel.h>
#include <kategorie.h>
#include <item.h>
#include <dialog.h>

#include <QDialog>
#include <QVector>


namespace Ui {
class Album;
}

class Album : public QDialog, private Item
{
    Q_OBJECT

public:
    explicit Album(QWidget *parent = 0);
    ~Album();
    QString ns;
    QVector<Item> basa;
    myQLabel *tab1[9];

    Dialog* form;

signals:
    void info(QPixmap,QString,QString);
public slots:
    void odbiornik(QString);
    void Pressed(int);

private:
    void spawanie();
    Ui::Album *ui;
};

#endif // ALBUM_H
