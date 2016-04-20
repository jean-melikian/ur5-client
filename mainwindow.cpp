#include "mainwindow.h"
#include "ui_mainwindow.h"



UR5Console::UR5Console(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    socket = new QTcpSocket(this);  // Initialisation du socket

    // ----------- SIGNAUX & SLOTS --------------------------------
    // -- Gestion socket<->interface
    connect(socket, SIGNAL(connected()), this, SLOT(setSocketState(SOCKETCONNECTED);));
    connect(socket, SIGNAL(disconnected()), this, SLOT(setSocketState(SOCKETDISCONNECTED);));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(erreurSocket(QAbstractSocket::SocketError)));
    // -- Gestion édition de texte<->interface
    connect(ui->lineEditText, SIGNAL(textEdited(QString)), this, SLOT(on_TextEdit(QString)));
    on_TextEdit(ui->lineEditText->text());

    // Initialisation de la matrice de QPoint contenant les points de contrôle des courbes de Bézier
    for(int i = 0; i<NBCHARMAX; i++){
        FontObj.FontChar[i].CharName = i;
        FontObj.FontChar[i].CharExists = false;
        for(int j = 0; j<NBCBMAX; j++){
            for(int k = 0; k<NBPTS; k++){
                FontObj.FontChar[i].TabCourbes[j][k].setX(0);
                FontObj.FontChar[i].TabCourbes[j][k].setY(0);
            }
        }
    }

    // ----------- WIDGETS ----------------------------------------
    // -- DOUBLESPINBOX : Vitesse du robot
    QLabel  *labelSpeed = new QLabel;
    ui->toolBar->addWidget(labelSpeed);
    labelSpeed->setText("Vitesse du robot : ");
    spinBoxSetSpeed.setValue(0.2);
    spinBoxSetSpeed.setRange(0.1, 1.0);
    spinBoxSetSpeed.setSingleStep(0.1);
    ui->toolBar->addWidget(&spinBoxSetSpeed);
    // --------------------
    // -- CHECKBOX : Affichage de la console
    ui->toolBar->addWidget(&ConsoleState);
    connect(&ConsoleState, SIGNAL(toggled(bool)), this, SLOT(on_ConsoleState(bool)));
    ConsoleState.setChecked(true);
    ConsoleState.setText("Afficher la console");
    ConsoleState.setStyleSheet("margin-left: 20px;");
    // --------------------
    // -- PreviewDlg : Prévisualisation (Parent = QDialog)
    Preview = new PreviewDlg(this);
    // ------------------------------------------------------------

    // -- Préfixes utilisés dans les messages de la console -------
    UserPrefix = "<font color='blue'><b>Utilisateur > </b></font>";
    ConsolePrefix = "<b>Console > </b>";
    ErrorPrefix = "<font color='red'><b>ERREUR > </b></font>";
    //-------------------------------------------------------------
    setSocketState(SOCKETDISCONNECTED);    // Etat par défaut du socket
    setXMLState(false);    // Etat par défaut du fichier XML

    this->adjustSize();
    this->setMinimumSize(this->width(), this->height());
    this->setMaximumSize(this->width(), this->height());
}

UR5Console::~UR5Console()
{
    delete socket;
    delete Preview;
    delete ui;
}

void UR5Console::on_actionConnexion_triggered()
{
    // Bouton connexion
    if(getSocketState() == SOCKETDISCONNECTED || getSocketState() == SOCKETABORTED)
    {
        ConnectDlg Dlg;
        if(Dlg.exec() == QDialog::Accepted)
        {
            // On désactive les connexions précédentes s'il y en a
            socket->abort();
            ServerIP = Dlg.getAdress();
            ServerPort = Dlg.getPort().toInt();

            // On se connecte au serveur avec son IP et son port
            socket->connectToHost(ServerIP, ServerPort);
            setSocketState(SOCKETTRYING);
        }
    }
    // Bouton connexion en mode "Annuler" pour avorter la tentative de connexion
    else
        setSocketState(SOCKETABORTED);
}

