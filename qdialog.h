#ifndef QDIALOG_H
#define QDIALOG_H

#include <QDialog>

namespace Ui {
class qDialog;
}

class qDialog : public QDialog
{
    Q_OBJECT

public:
    explicit qDialog(QWidget *parent = 0);
    ~qDialog();

private:
    Ui::qDialog *ui;
};

#endif // QDIALOG_H
