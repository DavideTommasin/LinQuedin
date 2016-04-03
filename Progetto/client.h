#ifndef CLIENT_H
#define CLIENT_H

#include "utente.h"
#include "database.h"

class Client{

    public:
        DataBase* db;
        Utente* utenteLoggato;                          // utente che sta utilizzando Linqedin
        Utente* utenteSelezionato;                      // utente selezionato dall'utenteLoggato
        bool stampaProfilo;                             // visualizzazione del profilo dell'utenteSelezionato
        bool stampaProfiloCompleto;                     // visualizzazione del profilo e della rete contatti dell'utenteSelezionato

        Client(QString,DataBase*);
        void cercaUtenteNomeCognome(QString,QString);
        void cercaUtenteUsername(QString);
        void modificaProfiloUtente(QString,int);        // modifica dei campi dati dell'utenteLoggato
        void modificaProfiloUtente(QDate,int);          // modifica la data dell'utenteLoggato
        bool aggiungiUtenteSelezionato();               // aggiunge l'utenteSelezionato alla rete dell'utenteLoggato
        void rimuoviUtenteSelezionato();                // rimuove l'utenteSelezionato dalla rete dell'utenteLoggato
        bool cercaContatto(QString);
        void stampaInfoCercato();                       // visualizzazione di determinate info sull'utente cercato in base alla tipologia dell'account dell'utenteLoggato
        void salva();                                   // salva le modifiche apportate al database

};//client

#endif // CLIENT_H