void UR5Console::on_actionDeconnexion_triggered()
{
    socket->disconnectFromHost();
}


void UR5Console::erreurSocket(QAbstractSocket::SocketError erreur)
{
    // Gestion d'erreur du socket
    switch(erreur)
    {
        case QAbstractSocket::HostNotFoundError:
            ui->labelStatutActuel->setText("Serveur introuvable");
            ui->textEditLogs->append(ErrorPrefix+"Le serveur n'a pas pu être trouvé. Vérifiez l'IP et le port.</em>");
            break;
        case QAbstractSocket::ConnectionRefusedError:
            ui->labelStatutActuel->setText("Connexion au serveur refusée");
            ui->textEditLogs->append(ErrorPrefix+"Le serveur a refusé la connexion. Vérifiez si le programme \"serveur\" a bien été lancé."
                                                 "Vérifiez aussi l'IP et le port.</em>");
            break;
        case QAbstractSocket::RemoteHostClosedError:ui->labelStatutActuel->setText("");
            ui->labelStatutActuel->setText("Connexion interrompue par le serveur");
            ui->textEditLogs->append(ErrorPrefix+"Le serveur a coupé la connexion.</em>");
        default:
            ui->labelStatutActuel->setText("Une erreur est survenue");
            ui->textEditLogs->append(ErrorPrefix+socket->errorString() + "</em>");
    }
    setSocketState(SOCKETDISCONNECTED);
}



void UR5Console::on_actionQuitter_triggered()
{
    close();
}

