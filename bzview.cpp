#include "bzview.h"
#include "mainwindow.h"

BzView::BzView(QWidget *parent) : QWidget(parent)
{
   // this->parent = (UR5Console*) parent->parent();
    this->setMouseTracking(true);
    this->setCursor(Qt::CrossCursor);
    this->setStyleSheet("border: 3px solid #000; background-color: #000;");

    LabelPos = new QLabel;
    LabelPos->setParent(this);
    mousePosFont.setPointSize(10);
    LabelPos->setFont(mousePosFont);
    LabelPos->setStyleSheet(
                "font-family: \"Tahoma\";"
                "font-size: 11px;"
                "background-color: none;"
                "border: none;"
                "color: black;"
                );
//    QVBoxLayout *layout = new QVBoxLayout;
//    layout->addWidget(LabelPos);
//    setLayout(layout);
}

BzView::~BzView()
{

}

#define SPACEFACTOR 1.2
void BzView::paintEvent(QPaintEvent *evt)
{

    evt->accept();
    // Initialisation du pinceau
    QPainter    painter(this);
    QPen        penBlue(Qt::blue, 1);
    QPen        penRed(Qt::red, 1);
    penBlue.setWidth(5);
    painter.setPen(penBlue);

    // On vérifie si le champ lineEditPreview a été rempli
    QString str = parent->getLineToPreview();
    // QPointF : Valeurs en float, utile pour la division
    QPointF ScaleOffset;
    ScaleOffset.setY(100);

    if(!str.isEmpty())
    {
        // On calcule la largeur du texte...
        int W=0;
        for(int i=0; i<str.size(); i++)
        {
            // On récupère le code ASCII du caractère
            int ascii = str.at(i).toLatin1();
            W+= parent->FontObj.FontChar[ascii].width*SPACEFACTOR;
        }
        QRect R = parent->geometry();
        R.setWidth(W*1.2);
        parent->resize(R.size());


        ScaleOffset.setX((this->geometry().width()-W)/2);
        // On parcourt tous les caractères de la chaîne str
        for(int i=0; i<str.size(); i++)
        {
            // On récupère le code ASCII du caractère
            int ascii = str.at(i).toLatin1();
            // On parcourt toutes les courbes définies pour le caractère

            for(int idcourbe = 0; idcourbe < parent->FontObj.FontChar[ascii].NbCourbes; idcourbe++)
            {
                // Calcul du décalage de la position horizontale de départ
                // pour les caractères à la position > 0 dans la chaîne de caractères
                QPoint tmpPos[NBPTS];
                for(int j=0; j<NBPTS; j++)
                {
                    tmpPos[j].setX(parent->FontObj.FontChar[ascii].TabCourbes[idcourbe][j].x()+ScaleOffset.x());
                    tmpPos[j].setY(parent->FontObj.FontChar[ascii].TabCourbes[idcourbe][j].y()+ScaleOffset.y());
                }
                QPainterPath    Path;
                Path.moveTo(tmpPos[0]);
                Path.cubicTo(tmpPos[1], tmpPos[2], tmpPos[3]);  // Calcul du tracé de la courbe de Bézier
                painter.drawPath(Path); // Dessine le tracé de la courbe de Bézier à l'écran
                painter.setPen(penRed);
                // Dessine des cercles autour des points de contrôle des courbes afin de savoir où ils sont
                for(int k=0; k<NBPTS; k++)
                {
                    painter.drawEllipse(tmpPos[k], PTSIZE, PTSIZE);
                }
                painter.setPen(penBlue);
            }
            ScaleOffset.setX(ScaleOffset.x()+parent->FontObj.FontChar[ascii].width*SPACEFACTOR);
        }
    }
    LabelPos->setGeometry(mousePos.x(), mousePos.y(), 0, 0);
    LabelPos->adjustSize();
}

void BzView::mousePressEvent(QMouseEvent *evt)
{
    if(evt->button() == Qt::LeftButton)
    {
        update();
    }
}

void BzView::mouseMoveEvent(QMouseEvent *evt)
{
    QString x;
    x = QString::number(evt->pos().x());
    QString y;
    y = QString::number(evt->pos().y());
    QString str("x("+x+") ; y("+y+")");
    parent->setStatusMsg(str);

    QString str2("x"+x+":y"+y);
    LabelPos->setText(str2);
    mousePos.setX(evt->pos().x()+10);
    mousePos.setY(evt->pos().y()-20);
    update();
}
