#ifndef ALBUM_H
#define ALBUM_H

#include <myqlabel.h>
#include <kategorie.h>
#include <item.h>
#include <dialog.h>

#include <QDialog>
#include <QVector>
#include <QList>
#include <QMessageBox>


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
    QList<myQLabel *> tab;

    Dialog* form;
    int n;

signals:
    void info(QPixmap,QString,QString);
public slots:
    void odbiornik(QString);
    void Pressed(int);

private:
    void spawanie(QString &f);
    Ui::Album *ui;
};

#endif // ALBUM_H