void UR5Console::on_actionOuvrirXML_triggered()
{
    // Instanciation de l'objet DOM (Document Object Model)
    QDomDocument dom;
    // On ouvre le fichier contenant les informations XML
    QFileDialog Dlg(this, "Ouvrir XML","", "Fichier XML (*.xml)" );
    if(Dlg.exec()==QDialog::Accepted)
    {
        QStringList List = Dlg.selectedFiles();
        for(int i=0; i<List.size(); i++)
        {
            QString FileName=List[0];
            QFile   xml_doc(FileName);
            // Ouverture du fichier XML
            if(!xml_doc.open(QIODevice::ReadOnly))
            {
                setXMLState(false);
                ui->labelXMLFileName->setText("Erreur à l'ouverture du fichier XML");
                ui->textEditLogs->append(ErrorPrefix+"Erreur à l'ouverture du fichier XML</em>");
                return;
            }
            setXMLState(true);
            // -----------------------------------------------------------------------------------
            // -- Débugger XML, très pratique en cas d'erreur de syntaxe dans le fichier XML
            QString errorStr;
            int errorLine;
            int errorColumn;
            if (!dom.setContent(&xml_doc, false, &errorStr, &errorLine, &errorColumn))
            {
                xml_doc.close();
                //Si l'on n'arrive pas à associer le fichier XML à l'objet DOM
                QString errLine = QString::number(errorLine);
                QString errCol = QString::number(errorColumn);
                ui->labelXMLFileName->setText("Erreur de syntaxe à la ligne "+errLine+", colonne "+errCol+": "+qPrintable(errorStr));
                ui->textEditLogs->append(ErrorPrefix+"Erreur de syntaxe à la ligne "+errLine+", colonne "+errCol+": "+qPrintable(errorStr)+"</em>");

                std::cerr << "Erreur: Erreur de syntaxe à la ligne " << errorLine << ", colonne " << errorColumn << ": "<< qPrintable(errorStr) << std::endl;
            }
            // -----------------------------------------------------------------------------------
            else
            {
                ui->labelXMLFileName->setText(QFileInfo(xml_doc).fileName()+" ouvert.");
                ui->labelXMLFileName->setText(QFileInfo(xml_doc).fileName()+" ouvert.");
                ui->textEditLogs->append(ConsolePrefix+"Le fichier <b>"+QFileInfo(xml_doc.fileName()).fileName()+"</b> a bien été ouvert.");
            }

            /* ------ PARSING DU FICHIER XML ---------------------------------------------------------------- */
            // On stocke le document entier dans un QDomElement
            QDomElement dom_element = dom.documentElement();
            // On récupère le noeud racine du document XML
            QDomNode node = dom_element.firstChild();

            ui->comboBoxChar->setEnabled(true);

            FontObj.NbCaracteres = 0;

            // On parcourt le noeud racine pour trouver tous les autres noeuds fils
            while(!node.isNull())
            {

                // On utilise cette propriété afin de transformer le noeud en éléments.
                // Cela nous permet aussi de récupérer l'élément ou noeud courant :
                dom_element = node.toElement();

                if(!dom_element.isNull())
                {
                    // -- Récupération du nom de la police ----------------------------------------
                    if(dom_element.nodeName() ==  "nompolice")
                    {
                        FontObj.FontName = dom_element.attribute("fontname");
                        ui->labelFontName->setText("Police <b>"+FontObj.FontName+"</b> active");
                    }

                    // -- Récupération des caractères ---------------------------------------------
                    if(dom_element.nodeName() == "caractere")
                    {
                        int ascii = dom_element.attribute("lettre").toLatin1().at(0);
                        FontObj.FontChar[ascii].CharName = dom_element.attribute("lettre").toLatin1().at(0);

                        FontObj.FontChar[ascii].NbCourbes = QString(dom_element.attribute("nbcourbes")).toInt();

                        // -- Ajout d'un item dans la comboBox
                        ui->comboBoxChar->addItem((QString)FontObj.FontChar[ascii].CharName+
                                                  " ["+QString::number(FontObj.FontChar[ascii].NbCourbes)+" courbes de Bézier]");

                        // On accède au premier enfant du noeud
                        node = node.firstChild();
                        dom_element = node.toElement();
                        // Si on tombe sur le tag <courbe>
                        if(dom_element.tagName() == "courbe")
                        {
                            // On remplit la matrice qui va contenir nos courbes de Bézier
                            for(int j=0; j<FontObj.FontChar[ascii].NbCourbes; j++)
                            {
                                dom_element = node.toElement(); // node: QDomNode -> dom_element: QDomElement
                                for(int k=0; k<NBPTS; k++)  // Pour chaque point de contrôle de la courbe
                                {
                                    QString pointID = QString::number(k);
                                    FontObj.FontChar[ascii].TabCourbes[j][k] =  /* On récupère les attributs x,y */
                                            QPoint(QString(dom_element.attribute("x"+pointID)).toDouble(),
                                                   QString(dom_element.attribute("y"+pointID)).toDouble());
                                }
                                // On passe au tag <courbe> suivant s'il y en a un
                                if(!node.nextSibling().isNull())
                                    node = node.nextSibling();
                            }
                            FontObj.FontChar[ascii].CharExists = true;  // Mise à jour du statut du caractère
                            node = node.parentNode();    // Retour au noeud parent

                        }
                        // On va ici recaler le caractère horizontalement et calculer sa largeur
                        int Xmin=FontObj.FontChar[ascii].TabCourbes[0][0].x();
                        int Xmax=FontObj.FontChar[ascii].TabCourbes[0][3].x();
                        int Ymin=FontObj.FontChar[ascii].TabCourbes[0][0].y();
                        int Ymax=FontObj.FontChar[ascii].TabCourbes[0][3].y();
                        if(Xmin > Xmax) {int t=Xmin; Xmin=Xmax; Xmax=t;}
                        if(Ymin > Ymax) {int t=Ymin; Ymin=Ymax; Ymax=t;}
                        for(int i=0; i<FontObj.FontChar[ascii].NbCourbes; i++)
                        {
                            for(double t=0.0; t<=1.0; t+=BERNSTEINSTEP)
                            {
                                // Calcul des coordonnées du point actuel de la courbe de Bézier
                                QPointF P = Bernstein(ascii, i, t);
                                // Réajustement des coordonnées
                                if(P.x() < Xmin) Xmin = P.x();
                                if(P.x() > Xmax) Xmax = P.x();
                                if(P.y() < Ymin) Ymin = P.y();
                                if(P.y() > Ymax) Ymax = P.y();
                            }
                        }
                        //Recalage des coordonnées
                        for(int i=0; i<FontObj.FontChar[ascii].NbCourbes; i++)
                        {
                            for(int j=0; j<4; j++)
                            {
                                FontObj.FontChar[ascii].TabCourbes[i][j].setX(FontObj.FontChar[ascii].TabCourbes[i][j].x()-Xmin);
                                FontObj.FontChar[ascii].TabCourbes[i][j].setY(FontObj.FontChar[ascii].TabCourbes[i][j].y()-Ymin);
                            }
                        }
                        // Calcul de la largeur et de la hauteur du caractère par la différence de ses extrêmes horizontaux et verticaux
                        FontObj.FontChar[ascii].width =Xmax-Xmin;
                        FontObj.FontChar[ascii].height=Ymax-Ymin;
                        // On met à jour le nombre de caractères présents
                        FontObj.NbCaracteres++;
                    }
                }
                node = node.nextSibling();
            }
            // On affiche le résultat de l'opération dans la console
            ui->textEditLogs->append(ConsolePrefix+"<b>"+QString::number(FontObj.NbCaracteres)+" caractères</b> sont disponibles pour la police <b>"+FontObj.FontName+"</b>.");
        }
    }
    /* Fin */
    /* ----------------------------------------------------*/
}

