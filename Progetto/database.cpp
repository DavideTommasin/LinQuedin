#include "database.h"

DataBase::~DataBase(){

    for(int i=0; i<rete.size(); ++i){
        delete rete.at(i);
    }//for i

}//~DataBase

Utente* DataBase::trovaUsername(QString s) const{

    for(int i=0; i<rete.size(); ++i){
        if(rete.at(i)->getUsername()==s){
            return rete.at(i);
        }//if
    }//for i
    return 0;

}//trovaUsername

Utente* DataBase::trovaNomeCognome(QString n , QString c) const{

    for(int i=0; i<rete.size(); ++i){
        if((rete.at(i)->getNome()==n)&&(rete.at(i)->getCognome()==c)){
            return rete.at(i);
        }//if
    }//for i
    return 0;

}//trovaNomeCognome

void DataBase::salva(){

    QFile fileDatabase;
    fileDatabase.setFileName("database.txt");
    fileDatabase.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);
    QTextStream stream(&fileDatabase);
    for(int i=0; i<rete.size(); ++i){
        Utente* usr = rete.at(i);
        stream << "utente" << "\n";
        if(typeid(*usr)==typeid(UtenteBasic)){
            stream << "basic" << "\n";
        }//if
        else{
            if(typeid(*usr)==typeid(UtenteBusiness)){
                stream << "business" << "\n";
            }//if
            else{
                if(typeid(*usr)==typeid(UtenteExecutive)){
                    stream << "executive" << "\n";
                }//if
            }//else
        }//else
        stream << "username" << "\n" << usr->getUsername() << "\n";
        stream << "nome" << "\n" << usr->getNome() << "\n";
        stream << "cognome" << "\n" << usr->getCognome() << "\n";
        stream << "data" << "\n" << usr->getDataNascita().year() << "\n" << usr->getDataNascita().month() << "\n" << usr->getDataNascita().day() << "\n";
        stream << "residenza" << "\n" << usr->getResidenza() << "\n";
        stream << "studio" << "\n" << usr->getTitoloStudio() << "\n";
        stream << "professione" << "\n" << usr->getProfessione() << "\n";
        stream << "esperienze" << "\n";
        QStringList esp = usr->getEsperienze();
        for(int j=0; j<esp.size(); ++j){
            stream << esp.at(j) << "\n";
        }//for j
        stream << "competenze" << "\n";
        QStringList comp = usr->getCompetenze();
        for(int k=0; k<comp.size(); ++k){
            stream << comp.at(k) << "\n";
        }//for k
        stream << "lingue" << "\n";
        QStringList ling = usr->getLingue();
        for(int l=0; l<ling.size(); ++l){
            stream << ling.at(l) << "\n";
        }//for l
        stream << "contatti" << "\n";
        QStringList cont = usr->getListaContatti();
        for(int m=0; m<cont.size(); ++m){
            stream << cont.at(m) << "\n";
        }//for m
        stream << "fine" << "\n";
    }//for i

}//salva

void DataBase::carica(){

    QFile fileDatabase;
    fileDatabase.setFileName("database.txt");
    fileDatabase.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream stream(&fileDatabase);
    QString x;
        while(!stream.atEnd()){
            x = stream.readLine();
            if(x=="utente"){
                QString tipologia;
                tipologia = stream.readLine();
                x = stream.readLine();
                if(x=="username"){
                    x = stream.readLine();
                    Utente* u;
                    if(tipologia=="basic"){
                        u = new UtenteBasic(x);
                    }//if
                    else{
                        if(tipologia=="business"){
                            u = new UtenteBusiness(x);
                        }//if
                        else{
                            if(tipologia=="executive"){
                                u = new UtenteExecutive(x);
                            }//if
                        }//else
                    }//else
                    aggiungi(u);
                    x = stream.readLine();
                    if(x=="nome"){
                        x = stream.readLine();
                        u->setNome(x);
                        x = stream.readLine();
                        if(x=="cognome"){
                            x = stream.readLine();
                            u->setCognome(x);
                            x = stream.readLine();
                            if(x=="data"){
                                x = stream.readLine();
                                int y = x.toInt();
                                x = stream.readLine();
                                int m = x.toInt();
                                x = stream.readLine();
                                int d = x.toInt();
                                u->setDataNascita(QDate(y,m,d));
                                x = stream.readLine();
                                if(x=="residenza"){
                                    x = stream.readLine();
                                    u->setResidenza(x);
                                    x = stream.readLine();
                                    if(x=="studio"){
                                        x = stream.readLine();
                                        u->setTitoloStudio(x);
                                        x = stream.readLine();
                                        if(x=="professione"){
                                            x = stream.readLine();
                                            u->setProfessione(x);
                                            x = stream.readLine();
                                            if(x=="esperienze"){
                                                x = stream.readLine();
                                                while(x!="competenze"){
                                                    u->aggiungiEsperienza(x);
                                                    x = stream.readLine();
                                                }//while
                                                x = stream.readLine();
                                                while(x!="lingue"){
                                                    u->aggiungiCompetenza(x);
                                                    x = stream.readLine();
                                                }//while
                                                x = stream.readLine();
                                                while(x!="contatti"){
                                                    u->aggiungiLingua(x);
                                                    x = stream.readLine();
                                                }//while
                                                x = stream.readLine();
                                                while(x!="fine"){
                                                    u->aggiungiContatto(x);
                                                    x = stream.readLine();
                                                }//while
                                            }//if esperienze
                                        }//if professione
                                    }//if studio
                                }//if residenza
                            }//if data
                        }//if cognome
                    }//if data
                }//if username
            }//if utente
        }//while

}//carica

bool DataBase::aggiungi(Utente * u){

    for(int i=0; i<rete.size(); ++i)
        if(rete.at(i)->getUsername()==u->getUsername()){
            return false;
        }//if
    rete.append(u);
    return true;

}//aggiungi

void DataBase::rimuovi(Utente * u){

        for(int i=0; i<rete.size(); ++i){
            if(u->getUsername()==rete.at(i)->getUsername()){
                delete rete.at(i);
                rete.removeAt(i);
            }//if
        }//for i

}//rimuovi

QStringList DataBase::getListaUtenti() const{

    QStringList a;
    for(int i=0; i<rete.size(); ++i){
        a.append(rete.at(i)->getUsername());
    }//for i
    return a;

}//getListaUtenti
