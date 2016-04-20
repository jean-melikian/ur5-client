/********************************************************************************
** Form generated from reading UI file 'connectdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTDLG_H
#define UI_CONNECTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_ConnectDlg
{
public:
    QGridLayout *gridLayout;
    QLabel *labelAdress;
    QLineEdit *lineEditAdress;
    QLabel *labelPort;
    QLineEdit *lineEditPort;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConnectDlg)
    {
        if (ConnectDlg->objectName().isEmpty())
            ConnectDlg->setObjectName(QStringLiteral("ConnectDlg"));
        ConnectDlg->setWindowModality(Qt::NonModal);
        ConnectDlg->resize(216, 93);
        gridLayout = new QGridLayout(ConnectDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelAdress = new QLabel(ConnectDlg);
        labelAdress->setObjectName(QStringLiteral("labelAdress"));
        labelAdress->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelAdress, 0, 0, 1, 1);

        lineEditAdress = new QLineEdit(ConnectDlg);
        lineEditAdress->setObjectName(QStringLiteral("lineEditAdress"));

        gridLayout->addWidget(lineEditAdress, 0, 1, 1, 1);

        labelPort = new QLabel(ConnectDlg);
        labelPort->setObjectName(QStringLiteral("labelPort"));
        labelPort->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelPort, 1, 0, 1, 1);

        lineEditPort = new QLineEdit(ConnectDlg);
        lineEditPort->setObjectName(QStringLiteral("lineEditPort"));

        gridLayout->addWidget(lineEditPort, 1, 1, 1, 1);

        buttonBox = new QDialogButtonBox(ConnectDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 2);


        retranslateUi(ConnectDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConnectDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConnectDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConnectDlg);
    } // setupUi

    void retranslateUi(QDialog *ConnectDlg)
    {
        ConnectDlg->setWindowTitle(QApplication::translate("ConnectDlg", "Dialog", 0));
        labelAdress->setText(QApplication::translate("ConnectDlg", "Adresse IP :", 0));
        lineEditAdress->setText(QApplication::translate("ConnectDlg", "172.22.49.221", 0));
        labelPort->setText(QApplication::translate("ConnectDlg", "Port :", 0));
        lineEditPort->setText(QApplication::translate("ConnectDlg", "30002", 0));
    } // retranslateUi

};

namespace Ui {
    class ConnectDlg: public Ui_ConnectDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTDLG_H