void UR5Console::on_actionOuvrir_triggered()
{
    QFileDialog Dlg(this, "Ouvrir un fichier URScript", "", "URSCript (*.script)" );
    if(Dlg.exec()==QDialog::Accepted)
    {
        QString FileName = Dlg.selectedFiles()[0];
        QFile   File(FileName);
        if (File.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            ui->textEditLogs->append(ConsolePrefix+"Le fichier <b>"+QFileInfo(File.fileName()).fileName()+"</b> a bien été ouvert.");
            ui->labelProgramFileName->setText(QFileInfo(File.fileName()).fileName());
            // On insère le contenu du fichier dans le textEditProgramme
            ui->textEditProgramme->setText(File.readAll());
        }
    }
}

void UR5Console::on_actionEnvoyerScript_triggered()
{
    // Si la zone d’édition du programme n’est pas vide
    if(ui->textEditProgramme->toPlainText() != 0)
    {
        // Vérification de l’état de la connexion
        if(socket->state()==QAbstractSocket::ConnectedState)
        {
            QString T = ui->textEditProgramme->toPlainText();
            // On range la QString dans un QByteArray avant de l’envoyer…
            QByteArray Ta= T.toLatin1();
            // On envoie le msg en précisant sa taille
            if(socket->write(Ta.data(), Ta.size()) != -1)
                ui->textEditLogs->append(ConsolePrefix+"L'envoi du programme est un succès.</em>");
            else
                ui->textEditLogs->append(ErrorPrefix+"L'envoi du programme a échoué.</em>");
        }
    }
}

int UR5Console::getSocketState() const
{
    return SocketState;
}

