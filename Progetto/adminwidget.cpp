#include "adminwidget.h"

AdminWidget::AdminWidget(DataBase * d, QWidget *parent) : QWidget(parent) {

    InizializzazioneLogica(d);
    adminLayout = new QVBoxLayout;
    creaListaUtentiBox();
    creaAmministratoreBox();
    QHBoxLayout* windowsLayout = new QHBoxLayout;
    windowsLayout->addWidget(listaUtentiBox);
    windowsLayout->addWidget(amministratoreBox);

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    salvaButton = new QPushButton;
    salvaButton->setText("Salva ed esci");
    salvaButton->setMaximumWidth(250);
    esciButton = new QPushButton;
    esciButton->setText("Esci senza salvare");
    esciButton->setMaximumWidth(250);
    connect(salvaButton,SIGNAL(clicked()),this,SLOT(saveSlot()));
    connect(salvaButton,SIGNAL(clicked()),this,SIGNAL(indietro()));
    connect(esciButton,SIGNAL(clicked()),this,SIGNAL(indietro()));
    buttonLayout->addWidget(salvaButton);
    buttonLayout->addWidget(esciButton);
    adminLayout->addLayout(windowsLayout);
    adminLayout->addLayout(buttonLayout);
    setLayout(adminLayout);

}//AdminWidget

AdminWidget::~AdminWidget() {

    delete amministratore;

}//~AdminWidget

void AdminWidget::InizializzazioneLogica(DataBase* d){

    amministratore = new Admin(d);

}//InizializzazioneLogica

