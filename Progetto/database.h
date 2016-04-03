#ifndef DATABASE_H
#define DATABASE_H

#include "utenteexecutive.h"
#include <typeinfo>
#include <QFile>
#include <QTextStream>

class DataBase{

    public:
        QList<Utente*> rete;                             // lista di puntatori alla classe utente

        ~DataBase();
        Utente* trovaUsername(QString) const;
        Utente* trovaNomeCognome(QString,QString) const;
        void carica();
        void salva();
        bool aggiungi(Utente*);
        void rimuovi(Utente*);
        QStringList getListaUtenti() const;

};//DataBase

#endif // DATABASE_H
