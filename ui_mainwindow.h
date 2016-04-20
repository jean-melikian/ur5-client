/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnexion;
    QAction *actionQuitter;
    QAction *actionDeconnexion;
    QAction *actionOuvrir;
    QAction *actionEnvoyerScript;
    QAction *actionArreter_Programme;
    QAction *actionOuvrirXML;
    QAction *actionGenererScript;
    QAction *actionPreview;
    QAction *actionPositionDepart;
    QWidget *centralWidget;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBoxConnexion;
    QGridLayout *gridLayout_5;
    QFormLayout *formLayout;
    QLabel *labelStatut;
    QLabel *labelStatutActuel;
    QGridLayout *gridLayout;
    QPushButton *pushButtonDeconnexion;
    QPushButton *pushButtonConnexion;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_8;
    QGroupBox *groupBoxProgramme;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_10;
    QLabel *labelProgramFileName;
    QTextEdit *textEditProgramme;
    QGridLayout *gridLayout_3;
    QPushButton *pushButtonOuvrir;
    QPushButton *pushButtonEnvoyerScript;
    QPushButton *pushButtonPositionDepart;
    QPushButton *pushButtonArreterProgramme;
    QWidget *tab_2;
    QGridLayout *gridLayout_13;
    QGroupBox *groupBoxFontXML;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QLabel *labelXMLFileName;
    QLabel *labelFontName;
    QPushButton *pushButtonOuvrirXML;
    QComboBox *comboBoxChar;
    QGroupBox *groupBoxTextEditor;
    QGridLayout *gridLayout_7;
    QLineEdit *lineEditText;
    QPushButton *pushButtonGenerate;
    QPushButton *pushButtonPreview;
    QLabel *labelText;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonQuitter;
    QGroupBox *groupBoxConsole;
    QGridLayout *gridLayout_12;
    QTextEdit *textEditLogs;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuProgramme;
    QMenu *menuPolice;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(629, 621);
        MainWindow->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/icones/res/uricon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->setDocumentMode(false);
        MainWindow->setTabShape(QTabWidget::Rounded);
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        actionConnexion = new QAction(MainWindow);
        actionConnexion->setObjectName(QStringLiteral("actionConnexion"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/icones/res/connection.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnexion->setIcon(icon1);
        actionConnexion->setFont(font);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionDeconnexion = new QAction(MainWindow);
        actionDeconnexion->setObjectName(QStringLiteral("actionDeconnexion"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/icones/res/logout.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDeconnexion->setIcon(icon2);
        actionOuvrir = new QAction(MainWindow);
        actionOuvrir->setObjectName(QStringLiteral("actionOuvrir"));
        actionEnvoyerScript = new QAction(MainWindow);
        actionEnvoyerScript->setObjectName(QStringLiteral("actionEnvoyerScript"));
        actionArreter_Programme = new QAction(MainWindow);
        actionArreter_Programme->setObjectName(QStringLiteral("actionArreter_Programme"));
        actionOuvrirXML = new QAction(MainWindow);
        actionOuvrirXML->setObjectName(QStringLiteral("actionOuvrirXML"));
        actionGenererScript = new QAction(MainWindow);
        actionGenererScript->setObjectName(QStringLiteral("actionGenererScript"));
        actionPreview = new QAction(MainWindow);
        actionPreview->setObjectName(QStringLiteral("actionPreview"));
        actionPositionDepart = new QAction(MainWindow);
        actionPositionDepart->setObjectName(QStringLiteral("actionPositionDepart"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_6 = new QGridLayout(centralWidget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        groupBoxConnexion = new QGroupBox(centralWidget);
        groupBoxConnexion->setObjectName(QStringLiteral("groupBoxConnexion"));
        gridLayout_5 = new QGridLayout(groupBoxConnexion);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        labelStatut = new QLabel(groupBoxConnexion);
        labelStatut->setObjectName(QStringLiteral("labelStatut"));
        labelStatut->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelStatut);

        labelStatutActuel = new QLabel(groupBoxConnexion);
        labelStatutActuel->setObjectName(QStringLiteral("labelStatutActuel"));
        labelStatutActuel->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, labelStatutActuel);


        gridLayout_5->addLayout(formLayout, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButtonDeconnexion = new QPushButton(groupBoxConnexion);
        pushButtonDeconnexion->setObjectName(QStringLiteral("pushButtonDeconnexion"));
        pushButtonDeconnexion->setEnabled(true);
        pushButtonDeconnexion->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(pushButtonDeconnexion, 0, 2, 1, 1);

        pushButtonConnexion = new QPushButton(groupBoxConnexion);
        pushButtonConnexion->setObjectName(QStringLiteral("pushButtonConnexion"));
        pushButtonConnexion->setMinimumSize(QSize(0, 25));
        pushButtonConnexion->setCheckable(false);

        gridLayout->addWidget(pushButtonConnexion, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout, 1, 0, 1, 1);


        gridLayout_6->addWidget(groupBoxConnexion, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setAutoFillBackground(true);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_8 = new QGridLayout(tab);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        groupBoxProgramme = new QGroupBox(tab);
        groupBoxProgramme->setObjectName(QStringLiteral("groupBoxProgramme"));
        groupBoxProgramme->setAutoFillBackground(false);
        gridLayout_11 = new QGridLayout(groupBoxProgramme);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        labelProgramFileName = new QLabel(groupBoxProgramme);
        labelProgramFileName->setObjectName(QStringLiteral("labelProgramFileName"));

        gridLayout_10->addWidget(labelProgramFileName, 0, 0, 1, 1);

        textEditProgramme = new QTextEdit(groupBoxProgramme);
        textEditProgramme->setObjectName(QStringLiteral("textEditProgramme"));
        textEditProgramme->setMinimumSize(QSize(0, 100));

        gridLayout_10->addWidget(textEditProgramme, 1, 0, 1, 1);


        gridLayout_11->addLayout(gridLayout_10, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButtonOuvrir = new QPushButton(groupBoxProgramme);
        pushButtonOuvrir->setObjectName(QStringLiteral("pushButtonOuvrir"));
        pushButtonOuvrir->setMinimumSize(QSize(0, 25));

        gridLayout_3->addWidget(pushButtonOuvrir, 0, 0, 1, 1);

        pushButtonEnvoyerScript = new QPushButton(groupBoxProgramme);
        pushButtonEnvoyerScript->setObjectName(QStringLiteral("pushButtonEnvoyerScript"));
        pushButtonEnvoyerScript->setMinimumSize(QSize(0, 25));

        gridLayout_3->addWidget(pushButtonEnvoyerScript, 0, 1, 1, 1);

        pushButtonPositionDepart = new QPushButton(groupBoxProgramme);
        pushButtonPositionDepart->setObjectName(QStringLiteral("pushButtonPositionDepart"));

        gridLayout_3->addWidget(pushButtonPositionDepart, 1, 0, 1, 1);

        pushButtonArreterProgramme = new QPushButton(groupBoxProgramme);
        pushButtonArreterProgramme->setObjectName(QStringLiteral("pushButtonArreterProgramme"));
        pushButtonArreterProgramme->setMinimumSize(QSize(0, 25));

        gridLayout_3->addWidget(pushButtonArreterProgramme, 1, 1, 1, 1);


        gridLayout_11->addLayout(gridLayout_3, 1, 0, 1, 1);


        gridLayout_8->addWidget(groupBoxProgramme, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_13 = new QGridLayout(tab_2);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        groupBoxFontXML = new QGroupBox(tab_2);
        groupBoxFontXML->setObjectName(QStringLiteral("groupBoxFontXML"));
        groupBoxFontXML->setMaximumSize(QSize(16777215, 16777215));
        groupBoxFontXML->setAutoFillBackground(false);
        gridLayout_4 = new QGridLayout(groupBoxFontXML);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        labelXMLFileName = new QLabel(groupBoxFontXML);
        labelXMLFileName->setObjectName(QStringLiteral("labelXMLFileName"));

        gridLayout_2->addWidget(labelXMLFileName, 0, 0, 1, 1);

        labelFontName = new QLabel(groupBoxFontXML);
        labelFontName->setObjectName(QStringLiteral("labelFontName"));

        gridLayout_2->addWidget(labelFontName, 0, 1, 1, 1);

        pushButtonOuvrirXML = new QPushButton(groupBoxFontXML);
        pushButtonOuvrirXML->setObjectName(QStringLiteral("pushButtonOuvrirXML"));
        pushButtonOuvrirXML->setMinimumSize(QSize(0, 25));

        gridLayout_2->addWidget(pushButtonOuvrirXML, 1, 0, 1, 1);

        comboBoxChar = new QComboBox(groupBoxFontXML);
        comboBoxChar->setObjectName(QStringLiteral("comboBoxChar"));
        comboBoxChar->setEnabled(false);

        gridLayout_2->addWidget(comboBoxChar, 1, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);


        gridLayout_13->addWidget(groupBoxFontXML, 1, 0, 1, 1);

        groupBoxTextEditor = new QGroupBox(tab_2);
        groupBoxTextEditor->setObjectName(QStringLiteral("groupBoxTextEditor"));
        groupBoxTextEditor->setMaximumSize(QSize(16777215, 16777215));
        groupBoxTextEditor->setAutoFillBackground(false);
        gridLayout_7 = new QGridLayout(groupBoxTextEditor);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        lineEditText = new QLineEdit(groupBoxTextEditor);
        lineEditText->setObjectName(QStringLiteral("lineEditText"));

        gridLayout_7->addWidget(lineEditText, 1, 0, 1, 2);

        pushButtonGenerate = new QPushButton(groupBoxTextEditor);
        pushButtonGenerate->setObjectName(QStringLiteral("pushButtonGenerate"));
        pushButtonGenerate->setMinimumSize(QSize(0, 0));

        gridLayout_7->addWidget(pushButtonGenerate, 3, 0, 1, 2);

        pushButtonPreview = new QPushButton(groupBoxTextEditor);
        pushButtonPreview->setObjectName(QStringLiteral("pushButtonPreview"));
        pushButtonPreview->setMinimumSize(QSize(567, 25));

        gridLayout_7->addWidget(pushButtonPreview, 2, 0, 1, 2);

        labelText = new QLabel(groupBoxTextEditor);
        labelText->setObjectName(QStringLiteral("labelText"));

        gridLayout_7->addWidget(labelText, 0, 0, 1, 2);


        gridLayout_13->addWidget(groupBoxTextEditor, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_13->addItem(verticalSpacer, 3, 0, 2, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_6->addWidget(tabWidget, 1, 0, 1, 1);

        pushButtonQuitter = new QPushButton(centralWidget);
        pushButtonQuitter->setObjectName(QStringLiteral("pushButtonQuitter"));
        pushButtonQuitter->setMinimumSize(QSize(0, 25));

        gridLayout_6->addWidget(pushButtonQuitter, 2, 0, 1, 1);

        groupBoxConsole = new QGroupBox(centralWidget);
        groupBoxConsole->setObjectName(QStringLiteral("groupBoxConsole"));
        groupBoxConsole->setMaximumSize(QSize(16777215, 130));
        gridLayout_12 = new QGridLayout(groupBoxConsole);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        textEditLogs = new QTextEdit(groupBoxConsole);
        textEditLogs->setObjectName(QStringLiteral("textEditLogs"));
        textEditLogs->setMaximumSize(QSize(16777215, 16777215));
        textEditLogs->setFont(font);
        textEditLogs->setReadOnly(true);
        textEditLogs->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_12->addWidget(textEditLogs, 0, 0, 1, 1);


        gridLayout_6->addWidget(groupBoxConsole, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 629, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuProgramme = new QMenu(menuBar);
        menuProgramme->setObjectName(QStringLiteral("menuProgramme"));
        menuPolice = new QMenu(menuBar);
        menuPolice->setObjectName(QStringLiteral("menuPolice"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        QWidget::setTabOrder(pushButtonConnexion, pushButtonDeconnexion);
        QWidget::setTabOrder(pushButtonDeconnexion, textEditProgramme);
        QWidget::setTabOrder(textEditProgramme, pushButtonOuvrir);
        QWidget::setTabOrder(pushButtonOuvrir, pushButtonEnvoyerScript);
        QWidget::setTabOrder(pushButtonEnvoyerScript, pushButtonPositionDepart);
        QWidget::setTabOrder(pushButtonPositionDepart, pushButtonArreterProgramme);
        QWidget::setTabOrder(pushButtonArreterProgramme, tabWidget);
        QWidget::setTabOrder(tabWidget, pushButtonOuvrirXML);
        QWidget::setTabOrder(pushButtonOuvrirXML, comboBoxChar);
        QWidget::setTabOrder(comboBoxChar, lineEditText);
        QWidget::setTabOrder(lineEditText, pushButtonPreview);
        QWidget::setTabOrder(pushButtonPreview, pushButtonGenerate);
        QWidget::setTabOrder(pushButtonGenerate, pushButtonQuitter);
        QWidget::setTabOrder(pushButtonQuitter, textEditLogs);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuPolice->menuAction());
        menuBar->addAction(menuProgramme->menuAction());
        menuFichier->addAction(actionConnexion);
        menuFichier->addAction(actionDeconnexion);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        menuProgramme->addAction(actionOuvrir);
        menuProgramme->addSeparator();
        menuProgramme->addAction(actionEnvoyerScript);
        menuProgramme->addAction(actionArreter_Programme);
        menuProgramme->addAction(actionPositionDepart);
        menuPolice->addAction(actionOuvrirXML);
        menuPolice->addSeparator();
        menuPolice->addAction(actionPreview);
        menuPolice->addAction(actionGenererScript);
        toolBar->addAction(actionConnexion);
        toolBar->addAction(actionDeconnexion);

        retranslateUi(MainWindow);
        QObject::connect(pushButtonConnexion, SIGNAL(clicked()), actionConnexion, SLOT(trigger()));
        QObject::connect(pushButtonDeconnexion, SIGNAL(clicked()), actionDeconnexion, SLOT(trigger()));
        QObject::connect(pushButtonQuitter, SIGNAL(clicked()), actionQuitter, SLOT(trigger()));
        QObject::connect(pushButtonEnvoyerScript, SIGNAL(clicked()), actionEnvoyerScript, SLOT(trigger()));
        QObject::connect(pushButtonOuvrir, SIGNAL(clicked()), actionOuvrir, SLOT(trigger()));
        QObject::connect(pushButtonArreterProgramme, SIGNAL(clicked()), actionArreter_Programme, SLOT(trigger()));
        QObject::connect(pushButtonPositionDepart, SIGNAL(clicked()), actionPositionDepart, SLOT(trigger()));
        QObject::connect(pushButtonOuvrirXML, SIGNAL(clicked()), actionOuvrirXML, SLOT(trigger()));
        QObject::connect(pushButtonPreview, SIGNAL(clicked()), actionPreview, SLOT(trigger()));
        QObject::connect(pushButtonGenerate, SIGNAL(clicked()), actionGenererScript, SLOT(trigger()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Client TCP UR5", 0));
        actionConnexion->setText(QApplication::translate("MainWindow", "Connexion", 0));
        actionConnexion->setShortcut(QApplication::translate("MainWindow", "Alt+C", 0));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0));
#ifndef QT_NO_TOOLTIP
        actionQuitter->setToolTip(QApplication::translate("MainWindow", "Quitter", 0));
#endif // QT_NO_TOOLTIP
        actionQuitter->setShortcut(QApplication::translate("MainWindow", "Alt+Q", 0));
        actionDeconnexion->setText(QApplication::translate("MainWindow", "D\303\251connexion", 0));
        actionDeconnexion->setShortcut(QApplication::translate("MainWindow", "Alt+D", 0));
        actionOuvrir->setText(QApplication::translate("MainWindow", "Ouvrir un fichier URScript...", 0));
        actionOuvrir->setShortcut(QApplication::translate("MainWindow", "Alt+O", 0));
        actionEnvoyerScript->setText(QApplication::translate("MainWindow", "Envoyer URScript", 0));
        actionEnvoyerScript->setShortcut(QApplication::translate("MainWindow", "Alt+E", 0));
        actionArreter_Programme->setText(QApplication::translate("MainWindow", "Arr\303\252ter l'URScript", 0));
        actionArreter_Programme->setShortcut(QApplication::translate("MainWindow", "Alt+S", 0));
        actionOuvrirXML->setText(QApplication::translate("MainWindow", "Ouvrir un fichier XML...", 0));
        actionOuvrirXML->setShortcut(QApplication::translate("MainWindow", "Alt+X", 0));
        actionGenererScript->setText(QApplication::translate("MainWindow", "G\303\251n\303\251rer le script", 0));
#ifndef QT_NO_TOOLTIP
        actionGenererScript->setToolTip(QApplication::translate("MainWindow", "G\303\251n\303\251rer le script \303\240 envoyer au robot", 0));
#endif // QT_NO_TOOLTIP
        actionGenererScript->setShortcut(QApplication::translate("MainWindow", "Alt+G", 0));
        actionPreview->setText(QApplication::translate("MainWindow", "Pr\303\251visualiser", 0));
        actionPreview->setShortcut(QApplication::translate("MainWindow", "Alt+V", 0));
        actionPositionDepart->setText(QApplication::translate("MainWindow", "Position de d\303\251part du robot", 0));
        actionPositionDepart->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0));
        groupBoxConnexion->setTitle(QApplication::translate("MainWindow", "Connexion au bras UR5", 0));
        labelStatut->setText(QApplication::translate("MainWindow", "Statut connexion : ", 0));
        labelStatutActuel->setText(QApplication::translate("MainWindow", "<em>Non connect\303\251</em>", 0));
        pushButtonDeconnexion->setText(QApplication::translate("MainWindow", "D\303\251connexion", 0));
        pushButtonConnexion->setText(QApplication::translate("MainWindow", "Connexion", 0));
        groupBoxProgramme->setTitle(QApplication::translate("MainWindow", "Editeur de script", 0));
        labelProgramFileName->setText(QApplication::translate("MainWindow", "Aucun fichier URScript ouvert.", 0));
        pushButtonOuvrir->setText(QApplication::translate("MainWindow", "Ouvrir un fichier URScript... (ALT+O)", 0));
        pushButtonEnvoyerScript->setText(QApplication::translate("MainWindow", "Envoyer URScript (ALT+E)", 0));
        pushButtonPositionDepart->setText(QApplication::translate("MainWindow", "Position de d\303\251part du robot (CTRL+D)", 0));
        pushButtonArreterProgramme->setText(QApplication::translate("MainWindow", "Arr\303\252ter l'URScript (ALT+S)", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Editeur URScript", 0));
        groupBoxFontXML->setTitle(QApplication::translate("MainWindow", "Police de caract\303\250res", 0));
        labelXMLFileName->setText(QApplication::translate("MainWindow", "Aucun fichier XML ouvert", 0));
        labelFontName->setText(QApplication::translate("MainWindow", "Aucune police de caract\303\250re active", 0));
        pushButtonOuvrirXML->setText(QApplication::translate("MainWindow", "Ouvrir un fichier XML... (ALT+X)", 0));
        groupBoxTextEditor->setTitle(QApplication::translate("MainWindow", "\303\211diteur de texte", 0));
        lineEditText->setInputMask(QString());
        pushButtonGenerate->setText(QApplication::translate("MainWindow", "G\303\251n\303\251rer URScript (ALT+G)", 0));
        pushButtonPreview->setText(QApplication::translate("MainWindow", "Pr\303\251visualisation courbes de B\303\251zier (ALT+V)", 0));
        labelText->setText(QApplication::translate("MainWindow", "Veuillez entrer le message \303\240 \303\251crire :", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Edition de texte", 0));
        pushButtonQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0));
        groupBoxConsole->setTitle(QString());
        textEditLogs->setDocumentTitle(QString());
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
        menuProgramme->setTitle(QApplication::translate("MainWindow", "URScript", 0));
        menuPolice->setTitle(QApplication::translate("MainWindow", "\303\211dition de texte", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