// -- Méthode gérant l'IHM selon l'état du socket
void UR5Console::setSocketState(int value)
{
    SocketState = value;
    // CONNECTED, TRYING, ABORTED, DISCONNECTED
    switch(SocketState)
    {
        // Socket connecté
        case SOCKETCONNECTED:
            ui->labelStatutActuel->setText("Connexion réussie !");
            ui->textEditLogs->append(ConsolePrefix+"Connexion réussie !");

            ui->pushButtonConnexion->setText("Connexion");
            ui->pushButtonConnexion->setChecked(false);
            ui->actionConnexion->setEnabled(false);
            ui->pushButtonConnexion->setEnabled(false);

            ui->actionDeconnexion->setEnabled(true);
            ui->pushButtonDeconnexion->setEnabled(true);

            ui->actionEnvoyerScript->setEnabled(true);
            ui->pushButtonEnvoyerScript->setEnabled(true);

            ui->actionArreter_Programme->setEnabled(true);
            ui->pushButtonArreterProgramme->setEnabled(true);
            ui->actionPositionDepart->setEnabled(true);
            ui->pushButtonPositionDepart->setEnabled(true);
            break;
        // Tentative de connexion
        case SOCKETTRYING:
            ui->labelStatutActuel->setText("Tentative de connexion en cours...");
            ui->textEditLogs->append(ConsolePrefix+"Tentative de connexion...");
            /* On désactive temporairement l'action "Connexion" pour empêcher au client
            de retenter une connexion alors qu'une tentative de connexion est déjà en cours. */
            ui->actionDeconnexion->setEnabled(false);
            ui->pushButtonDeconnexion->setEnabled(false);

            ui->pushButtonConnexion->setText("Annuler");
            ui->actionConnexion->setText("Annuler");

            ui->actionEnvoyerScript->setEnabled(false);
            ui->pushButtonEnvoyerScript->setEnabled(false);

            ui->actionArreter_Programme->setEnabled(false);
            ui->pushButtonArreterProgramme->setEnabled(false);
            ui->actionPositionDepart->setEnabled(false);
            ui->pushButtonPositionDepart->setEnabled(false);
            break;
        // Socket avorté
        case SOCKETABORTED:
            socket->abort();
            ui->pushButtonConnexion->setText("Connexion");
            ui->actionConnexion->setText("Connexion");
            ui->labelStatutActuel->setText("Connexion annulée");
            ui->textEditLogs->append(ConsolePrefix+"Connexion annulée");

            ui->actionEnvoyerScript->setEnabled(false);
            ui->pushButtonEnvoyerScript->setEnabled(false);

            ui->actionArreter_Programme->setEnabled(false);
            ui->pushButtonArreterProgramme->setEnabled(false);
            ui->actionPositionDepart->setEnabled(false);
            ui->pushButtonPositionDepart->setEnabled(false);
            break;
        // Socket déconnecté
        case SOCKETDISCONNECTED:
            ui->actionConnexion->setText("Connexion");
            ui->pushButtonConnexion->setText("Connexion");

            ui->labelStatutActuel->setText("Déconnecté");
            ui->textEditLogs->append(ConsolePrefix+"Déconnecté");

            ui->actionConnexion->setEnabled(true);
            ui->pushButtonConnexion->setEnabled(true);

            ui->actionDeconnexion->setEnabled(false);
            ui->pushButtonDeconnexion->setEnabled(false);

            ui->actionEnvoyerScript->setEnabled(false);
            ui->pushButtonEnvoyerScript->setEnabled(false);

            ui->actionArreter_Programme->setEnabled(false);
            ui->pushButtonArreterProgramme->setEnabled(false);
            ui->actionPositionDepart->setEnabled(false);
            ui->pushButtonPositionDepart->setEnabled(false);
            break;
    }
}

QString UR5Console::getLineToPreview()
{
    return ui->lineEditText->text();
}

void UR5Console::setStatusMsg(QString str)
{
    ui->statusBar->showMessage(str);
}

QLabel *UR5Console::getLabel()
{
    return ui->labelStatut;
}

void UR5Console::setXMLState(bool val)
{
    // Si un fichier XML (jeu de caractères) est bien ouvert
    if(val)
    {
        ui->groupBoxTextEditor->setEnabled(true);
    }
    else
        ui->groupBoxTextEditor->setEnabled(false);
}

