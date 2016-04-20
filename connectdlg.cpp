#include "connectdlg.h"
#include "ui_connectdlg.h"

ConnectDlg::ConnectDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectDlg)
{
    ui->setupUi(this);
}

ConnectDlg::~ConnectDlg()
{
    delete ui;
}

QString ConnectDlg::getAdress()
{
    return ui->lineEditAdress->text();
}

QString ConnectDlg::getPort()
{
    return ui->lineEditPort->text();
}

void ConnectDlg::on_buttonBox_accepted()
{

}
