#ifndef CATEGORIES_H
#define CATEGORIES_H

#include <item.h>
#include <myqlabel.h>
#include <album.h>
#include <dialogt.h>

#include <QDialog>
#include <QVector>
#include <QList>

namespace Ui {
class Categories;
}
class Album;
class DialogT;
class Categories : public QDialog, private Item
{
    Q_OBJECT

public:
    explicit Categories(QWidget *parent = 0);
    ~Categories();

    Album* form;
    DialogT* form2;
    QString t_setofcategory;

    QVector<Item> v_items;
    QList<myQLabel *> l_myLabels;

    bool info = false;

signals:
    void send(QString);
private slots:
    void Pressed(int);
    void bInfo(bool);

private:
    Ui::Categories *ui;
    void SetupGui(QVector<Item>& v_it, QString& file);
};

#endif // CATEGORIES_H
