#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDataStream>
#include <QIODevice>
#include <QSettings>
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QtXml>
#include <iostream>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QCheckBox>

#include "connectdlg.h"
#include "fontclass.h"
#include "bzview.h"
#include "previewdlg.h"

#define SOCKETDISCONNECTED 0
#define SOCKETTRYING 1
#define SOCKETCONNECTED 2
#define SOCKETABORTED 3

#define BERNSTEINSTEP   0.05

// Etats du feutre (valeurs pour movej() en axe z)
#define PENDOWN -0.07
#define PENUP   0.
// Valauers d'orientation de l'outil
#define RX 1.5  // En Rx
#define RY -1.  // En Ry
#define RZ -1.  // En Rz


using   namespace std;

namespace Ui {
class MainWindow;
}

class UR5Console : public QMainWindow
{
    Q_OBJECT

public:
    explicit UR5Console(QWidget *parent = 0);
    ~UR5Console();

public:
    FontClass   FontObj;    // Objet de la classe de police de caractère
    QString     GenScript;  // Script autogénéré suite à l'insertion du texte
private:
    QString ServerIP;       // IP du serveur Linux du robot
    quint16 ServerPort;     // Port
    QTcpSocket *socket;     // Socket de connexion au serveur
    int     SocketState;    // Etat du socket, permet entre autres de gérer l'UI

    // Préfixes utilisés dans les messages de la console
    QString UserPrefix;
    QString ConsolePrefix;
    QString ErrorPrefix;

    double  SpeedValue;
    QDoubleSpinBox spinBoxSetSpeed;
    QCheckBox   ConsoleState;
    PreviewDlg  *Preview;

public:
    QPointF Bernstein(int C, int k, double t);
    int  getSocketState() const;
    void setSocketState(int value);

    QString getLineToPreview();         // Récupère le texte inséré par l'utilisateur
    void    setStatusMsg(QString str);  // Utilisé par la View pour afficher la position de la souris dans la statusbar
    QLabel *getLabel();

    bool    XMLState;
    void    setXMLState(bool val);

    QString TextStr;    // On y stocke la chaine de caractère du champ lineEditText

public slots:
    void on_TextEdit(QString str);
    void on_ConsoleState(bool val);

private slots:
    void on_actionConnexion_triggered();
    void on_actionDeconnexion_triggered();
    void erreurSocket(QAbstractSocket::SocketError erreur); // Gestion d'erreur du socket

    void on_actionQuitter_triggered();
    void on_actionOuvrirXML_triggered();
    void on_actionOuvrir_triggered();
    void on_actionEnvoyerScript_triggered();
    void on_actionArreter_Programme_triggered();
    void on_actionPreview_triggered();
    void on_actionGenererScript_triggered();
    void on_actionPositionDepart_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
