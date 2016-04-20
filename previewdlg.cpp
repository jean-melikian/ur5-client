#include "previewdlg.h"
#include "ui_previewdlg.h"
#include "mainwindow.h"

PreviewDlg::PreviewDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreviewDlg)
{
    ui->setupUi(this);
    ui->View->setMainWindow((UR5Console *)parent);
}

PreviewDlg::~PreviewDlg()
{
    delete ui;
}