void AdminWidget::creaAmministratoreBox(){

    amministratoreBox = new QGroupBox;
    amministratoreBox->setTitle("Amministratore del database LinQedIn");
    amministratoreBox->setMinimumSize(840,480);
    QVBoxLayout* amministratoreBoxLayout = new QVBoxLayout;

    QFormLayout* boxLayout = new QFormLayout;

    QHBoxLayout* cercaLayout1 = new QHBoxLayout;
    cercaUtenteUsernameEdit = new QLineEdit;
    cercaUtenteUsernameButton = new QPushButton;
    cercaUtenteUsernameButton->setText("Cerca");
    cercaUtenteUsernameEdit->setPlaceholderText("Username");
    cercaLayout1->addWidget(cercaUtenteUsernameEdit);
    cercaLayout1->addWidget(cercaUtenteUsernameButton);

    QHBoxLayout* cercaLayout2 = new QHBoxLayout;
    cercaUtenteNomeEdit = new QLineEdit;
    cercaUtenteCognomeEdit = new QLineEdit;
    cercaUtenteNCButton = new QPushButton;
    cercaUtenteNCButton->setText("Cerca");
    cercaUtenteNomeEdit->setPlaceholderText("Nome");
    cercaUtenteCognomeEdit->setPlaceholderText("Cognome");
    cercaLayout2->addWidget(cercaUtenteNomeEdit);
    cercaLayout2->addWidget(cercaUtenteCognomeEdit);
    cercaLayout2->addWidget(cercaUtenteNCButton);

    aggiungiUtelteLabel = new QLabel;
    aggiungiUtelteLabel->setText("Aggiungi utente: ");

    aggiungiUtenteEdit = new QLineEdit;
    aggiungiUtenteEdit->setFixedSize(429,20);
    aggiungiBasicButton = new QPushButton;
    aggiungiBusinessButton = new QPushButton;
    aggiungiExecutiveButton = new QPushButton;
    aggiungiBasicButton->setText("Aggiungi Utente Basic");
    aggiungiBusinessButton->setText("Aggiungi Utente business");
    aggiungiExecutiveButton->setText("Aggiungi Utente executive");

    QFormLayout* addButtonsLayout = new QFormLayout;
    addButtonsLayout->addRow(aggiungiBasicButton);
    addButtonsLayout->addRow(aggiungiBusinessButton);
    addButtonsLayout->addRow(aggiungiExecutiveButton);

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(aggiungiUtelteLabel);
    layout->setAlignment(aggiungiUtelteLabel,Qt::AlignRight);
    layout->addWidget(aggiungiUtenteEdit);
    layout->addLayout(addButtonsLayout);

    messaggiLabel = new QLabel;
    messaggiLabel->setText("");
    messaggiLabel->setAlignment(Qt::AlignCenter);

    connect(aggiungiBasicButton,SIGNAL(clicked()),this,SLOT(aggiungiBasicSlot()));
    connect(aggiungiBusinessButton,SIGNAL(clicked()),this,SLOT(aggiungiBusinessSlot()));
    connect(aggiungiExecutiveButton,SIGNAL(clicked()),this,SLOT(aggiungiExecutiveSlot()));
    connect(cercaUtenteUsernameButton,SIGNAL(clicked()),this,SLOT(cercaUsernameSlot()));
    connect(cercaUtenteNCButton,SIGNAL(clicked()),this,SLOT(cercaNomeCognomeSlot()));

    QHBoxLayout* selezionatoLayout = new QHBoxLayout;
    utenteSelezionatoLabel = new QLabel;
    utenteSelezionatoLabel->setText("Nessun Utente Selezionato");
    selezionatoLayout->addWidget(utenteSelezionatoLabel);

    rimuoviUtenteButton = new QPushButton;
    rimuoviUtenteButton->setText("Rimuovi l'Utente Selezionato");
    connect(rimuoviUtenteButton,SIGNAL(clicked()),this,SLOT(rimuoviUtenteSlot()));

    visualizzaProfiloButton = new QPushButton;
    visualizzaProfiloButton->setText("Visualizza il Profilo dell'Utente Selezionato");
    connect(visualizzaProfiloButton,SIGNAL(clicked()),this,SLOT(visualizzaProfiloSlot()));

    QVBoxLayout* cambiaLayout = new QVBoxLayout;
    cambiaBasicButton = new QPushButton;
    cambiaBasicButton->setText("Basic");
    connect(cambiaBasicButton,SIGNAL(clicked()),this,SLOT(cambiaBasicSlot()));
    cambiaBusinessButton = new QPushButton;
    cambiaBusinessButton->setText("Business");
    connect(cambiaBusinessButton,SIGNAL(clicked()),this,SLOT(cambiaBusinessSlot()));
    cambiaExecutiveButton = new QPushButton;
    cambiaExecutiveButton->setText("Executive");
    connect(cambiaExecutiveButton,SIGNAL(clicked()),this,SLOT(cambiaExecutiveSlot()));
    cambiaLayout->addWidget(cambiaBasicButton);
    cambiaLayout->addWidget(cambiaBusinessButton);
    cambiaLayout->addWidget(cambiaExecutiveButton);

    boxLayout->addRow("Inserisci username:",cercaLayout1);
    boxLayout->addRow("Inserisci nome e cognome:",cercaLayout2);
    boxLayout->addRow(layout);
    boxLayout->addRow("Utente selezionato:",selezionatoLayout);
    boxLayout->addRow("Rimuovi utente:",rimuoviUtenteButton);
    boxLayout->addRow("Visualizza profilo:",visualizzaProfiloButton);
    boxLayout->addRow("Cambia tipologia di account\ndell'utente selezionato:",cambiaLayout);
    rimuoviUtenteButton->setEnabled(false);
    visualizzaProfiloButton->setEnabled(false);
    cambiaBasicButton->setEnabled(false);
    cambiaBusinessButton->setEnabled(false);
    cambiaExecutiveButton->setEnabled(false);

    amministratoreBoxLayout->addLayout(boxLayout);
    amministratoreBoxLayout->addWidget(messaggiLabel);

    amministratoreBox->setLayout(amministratoreBoxLayout);

}//creaAmministratoreBox

