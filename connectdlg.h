#ifndef CONNECTDLG_H
#define CONNECTDLG_H

#include <QDialog>

namespace Ui {
class ConnectDlg;
}

class ConnectDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectDlg(QWidget *parent = 0);
    ~ConnectDlg();
    QString getAdress();
    QString getPort();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ConnectDlg *ui;
};

#endif // CONNECTDLG_H
