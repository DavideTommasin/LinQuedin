#include "client.h"

Client::Client(QString s, DataBase * d){

    db = d;
    utenteLoggato = db->trovaUsername(s);
    utenteSelezionato = 0;
    stampaProfilo = false;
    stampaProfiloCompleto = false;

}//Client


void Client::modificaProfiloUtente(QDate d,int campo){

    switch(campo){
    case 1:
        utenteLoggato->setDataNascita(d);
    }//switch

}//modificaProfiloUtente

void Client::modificaProfiloUtente(QString s, int campo){

    switch(campo){
    case 1:
        utenteLoggato->setNome(s);
        break;
    case 2:
        utenteLoggato->setCognome(s);
        break;
    case 3:
        utenteLoggato->setResidenza(s);
        break;
    case 4:
        utenteLoggato->setTitoloStudio(s);
        break;
    case 5:
        utenteLoggato->setProfessione(s);
        break;
    case 6:
        utenteLoggato->aggiungiEsperienza(s);
        break;
    case 7:
        utenteLoggato->rimuoviEsperienza(s);
        break;
    case 8:
        utenteLoggato->aggiungiCompetenza(s);
        break;
    case 9:
        utenteLoggato->rimuoviCompetenza(s);
        break;
    case 10:
        utenteLoggato->aggiungiLingua(s);
        break;
    case 11:
        utenteLoggato->rimuoviLingua(s);
        break;
    }//switch

}//modificaProfiloUtente

void Client::salva(){

    db->salva();

}//salva

void Client::cercaUtenteUsername(QString un){

    utenteSelezionato = db->trovaUsername(un);

}//cercaUtenteUsername

void Client::cercaUtenteNomeCognome(QString n, QString c){

    utenteSelezionato = db->trovaNomeCognome(n,c);

}//cercaUtenteNomeCognome

bool Client::aggiungiUtenteSelezionato(){

    return utenteLoggato->aggiungiContatto(utenteSelezionato->getUsername());

}//aggiungiUtenteSelezionato

void Client::rimuoviUtenteSelezionato(){

    utenteLoggato->rimuoviContatto(utenteSelezionato->getUsername());
    utenteSelezionato=0;

}//rimuoviUtenteSelezionato

bool Client::cercaContatto(QString x){

    if(!utenteLoggato->cercaContatto(x)){
        utenteSelezionato = 0;
        return false;
    }//if
    else{
        cercaUtenteUsername(x);
        if(utenteSelezionato==0)
            utenteLoggato->rimuoviContatto(x);
        return true;
    }//else

}//cercaContatto

void Client::stampaInfoCercato(){

    utenteLoggato->stampaInfo(stampaProfilo,stampaProfiloCompleto);

}//stampaInfoCercato