void AdminWidget::creaListaUtentiBox() {

    listaUtentiBox = new QGroupBox;
    listaUtentiBox->setTitle("Utenti iscritti a LinQedIn");
    listaUtentiBox->setMinimumSize(240,480);

    QVBoxLayout* listaLayout = new QVBoxLayout;

    listaUtentiList = new QListWidget;
    QStringList users = amministratore->utentiDatabase();
    listaUtentiList->addItems(users);
    listaUtentiList->sortItems();

    listaLayout->addWidget(listaUtentiList);
    listaUtentiBox->setLayout(listaLayout);

    connect(listaUtentiList,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(getUtente()));

}//creaListaUtentiBox

void AdminWidget::aggiornaUtenteSelezionato(){

    if(amministratore->selezionato==0){
        utenteSelezionatoLabel->setText("Nessun utente selezionato");
        rimuoviUtenteButton->setEnabled(false);
        visualizzaProfiloButton->setEnabled(false);
        cambiaBasicButton->setEnabled(false);
        cambiaBusinessButton->setEnabled(false);
        cambiaExecutiveButton->setEnabled(false);
    }//if
    else{
        QString x = amministratore->selezionato->getUsername();
        utenteSelezionatoLabel->setText(x);
        rimuoviUtenteButton->setEnabled(true);
        visualizzaProfiloButton->setEnabled(true);
        cambiaBasicButton->setEnabled(true);
        cambiaBusinessButton->setEnabled(true);
        cambiaExecutiveButton->setEnabled(true);
    }//else

}//aggiornaUtenteSelezionato

void AdminWidget::aggiornaListaUtenti(){

    listaUtentiList->clear();
    QStringList users = amministratore->utentiDatabase();
    listaUtentiList->addItems(users);
    listaUtentiList->sortItems();

}//aggiornaListaUtenti

void AdminWidget::saveSlot(){

    amministratore->salva();

}//saveSlot

void AdminWidget::aggiungiBasicSlot(){

    QString un = aggiungiUtenteEdit->text();
    if(un.isEmpty()){
        messaggiLabel->setText("Impossibile aggiungere l'utente: campo di testo vuoto");
    }//if
    else{
        Utente* u = new UtenteBasic(un);
        if(amministratore->aggiungiUtente(u)){
            aggiungiUtenteEdit->setText("");
            messaggiLabel->setText("Utente aggiunto con successo!");
        }//if
        else{
            delete u;
            aggiungiUtenteEdit->setText("");
            messaggiLabel->setText("Impossibile effettuare l'operazione\nL'utente e' gia' presente nel database");
        }//else
    }//else
    aggiornaListaUtenti();

}//aggiungiBasicSlot

void AdminWidget::aggiungiBusinessSlot(){

    QString un = aggiungiUtenteEdit->text();
    if(un.isEmpty()){
        messaggiLabel->setText("Impossibile aggiungere l'utente: campo di testo vuoto");
    }//if
    else{
        Utente* u = new UtenteBusiness(un);
        if(amministratore->aggiungiUtente(u)){
            aggiungiUtenteEdit->setText("");
            messaggiLabel->setText("Utente aggiunto con successo!");
        }//if
        else{
            delete u;
            aggiungiUtenteEdit->setText("");
            messaggiLabel->setText("Impossibile effettuare l'operazione\nL'utente e' gia' presente nel database");
        }//else
    }//else
    aggiornaListaUtenti();

}//aggiungiBusinessSlot

void AdminWidget::aggiungiExecutiveSlot(){

    QString un = aggiungiUtenteEdit->text();
    if(un.isEmpty()){
        messaggiLabel->setText("Impossibile aggiungere l'utente: campo di testo vuoto");
    }//if
    else{
        Utente* u = new UtenteExecutive(un);
        if(amministratore->aggiungiUtente(u)){
            aggiungiUtenteEdit->setText("");
            messaggiLabel->setText("Utente aggiunto con successo!");
        }//if
        else{
            delete u;
            aggiungiUtenteEdit->setText("");
            messaggiLabel->setText("Impossibile effettuare l'operazione\nL'utente e' gia' presente nel database");
        }//else
    }//else
    aggiornaListaUtenti();

}//aggiungiExecutiveSlot

