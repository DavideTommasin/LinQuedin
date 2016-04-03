#ifndef ADMINWIDGET_H
#define ADMINWIDGET_H

#include <QLineEdit>
#include "admin.h"
#include "profiloretewidget.h"

class AdminWidget : public QWidget {

    Q_OBJECT

    public:
        explicit AdminWidget(DataBase*,QWidget *parent = 0);
        ~AdminWidget();

    private:
        Admin* amministratore;
        QVBoxLayout* adminLayout;               // layout principale del widget

        QGroupBox* amministratoreBox;           // widget contenente i widget che permettono all'amministratore di interagire con il database
        QGroupBox* listaUtentiBox;              // widget contenente i campi relativi alla lista di utenti
        QListWidget* listaUtentiList;
        QLineEdit* cercaUtenteUsernameEdit;
        QLineEdit* cercaUtenteNomeEdit;
        QLineEdit* cercaUtenteCognomeEdit;
        QLineEdit* aggiungiUtenteEdit;

        QPushButton* cercaUtenteUsernameButton;
        QPushButton* cercaUtenteNCButton;
        QPushButton* aggiungiBasicButton;
        QPushButton* aggiungiBusinessButton;
        QPushButton* aggiungiExecutiveButton;
        QPushButton* rimuoviUtenteButton;
        QPushButton* salvaButton;
        QPushButton* esciButton;
        QPushButton* visualizzaProfiloButton;
        QPushButton* cambiaBasicButton;
        QPushButton* cambiaBusinessButton;
        QPushButton* cambiaExecutiveButton;

        QLabel* messaggiLabel;                  // campo in cui vengono visualizzati i messagi  inerenti le azioni effettuate dall'amministratore
        QLabel* utenteSelezionatoLabel;         // tale campo mostra l'username dell'utente selezionato
        QLabel* aggiungiUtelteLabel;

        void InizializzazioneLogica(DataBase*); // inizializzazione logica del campo dati amministratore
        void creaAmministratoreBox();           // crea il widget di gestione di LinQedIn
        void creaListaUtentiBox();              // crea il widget lista di utenti
        void aggiornaUtenteSelezionato();
        void aggiornaListaUtenti();

    signals:
        void indietro();

    public slots:
        void saveSlot();
        void aggiungiBasicSlot();
        void aggiungiBusinessSlot();
        void aggiungiExecutiveSlot();
        void rimuoviUtenteSlot();
        void cercaUsernameSlot();
        void cercaNomeCognomeSlot();
        void visualizzaProfiloSlot();
        void cambiaBasicSlot();
        void cambiaBusinessSlot();
        void cambiaExecutiveSlot();
        void getUtente();

};//AdminWidget

#endif // ADMINWIDGET_H
