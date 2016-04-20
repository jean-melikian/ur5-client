/********************************************************************************
** Form generated from reading UI file 'previewdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREVIEWDLG_H
#define UI_PREVIEWDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include "bzview.h"

QT_BEGIN_NAMESPACE

class Ui_PreviewDlg
{
public:
    QGridLayout *gridLayout;
    BzView *View;

    void setupUi(QDialog *PreviewDlg)
    {
        if (PreviewDlg->objectName().isEmpty())
            PreviewDlg->setObjectName(QStringLiteral("PreviewDlg"));
        PreviewDlg->resize(1094, 594);
        gridLayout = new QGridLayout(PreviewDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        View = new BzView(PreviewDlg);
        View->setObjectName(QStringLiteral("View"));

        gridLayout->addWidget(View, 0, 0, 1, 1);


        retranslateUi(PreviewDlg);

        QMetaObject::connectSlotsByName(PreviewDlg);
    } // setupUi

    void retranslateUi(QDialog *PreviewDlg)
    {
        PreviewDlg->setWindowTitle(QApplication::translate("PreviewDlg", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class PreviewDlg: public Ui_PreviewDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREVIEWDLG_H