void AdminWidget::rimuoviUtenteSlot(){

    amministratore->rimuoviUtente();
    messaggiLabel->setText("Utente rimosso con successo!");
    aggiornaUtenteSelezionato();
    aggiornaListaUtenti();

}//rimuoviUtenteSlot

void AdminWidget::cercaUsernameSlot(){

    QString x = cercaUtenteUsernameEdit->text();
    if(x.isEmpty()){
        messaggiLabel->setText("Impossibile cercare l'utente: campo di ricerca vuoto");
    }//if
    else{
        amministratore->cercaUtenteUsername(x);
        if(amministratore->selezionato==0){
            messaggiLabel->setText("L'utente cercato non è presente nel database");
            cercaUtenteUsernameEdit->setText("");
            aggiornaUtenteSelezionato();
        }//if
        else{
            messaggiLabel->setText("L'utente cercato è presente nel database");
            cercaUtenteUsernameEdit->setText("");
            aggiornaUtenteSelezionato();
        }//else
    }//else

}//cercaUsernameSlot

void AdminWidget::cercaNomeCognomeSlot(){

    QString n = cercaUtenteNomeEdit->text();
    QString c = cercaUtenteCognomeEdit->text();
    if((n.isEmpty())||(c.isEmpty())){
        messaggiLabel->setText("Impossibile cercare l'utente: campo di ricerca vuoto");
    }//if
    else{
        amministratore->cercaUtenteNomeCognome(n,c);
        if(amministratore->selezionato==0){
            messaggiLabel->setText("L'utente cercato non è presente nel database");
            cercaUtenteNomeEdit->setText("");
            cercaUtenteCognomeEdit->setText("");
            aggiornaUtenteSelezionato();
        }//if
        else{
            messaggiLabel->setText("L'utente cercato è presente nel database");
            cercaUtenteNomeEdit->setText("");
            cercaUtenteCognomeEdit->setText("");
            aggiornaUtenteSelezionato();
        }//else
    }//else

}//cercaNomeCognomeSlot

void AdminWidget::visualizzaProfiloSlot(){

    profiloReteWidget* profilo = new profiloReteWidget(amministratore->selezionato);
    profilo->show();

}//visualizzaProfiloSlot

void AdminWidget::cambiaBasicSlot(){

    amministratore->cambiaIscrizione(1);
    messaggiLabel->setText("Tipologia dell'utente selezionato cambiata in: BASIC");

}//cambiaBasicSlot

void AdminWidget::cambiaBusinessSlot(){

    amministratore->cambiaIscrizione(2);
    messaggiLabel->setText("Tipologia dell'utente selezionato cambiata in: BUSINESS");

}//cambiaBusinessSlot

void AdminWidget::cambiaExecutiveSlot(){

    amministratore->cambiaIscrizione(3);
    messaggiLabel->setText("Tipologia dell'utente selezionato cambiata in: EXECUTIVE");

}//cambiaExecutiveSlot

void AdminWidget::getUtente(){

    QString x = listaUtentiList->currentItem()->text();
    amministratore->cercaUtenteUsername(x);
    if(amministratore->selezionato==0){
        messaggiLabel->setText("L'utente cercato non è presente nel database");
        cercaUtenteUsernameEdit->setText("");
        aggiornaUtenteSelezionato();
    }//if
    else{
        messaggiLabel->setText("L'utente cercato è presente nel database");
        cercaUtenteUsernameEdit->setText("");
        aggiornaUtenteSelezionato();
    }//else

}//getUtente











