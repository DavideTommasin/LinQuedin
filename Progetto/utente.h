#ifndef UTENTE_H
#define UTENTE_H

#include "profilo.h"
#include <QList>

class Utente{

    private:
        QString username;
        Profilo pf;
        QStringList contatti;

    public:
        Utente(QString);
        virtual ~Utente();

        QString getUsername() const;
        QString getNome() const;
        QString getCognome() const;
        QString getResidenza() const;
        QDate getDataNascita() const;
        QString getProfessione() const;
        QString getTitoloStudio() const;
        QStringList getEsperienze() const;
        QStringList getCompetenze() const;
        QStringList getLingue() const;
        QStringList getListaContatti() const;
        bool cercaContatto(QString) const;
        void setNome(QString);
        void setCognome(QString);
        void setResidenza(QString);
        void setDataNascita(QDate);
        void setProfessione(QString);
        void setTitoloStudio(QString);
        void aggiungiEsperienza(QString);
        void rimuoviEsperienza(QString);
        void aggiungiCompetenza(QString);
        void rimuoviCompetenza(QString);
        void aggiungiLingua(QString);
        void rimuoviLingua(QString);
        bool aggiungiContatto(QString);
        void rimuoviContatto(QString);

        virtual void stampaInfo(bool&,bool&) = 0; // metodo di permesso virtuale puro, le sue implementazioni stabiliranno cosa un utente potrà visualizzare in base alla tipologia di account

};//Utente

#endif // UTENTE_H