void UR5Console::on_TextEdit(QString str)
{
    // Si la lineEdit est vide
    if(str.isEmpty())
    {
        TextStr = ui->lineEditText->text();
        ui->labelText->setText("Veuillez entrer le message à écrire :");
        ui->pushButtonGenerate->setEnabled(false);
        ui->actionGenererScript->setEnabled(false);
        ui->pushButtonPreview->setEnabled(false);
        ui->actionPreview->setEnabled(false);
    }
    // Ou si elle n'est pas vide
    else
    {
        ui->lineEditText->setText(ui->lineEditText->text().toUpper());
        TextStr = ui->lineEditText->text();
        ui->pushButtonGenerate->setEnabled(true);
        ui->actionGenererScript->setEnabled(true);
        ui->pushButtonPreview->setEnabled(true);
        ui->actionPreview->setEnabled(true);
    }
    // Pour la mise à jour automatique de la BzView
//    ui->View->repaint();
}

void UR5Console::on_ConsoleState(bool val)
{
    if(val)
        ui->groupBoxConsole->show();
    else
        ui->groupBoxConsole->hide();
}



void UR5Console::on_actionArreter_Programme_triggered()
{
    if(socket->state()==QAbstractSocket::ConnectedState)
    {
        QString Text = "def StopProgram():\n"
                    "end\n";
        QByteArray Msg = Text.toLatin1();
        if(socket->write(Msg.data(), Msg.size()) != -1)
            ui->textEditLogs->append(ConsolePrefix+"L'envoi du message est un succès.</em>");
        else
            ui->textEditLogs->append(ErrorPrefix+"L'envoi du message a échoué. </em>");
    }
}

void UR5Console::on_actionPreview_triggered()
{
    // On affiche la boîte de dialogue de prévisualisation
    Preview->show();
}

// -- Module en cours de développement
// Ne contient que du code de test
// La hauteur de base des caractères est de 300px
// Le robot reçoit des données en mètres
// Pour obtenir des caractères de hauteur :
//    3cm (0.03m) il faut diviser par 10000
//    6cm (0.06m) il faut diviser par 5000
//    9cm (0.09m) il faut diviser par 3333
//   12cm (0.12m) il faut diviser par 2500

// En dur pour le moment
#define HDIV    5000.


