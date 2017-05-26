#include "myqlabel.h"

myQLabel::myQLabel(QWidget *parent) : QLabel(parent)
{

}

void myQLabel::mousePressEvent(QMouseEvent *event)
{
    int q = SeeRef();
    emit Pressed(q);
}

void myQLabel::SetRef(int i)
{
    RefCode = i;
}
int myQLabel::SeeRef() const
{ return RefCode; }


