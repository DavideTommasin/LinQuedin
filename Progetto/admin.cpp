#include "admin.h"

Admin::Admin(DataBase * d) {

    db = d;
    selezionato = 0;

}//Admin

bool Admin::aggiungiUtente(Utente* u) {

    bool a = db->aggiungi(u);
    if(a) {
        selezionato = u;
    }//if
    else {
        selezionato = 0;
    }//else
    return a;

}//aggiungiUtente

void Admin::rimuoviUtente() {

    if(selezionato){
        db->rimuovi(selezionato);
        selezionato = 0;
    }//if

}//rimuoviUtente

QStringList Admin::utentiDatabase() const {

    return db->getListaUtenti();

}//utentiDatabase

void Admin::salva() {

    db->salva();

}//salva

void Admin::cercaUtenteNomeCognome(QString n , QString c) {

    selezionato = db->trovaNomeCognome(n,c);

}//cercaUtenteNomeCognome

void Admin::cercaUtenteUsername(QString un) {

    selezionato = db->trovaUsername(un);

}//cercaUtenteUsername

void Admin::cambiaIscrizione(int tipo) {

    Utente* nuovo;
    QStringList x;
    switch(tipo) {
    case 1:
        if(typeid(*selezionato)==typeid(UtenteBasic)){
            return;
        }//if
        nuovo = new UtenteBasic(selezionato->getUsername());
        break;
    case 2:
        if(typeid(*selezionato)==typeid(UtenteBusiness)){
            return;
        }//if
        nuovo = new UtenteBusiness(selezionato->getUsername());
        break;
    case 3:
        if(typeid(*selezionato)==typeid(UtenteExecutive)){
            return;
        }//if
        nuovo = new UtenteExecutive(selezionato->getUsername());
        break;
    }//switch
    nuovo->setNome(selezionato->getNome());
    nuovo->setCognome(selezionato->getCognome());
    nuovo->setDataNascita(selezionato->getDataNascita());
    nuovo->setResidenza(selezionato->getResidenza());
    nuovo->setTitoloStudio(selezionato->getTitoloStudio());
    nuovo->setProfessione(selezionato->getProfessione());
    x = selezionato->getEsperienze();
    for(int i=0; i<x.size(); ++i){
        nuovo->aggiungiEsperienza(x.at(i));
    }//for i
    x = selezionato->getCompetenze();
    for(int i=0; i<x.size(); ++i){
        nuovo->aggiungiCompetenza(x.at(i));
    }//for i
    x = selezionato->getLingue();
    for(int i=0; i<x.size(); ++i){
        nuovo->aggiungiLingua(x.at(i));
    }//for i
    x = selezionato->getListaContatti();
    for(int i=0; i<x.size(); ++i){
        nuovo->aggiungiContatto(x.at(i));
    }//for i
    rimuoviUtente();
    aggiungiUtente(nuovo);

}//cambiaSottoscrizione




















