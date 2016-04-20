#ifndef FONTCLASS_H
#define FONTCLASS_H

#include <QPoint>
#include <QString>

#define NBCHARMAX 256 // Table ASCII étendue : 0->255
#define NBPTS 4         // Nombre de points de contrôle des courbes de Bézier
#define NBCBMAX 20      // Nombre de courbes max

class FontClass
{
public:
    FontClass();
    ~FontClass();

public:
    QString FontName; // Nom de la police
    int     NbCaracteres;   // Nombre de caractères de la police

    struct  s_Caractere
    {
        QChar   CharName;   // Nom du caractère (ex: 'a', 'A', '9', '!')
        int     NbCourbes;  // Nombre de courbes dans un caractère
        int     width;
        int     height;
        // Matrice contenant les points de contrôles des courbes de Bézier
        QPoint  TabCourbes[NBCBMAX][NBPTS];
        // Variable de statut du caractère
        bool    CharExists;
    };
    // Tableau de caractères de la police (NBCHARMAX = 256)
    s_Caractere FontChar[NBCHARMAX];

};

#endif // FONT_H
