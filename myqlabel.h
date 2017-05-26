#ifndef MYQLABEL_H
#define MYQLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QEvent>

class myQLabel : public QLabel
{
    Q_OBJECT

public:
    explicit myQLabel(QWidget *parent=0);

    void mousePressEvent(QMouseEvent *event);
    void SetRef(int i);

    int SeeRef() const;


signals:
    void Pressed(int);
private:
    int RefCode; // <-- Kod referencyjny sygnału

};

#endif // MYQLABEL_H
