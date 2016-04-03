#ifndef ADMIN_H
#define ADMIN_H

#include "database.h"

class Admin {

    private:
        DataBase* db;

    public:
        Utente* selezionato;                            // utente selezionato dall'amministratore
        Admin(DataBase*);
        bool aggiungiUtente(Utente*);
        void rimuoviUtente();
        QStringList utentiDatabase() const;             // restituisce una lista contente gli username degli utenti
        void salva();
        void cercaUtenteNomeCognome(QString,QString);
        void cercaUtenteUsername(QString);
        void cambiaIscrizione(int);

};//Admin

#endif // ADMIN_H
