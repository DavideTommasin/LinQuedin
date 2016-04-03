#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include <QListWidget>
#include <QGroupBox>
#include <QLineEdit>
#include <QDateEdit>
#include "client.h"
#include "database.h"
#include "profilowidget.h"
#include "profiloretewidget.h"

class ClientWidget : public QWidget{

    Q_OBJECT

    public:
        explicit ClientWidget(QString,DataBase*,QWidget *parent = 0);
        ~ClientWidget();

    private:
        Client* LogicClient;

        QLabel* NomeLabel;
        QLabel* CognomeLabel;
        QLabel* ResidenzaLabel;
        QLabel* TitoloDiStudioLabel;
        QLabel* ProfessioneLabel;
        QLabel* DataNascitaLabel;
        QLabel* EsperienzeLabel;
        QLabel* CompetenzeLabel;
        QLabel* LingueLabel;
        QListWidget* EsperienzeList;
        QListWidget* CompetenzeList;
        QListWidget* LingueList;
        QListWidget* ContattiList;

        QLineEdit* NomeEdit;
        QLineEdit* CognomeEdit;
        QLineEdit* ResidenzaEdit;
        QLineEdit* TitoloDiStudioEdit;
        QLineEdit* ProfessioneEdit;
        QDateEdit* DataNascitaEdit;
        QLineEdit* EsperienzaEdit;
        QLineEdit* CompetenzaEdit;
        QLineEdit* LinguaEdit;
        QLineEdit* cercaUtenteUsernameEdit;
        QLineEdit* cercaUtenteNomeEdit;
        QLineEdit* cercaUtenteCognomeEdit;
        QLineEdit* cercaContattoEdit;

        QLabel* modificaMessageLabel;                   // campo che mostra informazioni relative alle operazioni di modifica effettuate dal'utente
        QLabel* ricercaMessageLabel;                    // campo che mostra informazioni relative alle operazioni di ricerca effettuate dall'utente
        QLabel* contattiLabel;                          // campo che mostra informazioni relatice alle operazioni sui contatti
        QLabel* selezionatoLabel;                       // campo che mostra l'utente selezionato

        QPushButton* modificaButton;
        QPushButton* logoutButton;
        QPushButton* aggiungiButton;                    // pulsante che aggiunge un utente alla propria rete
        QPushButton* rimuoviButton;                     // pulsante che rimuove un utente dalla propria rete
        QPushButton* visualizzaContattoButton;          // visualizzazione del profilo di un proprio contatto
        QPushButton* visualizzaCercatoButton;           // visualizzazione del profilo di un utente cercato
        QPushButton* visualizzaCercatoCompletoButton;   // visualizzazione del profilo e della rete contatti di un utente cercato

        QGroupBox* visualizzaBox;                       // contenitore dei campi di visualizzazione
        QGroupBox* reteBox;                             // contenitore dei campi relativi ai contatti
        QGroupBox* modificaBox;                         // contenitore dei campi di modifica
        QGroupBox* ricercaBox;                          // contenitore dei campi di ricerca

        QVBoxLayout* ClientLayout;                      // layout principale
        QHBoxLayout* UtenteLayout;                      // layout di visualizzazione dell'utente loggato

        bool InizializzazioneLogica(QString,DataBase*); // inizializzazione logica del campo LogicClient
        void visualizzaProfiloInitialize();             // visualizzazione del profilo
        void visualizzaReteInitialize();                // visualizzazione rete contatti
        void modificaProfiloInitialize();               // visualizzazione di modifica profilo
        void ricercaInitialize();                       // visualizzazione dei form di ricerca utenti
        void modificaSelezionato();
        void modificaContattiList();

    signals:
        void logoutSignal();

    public slots:
        void modalitaModifica();
        void applicaModificheSlot();
        void modificheCompletateSlot();
        void aggiungiEsperienzaSlot();
        void rimuoviEsperienzaSlot();
        void aggiungiCompetenzaSlot();
        void rimuoviCompetenzaSlot();
        void aggiungiLinguaSlot();
        void rimuoviLinguaSlot();
        void salvaSlot();                               // salva le modifiche
        void cercaUsernameSlot();
        void cercaNomeCognomeSlot();
        void aggiungiContattoSlot();
        void cercaContattoSlot();
        void getContattoSlot();
        void visualizzaContattoSlot();
        void rimuoviContattoSlot();
        void visualizzaCercatoSlot();                   // visualizza il profilo dell'utente cercato
        void visualizzaCercatoCompletoSlot();           // visualizza il profilo e la rete contatti dell'utente cercato

};//ClientWidget

#endif // CLIENTWIDGET_H
