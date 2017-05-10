#ifndef ALBUM_H
#define ALBUM_H

#include <myqlabel.h>
#include <categories.h>
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
    QVector<Item> v_categoryItems;
    QList<myQLabel *> l_myLabels;

    Dialog* form;
    int n;

signals:
    void item(QPixmap,QString,QString);
public slots:
    void Reception(QString);
    void Pressed(int);

private:
    void SetupGui(QString &f);
    Ui::Album *ui;
};

#endif // ALBUM_H
