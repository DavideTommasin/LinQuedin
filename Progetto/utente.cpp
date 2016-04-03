#include "utente.h"

Utente::Utente(QString u): username(u) {}

QString Utente::getUsername() const{

    return username;

}//getUsername

QString Utente::getNome() const{

    return pf.nome;

}//getNome

QString Utente::getCognome() const{

    return pf.cognome;

}//getCognome

QString Utente::getResidenza() const{

    return pf.residenza;

}//getResidenza

QDate Utente::getDataNascita() const{

    return pf.dataNascita;

}//getDataNascita

QString Utente::getProfessione() const{

    return pf.professione;

}//getProfessione

QString Utente::getTitoloStudio() const{

    return pf.titoloStudio;

}//getTitoloStudio

QStringList Utente::getEsperienze() const{

    return pf.esperienze;

}//getEsperienze

QStringList Utente::getCompetenze() const{

    return pf.competenze;

}//getCompetenze

QStringList Utente::getLingue() const{

    return pf.lingue;

}//getLingue

QStringList Utente::getListaContatti() const{

    return contatti;

}//getListaContatti

bool Utente::cercaContatto(QString x) const{

    for(int i=0; i<contatti.size(); ++i){
        if(contatti.at(i)==x){
            return true;
        }//if
    }//for i
    return false;

}//cercaContatto

void Utente::setNome(QString n){

    pf.nome=n;

}//setNome

void Utente::setCognome(QString c){

    pf.cognome=c;

}//setCognome

void Utente::setResidenza(QString r){

    pf.residenza=r;

}//setResidenza

void Utente::setDataNascita(QDate dn){

    pf.dataNascita=dn;

}//setDataNascita

void Utente::setProfessione(QString p){

    pf.professione=p;

}//setProfessione

void Utente::setTitoloStudio(QString f){

    pf.titoloStudio=f;

}//setTitoloStudio

void Utente::aggiungiEsperienza(QString e){

    pf.esperienze.push_back(e);
    pf.esperienze.sort();

}//aggiungiEsperienza

void Utente::rimuoviEsperienza(QString e){

    pf.esperienze.removeAll(e);

}//rimuoviEsperienza

void Utente::aggiungiCompetenza(QString c){

    pf.competenze.push_back(c);
    pf.competenze.sort();

}//aggiungiCompetenza

void Utente::rimuoviCompetenza(QString c){

    pf.competenze.removeAll(c);

}//rimuoviCompetenza

void Utente::aggiungiLingua(QString l){

    pf.lingue.push_back(l);
    pf.lingue.sort();

}//aggiungiLingua

void Utente::rimuoviLingua(QString l){

    pf.lingue.removeAll(l);

}//rimuoviLingua

bool Utente::aggiungiContatto(QString u){

    QStringList x = getListaContatti();
    for(int i=0; i<x.size(); ++i){
        if(x.at(i)==u){
            return false;
        }//if
    }//for i
    contatti.append(u);
    return true;

}//aggiungiContatto

void Utente::rimuoviContatto(QString u){

    for(int i=0; i<contatti.size(); ++i){
        if(u==contatti.at(i)){
            contatti.removeAt(i);
        }//if
    }//for i

}//rimuoviContatto

Utente::~Utente(){}
