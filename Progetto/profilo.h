#ifndef PROFILO_H
#define PROFILO_H

#include <QString>
#include <QStringList>
#include <QDate>

class Profilo{

    public:
        QString nome;
        QString cognome;
        QString residenza;
        QDate dataNascita;
        QString professione;
        QString titoloStudio;
        QStringList esperienze;
        QStringList competenze;
        QStringList lingue;

        Profilo();

};//profilo

#endif // PROFILO_H
