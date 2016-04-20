#ifndef BZVIEW_H
#define BZVIEW_H

#include <QWidget>

#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QPainterPath>
#include <QMouseEvent>
#include <QLabel>

class UR5Console;

class BzView : public QWidget
{
    Q_OBJECT
    UR5Console  *parent;
public:
    explicit BzView(QWidget *parent = 0);
    ~BzView();
    void setMainWindow(UR5Console* Parent) { parent = Parent; }

    void    paintEvent(QPaintEvent *evt);
    void    mousePressEvent(QMouseEvent *evt);
    void    mouseMoveEvent(QMouseEvent *evt);

    QLabel  *LabelPos;
    QPoint  mousePos;
    QFont   mousePosFont;

    // Taille et largeur des points de contrôle
    enum    {   PTSIZE=9, PTWIDTH=5    };

signals:

public slots:

};

#endif // BZVIEW_H