void UR5Console::on_actionGenererScript_triggered()
{
    // Avant tout, l'espace de travail du robot doit être ajusté
    // Pour cela, on ajuste les Offsets ci-dessous en X et Y
    double OffsetX=-0.30;
    double OffsetY=0.0;
    if(!TextStr.isEmpty())
    {
        ui->tabWidget->setCurrentIndex(0);
        QString speed = QString::number(spinBoxSetSpeed.value());
        GenScript =
                "def Patisserie():\n"
                "set_gravity([0.0, 0.0, 9.82])\n";

        // Pour chaque caractère à générer
        for(int i=0; i<TextStr.size(); i++)
        {
            // On récupère le code ASCII du caractère
            int ascii = TextStr.at(i).toLatin1();
            // Commentaire pour l'URScript, indique la lettre sur laquelle on travaille
            GenScript += "$ "+QString::number(i)+" \"Lettre : "+TextStr.at(i).toLatin1()+"\"\n";
            // Variables utilisées par movej()
            double Dx, Dy, Dz;
            double Drx, Dry, Drz;
            QString Sx, Sy, Sz;
            QString Srx, Sry, Srz;
            for(int idcourbe=0; idcourbe<FontObj.FontChar[ascii].NbCourbes; idcourbe++)
            {
                // Calcul du tracé point par point de chaque courbe à pas de t
                for(double t=0; t<=1.0; t+=BERNSTEINSTEP)
                {
                    QPointF P = Bernstein(ascii, idcourbe, t);  // Calcul des coordonnées du point
                    P/=HDIV;    // Redimensionnement de la courbe
                    Dx = (-P.x())+OffsetX;  // Ici, on inverse la valeur de x pour corriger l'axe du robot
                    Dy = P.y()+OffsetY;
                    // On lève et rabaisse l'outil du robot entre chaque courbe de Bézier
                    if(t==0)    Dz = PENUP;     // Lorsqu'on est entre 2 courbes, on relève l'outil
                    else        Dz = PENDOWN;   // Si on trace la courbe, on rabaisse l'outil
                    Drx = RX;
                    Dry = RY;
                    Drz = RZ;
                    // Conversion des Double en QString avec la méthode statique
                    Sx = QString::number(Dx);
                    Sy = QString::number(Dy);
                    Sz = QString::number(Dz);
                    Srx = QString::number(Drx);
                    Sry = QString::number(Dry);
                    Srz = QString::number(Drz);
                    // Commande URScript générée pour le tracé d'un point sur la courbe de Bézier
                    GenScript += "movej(p["+Sx+", "+Sy+", "+Sz+", "+Srx+", "+Sry+", "+Srz+"], a=1, v="+speed+")\n";
                }
            }
            // Décalage à droite pour le caractère suivant
            // On utilise la largeur du caractère actuel pour ajuster l'offset sur l'axe horizontal
            OffsetX -= FontObj.FontChar[ascii].width/HDIV;
        }
        // Fin du texte, on remet le robot en position de départ
        GenScript +=
                "movej([0, -1.6, 0, -1.5, 0, 0], a=3.141592653589793, v="+speed+")\n"
                "end\n";
        // On met à jour la zone d'édition d'URScript
        ui->textEditProgramme->setText(GenScript);
        ui->textEditLogs->append(ConsolePrefix+"L'URScript pour le texte <b>\""+TextStr+"\"</b> a bien été généré.</em>");
    }
}




// Permet de faire revenir le robot à sa position de départ
void UR5Console::on_actionPositionDepart_triggered()
{
    if(socket->state()==QAbstractSocket::ConnectedState)
    {
        QString speed = QString::number(spinBoxSetSpeed.value());
        QString Text =
    "def Depart():\n"
        "set_gravity([0.0, 0.0, 9.82])\n"
            "movej([0, -1.6, 0, -1.5, 0, 0], a=3.141592653589793, v="+speed+")\n"
        "end\n"
    "end\n"
    ;
        ui->textEditProgramme->setText(Text);
        QByteArray Msg = Text.toLatin1();
        if(socket->write(Msg.data(), Msg.size()) != -1)
            ui->textEditLogs->append(ConsolePrefix+"L'envoi du message est un succès.</em>");
        else
            ui->textEditLogs->append(ErrorPrefix+"L'envoi du message a échoué. </em>");
    }
}

// ----------------------------------------------------------------------------------
// -- Méthode calculant les coordonnées de chaque point à pas de t, sur une courbe de Bézier
// - int C : code ASCII du caractère actuel
// - int k: Courbe de Bézier actuelle
// - double t: valeur du pas
// - Retourne un QPointF (valeurs type float)
// Notes: UR5Console correspond à la classe principale de l'application.
// FontObj est une instance de la classe représentant une police de caractères ouverte depuis un fichier XML généré par l'éditeur de caractères de mon collègue.
// La classe instanciée par FontChar appartient à la classe mentionnée précédemment.
// Un caractère pouvant être composé de plusieurs courbes de Bézier: TabCourbes[<courbe>][<points de contrôle>]
QPointF UR5Console::Bernstein(int C, int k, double t)
{
    QPointF P;
    // Pour chacun des points de contrôle
    for(int i=0; i<NBPTS; i++)
    {
            double R = 1;

            for(int j=i+1; j<NBPTS; j++)
                R*=(1-t)*j/(j-i);

            for(int j=1; j<=i; j++)
                R*=t;

            P += R*FontObj.FontChar[C].TabCourbes[k][i];
    }
    return P;
}
// ----------------------------------------------------------------------------------
