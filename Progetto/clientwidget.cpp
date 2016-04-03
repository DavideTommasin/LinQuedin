#include "clientwidget.h"

ClientWidget::ClientWidget(QString s, DataBase * d, QWidget *parent) : QWidget(parent){

    ClientLayout = new QVBoxLayout;
    UtenteLayout = new QHBoxLayout;
    if(InizializzazioneLogica(s,d)){

        visualizzaProfiloInitialize();
        modificaProfiloInitialize();
        visualizzaReteInitialize();
        ricercaInitialize();
        QHBoxLayout* buttonLayout = new QHBoxLayout;

        modificaButton = new QPushButton;
        modificaButton->setText("Modifica profilo");
        modificaButton->setMaximumWidth(200);
        connect(modificaButton,SIGNAL(clicked()),this,SLOT(modalitaModifica()));

        logoutButton = new QPushButton;
        logoutButton->setText("Logout");
        logoutButton->setMaximumWidth(100);
        connect(logoutButton,SIGNAL(clicked()),this,SLOT(salvaSlot()));
        connect(logoutButton,SIGNAL(clicked()),this,SIGNAL(logoutSignal()));

        buttonLayout->addWidget(modificaButton);
        buttonLayout->addWidget(logoutButton);

        ClientLayout->addLayout(UtenteLayout);
        ClientLayout->addLayout(buttonLayout);
        setLayout(ClientLayout);

        setMinimumSize(900,580);
    }//if
    else{
        QVBoxLayout* errorLayout = new QVBoxLayout;
        QGroupBox* errorGroup = new QGroupBox;
        QLabel* errorLabel = new QLabel;
        errorLabel->setText("ERRORE\nNome Utente Errato\nRieffetuare il login");
        errorLabel->setAlignment(Qt::AlignCenter);
        QPushButton* errorButton = new QPushButton;
        errorButton->setText("Indietro");
        errorButton->setMaximumWidth(100);
        errorLayout->addWidget(errorLabel);
        errorLayout->addWidget(errorButton);
        errorLayout->setAlignment(errorButton,Qt::AlignCenter);
        errorGroup->setLayout(errorLayout);
        errorGroup->setFixedSize(400,115);

        QVBoxLayout* layout = new QVBoxLayout;
        layout->addWidget(errorGroup);
        layout->setAlignment(errorGroup,Qt::AlignCenter);
        setLayout(layout);

        connect(errorButton,SIGNAL(clicked()),this,SIGNAL(logoutSignal()));
    }//else

}//ClientWidget

ClientWidget::~ClientWidget(){

    delete LogicClient;

}//~ClientWidget

bool ClientWidget::InizializzazioneLogica(QString s, DataBase * d){

    LogicClient = new Client(s,d);
    if(LogicClient->utenteLoggato){
        return true;
    }//if
    else{
        delete LogicClient;
        return false;
    }//else

}//InizializzazioneLogica

void ClientWidget::visualizzaProfiloInitialize(){

    visualizzaBox = new QGroupBox;
    QString intro("Utente: ");
    intro.append(LogicClient->utenteLoggato->getUsername());
    visualizzaBox->setTitle(intro);

    NomeLabel = new QLabel;
    CognomeLabel = new QLabel;
    ResidenzaLabel = new QLabel;
    TitoloDiStudioLabel = new QLabel;
    ProfessioneLabel = new QLabel;
    DataNascitaLabel = new QLabel;
    EsperienzeLabel = new QLabel;
    CompetenzeLabel = new QLabel;
    LingueLabel = new QLabel;
    EsperienzeList = new QListWidget;
    CompetenzeList = new QListWidget;
    LingueList = new QListWidget;

    NomeLabel->setText(LogicClient->utenteLoggato->getNome());
    CognomeLabel->setText(LogicClient->utenteLoggato->getCognome());
    ResidenzaLabel->setText(LogicClient->utenteLoggato->getResidenza());
    TitoloDiStudioLabel->setText(LogicClient->utenteLoggato->getTitoloStudio());
    ProfessioneLabel->setText(LogicClient->utenteLoggato->getProfessione());
    DataNascitaLabel->setText(LogicClient->utenteLoggato->getDataNascita().toString());
    EsperienzeLabel->setText("Esperienze:");
    CompetenzeLabel->setText("Competenze:");
    LingueLabel->setText("Lingue:");
    QStringList x = LogicClient->utenteLoggato->getEsperienze();
    EsperienzeList->addItems(x);
    x = LogicClient->utenteLoggato->getCompetenze();
    CompetenzeList->addItems(x);
    x = LogicClient->utenteLoggato->getLingue();
    LingueList->addItems(x);
    EsperienzeList->setFixedSize(200,115);
    CompetenzeList->setFixedSize(200,115);
    LingueList->setFixedSize(150,115);

    QFormLayout* flayout = new QFormLayout;
    flayout->setSpacing(30);
    flayout->addRow("Nome: ",NomeLabel);
    flayout->addRow("Cognome: ",CognomeLabel);
    flayout->addRow("Data di nascita: ",DataNascitaLabel);
    flayout->addRow("Professione: ",ProfessioneLabel);
    flayout->addRow("Titolo di studio: ",TitoloDiStudioLabel);
    flayout->addRow("Residenza: ",ResidenzaLabel);
    QFormLayout* flayout2 = new QFormLayout;
    flayout2->addWidget(EsperienzeLabel);
    flayout2->addWidget(EsperienzeList);
    QFormLayout* flayout3 = new QFormLayout;
    flayout3->addWidget(CompetenzeLabel);
    flayout3->addWidget(CompetenzeList);
    QFormLayout* flayout4 = new QFormLayout;
    flayout4->addWidget(LingueLabel);
    flayout4->addWidget(LingueList);

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addLayout(flayout);
    layout->addLayout(flayout2);
    layout->addLayout(flayout3);
    layout->addLayout(flayout4);

    visualizzaBox->setLayout(layout);
    ClientLayout->addWidget(visualizzaBox);

}//visualizzaProfiloInitialize

void ClientWidget::visualizzaReteInitialize(){

    QVBoxLayout* vlayout = new QVBoxLayout;

    reteBox = new QGroupBox;
    reteBox->setTitle("Rete contatti dell'utente:");
    ContattiList = new QListWidget;
    QStringList c = LogicClient->utenteLoggato->getListaContatti();
    ContattiList->addItems(c);
    cercaContattoEdit = new QLineEdit;
    QPushButton* cercaContattoButton = new QPushButton;
    cercaContattoButton->setText("Cerca contatto");
    contattiLabel = new QLabel;
    contattiLabel->setText("");
    contattiLabel->setAlignment(Qt::AlignCenter);
    visualizzaContattoButton = new QPushButton;
    visualizzaContattoButton->setText("Visualizza profilo contatto");
    rimuoviButton = new QPushButton;
    rimuoviButton->setText("Rimuovi contatto");

    connect(rimuoviButton,SIGNAL(clicked()),this,SLOT(rimuoviContattoSlot()));
    connect(cercaContattoButton,SIGNAL(clicked()),this,SLOT(cercaContattoSlot()));
    connect(visualizzaContattoButton,SIGNAL(clicked()),this,SLOT(visualizzaContattoSlot()));
    connect(ContattiList,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(getContattoSlot()));

    vlayout->addWidget(ContattiList);
    vlayout->addWidget(cercaContattoEdit);
    vlayout->addWidget(cercaContattoButton);
    vlayout->addWidget(contattiLabel);
    vlayout->addWidget(visualizzaContattoButton);
    vlayout->addWidget(rimuoviButton);
    contattiLabel->hide();
    visualizzaContattoButton->hide();
    rimuoviButton->hide();
    reteBox->setLayout(vlayout);
    reteBox->setFixedSize(350,205);
    UtenteLayout->addWidget(reteBox);

}//visualizzaReteInitialize

void ClientWidget::modificaProfiloInitialize(){

    NomeEdit = new QLineEdit;
    CognomeEdit = new QLineEdit;
    ResidenzaEdit = new QLineEdit;
    TitoloDiStudioEdit = new QLineEdit;
    ProfessioneEdit = new QLineEdit;
    DataNascitaEdit = new QDateEdit;
    EsperienzaEdit = new QLineEdit;
    CompetenzaEdit = new QLineEdit;
    LinguaEdit = new QLineEdit;

    NomeEdit->setFixedSize(150,20);
    CognomeEdit->setFixedSize(150,20);
    ResidenzaEdit->setFixedSize(150,20);
    TitoloDiStudioEdit->setFixedSize(150,20);
    ProfessioneEdit->setFixedSize(150,20);
    DataNascitaEdit->setFixedSize(150,20);

    EsperienzaEdit->setFixedSize(400,20);
    CompetenzaEdit->setFixedSize(400,20);
    LinguaEdit->setFixedSize(400,20);

    QVBoxLayout* vlayout = new QVBoxLayout;
    QFormLayout* flayout = new QFormLayout;
    flayout->addRow("Nome: ",NomeEdit);
    flayout->addRow("Cognome: ",CognomeEdit);
    flayout->addRow("Data di nascita: ",DataNascitaEdit);
    flayout->addRow("Residenza: ",ResidenzaEdit);
    flayout->addRow("Titolo di studio: ",TitoloDiStudioEdit);
    flayout->addRow("Professione: ",ProfessioneEdit);

    QHBoxLayout* buttonLayout[3];
    buttonLayout[0] = new QHBoxLayout;
    buttonLayout[1] = new QHBoxLayout;
    buttonLayout[2] = new QHBoxLayout;

    QPushButton* addButton[3];
    QPushButton* removeButton[3];
    for(int i=0; i<3; i++){
        addButton[i] = new QPushButton;
        addButton[i]->setText("Aggiungi");
        addButton[i]->setFixedSize(112,23);
        removeButton[i] = new QPushButton;
        removeButton[i]->setText("Rimuovi");
        removeButton[i]->setFixedSize(112,23);
        buttonLayout[i]->addWidget(addButton[i]);
        buttonLayout[i]->addWidget(removeButton[i]);
        buttonLayout[i]->setAlignment(Qt::AlignRight);
    }//for i

    connect(addButton[0],SIGNAL(clicked()),this,SLOT(aggiungiEsperienzaSlot()));
    connect(removeButton[0],SIGNAL(clicked()),this,SLOT(rimuoviEsperienzaSlot()));
    connect(addButton[1],SIGNAL(clicked()),this,SLOT(aggiungiCompetenzaSlot()));
    connect(removeButton[1],SIGNAL(clicked()),this,SLOT(rimuoviCompetenzaSlot()));
    connect(addButton[2],SIGNAL(clicked()),this,SLOT(aggiungiLinguaSlot()));
    connect(removeButton[2],SIGNAL(clicked()),this,SLOT(rimuoviLinguaSlot()));

    QFormLayout* flayout2 = new QFormLayout;
    flayout2->addRow("Esperienza:",EsperienzaEdit);
    flayout2->addRow(buttonLayout[0]);
    flayout2->addRow("Competenza:",CompetenzaEdit);
    flayout2->addRow(buttonLayout[1]);
    flayout2->addRow("Lingua:",LinguaEdit);
    flayout2->addRow(buttonLayout[2]);

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addLayout(flayout);
    layout->addLayout(flayout2);

    modificaMessageLabel = new QLabel;
    modificaMessageLabel->setText("");
    modificaMessageLabel->setAlignment(Qt::AlignCenter);

    QPushButton* applicaModificheButton = new QPushButton;
    applicaModificheButton->setText("Applica Modifiche");
    connect(applicaModificheButton,SIGNAL(clicked()),this,SLOT(applicaModificheSlot()));

    QPushButton* modificheCompletateButton = new QPushButton;
    modificheCompletateButton->setText("Modifiche Completate");
    connect(modificheCompletateButton,SIGNAL(clicked()),this,SLOT(modificheCompletateSlot()));

    vlayout->addLayout(layout);
    vlayout->addWidget(modificaMessageLabel);
    vlayout->addWidget(applicaModificheButton);
    vlayout->addWidget(modificheCompletateButton);

    modificaBox = new QGroupBox;
    modificaBox->setLayout(vlayout);
    modificaBox->setTitle("Modifica del profilo");

    ClientLayout->insertWidget(0,modificaBox);
    modificaBox->hide();

}//visualizzaReteInitialize

void ClientWidget::ricercaInitialize(){

    ricercaBox = new QGroupBox;
    cercaUtenteUsernameEdit = new QLineEdit;
    cercaUtenteNomeEdit = new QLineEdit;
    cercaUtenteCognomeEdit = new QLineEdit;

    cercaUtenteUsernameEdit->setPlaceholderText("Username");
    cercaUtenteNomeEdit->setPlaceholderText("Nome");
    cercaUtenteCognomeEdit->setPlaceholderText("Cognome");
    QPushButton* cerca1 = new QPushButton;
    cerca1->setText("Cerca"); cerca1->setMaximumWidth(200);
    QPushButton* cerca2 = new QPushButton;
    cerca2->setText("Cerca"); cerca2->setMaximumWidth(200);
    aggiungiButton = new QPushButton;
    aggiungiButton->setText("Aggiungi l'utente alla rete");
    visualizzaCercatoButton = new QPushButton;
    visualizzaCercatoButton->setText("Visualizza profilo");
    visualizzaCercatoCompletoButton = new QPushButton;
    visualizzaCercatoCompletoButton->setText("Visualizza profilo");

    connect(visualizzaCercatoButton,SIGNAL(clicked()),this,SLOT(visualizzaCercatoSlot()));
    connect(visualizzaCercatoCompletoButton,SIGNAL(clicked()),this,SLOT(visualizzaCercatoCompletoSlot()));
    connect(aggiungiButton,SIGNAL(clicked()),this,SLOT(aggiungiContattoSlot()));
    connect(cerca1,SIGNAL(clicked()),this,SLOT(cercaUsernameSlot()));
    connect(cerca2,SIGNAL(clicked()),this,SLOT(cercaNomeCognomeSlot()));

    selezionatoLabel = new QLabel;
    selezionatoLabel->setText("Nessun utente selezionato");

    QHBoxLayout* layout1 = new QHBoxLayout;
    QHBoxLayout* layout2 = new QHBoxLayout;
    QHBoxLayout* layout3 = new QHBoxLayout;

    layout1->addWidget(cercaUtenteUsernameEdit);
    layout1->addWidget(cerca1);
    layout2->addWidget(cercaUtenteNomeEdit);
    layout2->addWidget(cercaUtenteCognomeEdit);
    layout2->addWidget(cerca2);
    layout3->addWidget(selezionatoLabel);
    layout3->addWidget(visualizzaCercatoButton);
    layout3->addWidget(visualizzaCercatoCompletoButton);
    layout3->addWidget(aggiungiButton);
    visualizzaCercatoButton->hide();
    visualizzaCercatoCompletoButton->hide();
    aggiungiButton->hide();

    QFormLayout* ricercaLayout = new QFormLayout;

    ricercaMessageLabel = new QLabel;
    ricercaMessageLabel->setText("");
    ricercaMessageLabel->setAlignment(Qt::AlignCenter);

    ricercaLayout->addRow("Inserisci username:",layout1);
    ricercaLayout->addRow("Inseriscsi nome e cognome:",layout2);
    ricercaLayout->addRow("Utente selezionato:",layout3);

    QVBoxLayout* vlayout = new QVBoxLayout;
    vlayout->addLayout(ricercaLayout);
    vlayout->addWidget(ricercaMessageLabel);

    ricercaBox->setLayout(vlayout);
    ricercaBox->setTitle("Ricerca di utenti in LinQedIn:");
    UtenteLayout->addWidget(ricercaBox);

}//ricercaInitialize

void ClientWidget::modificaSelezionato(){

    if(LogicClient->utenteSelezionato==0){
        selezionatoLabel->setText("Nessun utente selezionato");
        aggiungiButton->hide();
        visualizzaCercatoButton->hide();
        visualizzaCercatoCompletoButton->hide();
    }//if
    else{
        QString x = LogicClient->utenteSelezionato->getUsername();
        selezionatoLabel->setText(x);
    }//else

}//modificaSelezionato

void ClientWidget::modificaContattiList(){

    ContattiList->clear();
    QStringList c = LogicClient->utenteLoggato->getListaContatti();
    ContattiList->addItems(c);

}//modificaContattiList

void ClientWidget::modalitaModifica(){

    visualizzaBox->hide();
    modificaButton->hide();
    modificaBox->show();

    NomeEdit->setText(LogicClient->utenteLoggato->getNome());
    CognomeEdit->setText(LogicClient->utenteLoggato->getCognome());
    ResidenzaEdit->setText(LogicClient->utenteLoggato->getResidenza());
    TitoloDiStudioEdit->setText(LogicClient->utenteLoggato->getTitoloStudio());
    ProfessioneEdit->setText(LogicClient->utenteLoggato->getProfessione());
    DataNascitaEdit->setDate(LogicClient->utenteLoggato->getDataNascita());
    EsperienzaEdit->setText("");
    CompetenzaEdit->setText("");
    LinguaEdit->setText("");

}//modalitaModifica

void ClientWidget::applicaModificheSlot(){

    LogicClient->modificaProfiloUtente(NomeEdit->text(),1);
    LogicClient->modificaProfiloUtente(CognomeEdit->text(),2);
    LogicClient->modificaProfiloUtente(ResidenzaEdit->text(),3);
    LogicClient->modificaProfiloUtente(TitoloDiStudioEdit->text(),4);
    LogicClient->modificaProfiloUtente(ProfessioneEdit->text(),5);
    LogicClient->modificaProfiloUtente(DataNascitaEdit->date(),1);

    modificaMessageLabel->setText("Modifiche effettuate con successo!");

}//applicaModificheSlot

void ClientWidget::modificheCompletateSlot(){

    modificaBox->hide();
    visualizzaBox->show();
    modificaButton->show();

    NomeLabel->setText(LogicClient->utenteLoggato->getNome());
    CognomeLabel->setText(LogicClient->utenteLoggato->getCognome());
    ResidenzaLabel->setText(LogicClient->utenteLoggato->getResidenza());
    TitoloDiStudioLabel->setText(LogicClient->utenteLoggato->getTitoloStudio());
    ProfessioneLabel->setText(LogicClient->utenteLoggato->getProfessione());
    DataNascitaLabel->setText(LogicClient->utenteLoggato->getDataNascita().toString());

    modificaMessageLabel->setText("");

}//modificheCompletateSlot

void ClientWidget::aggiungiEsperienzaSlot(){

    QString x = EsperienzaEdit->text();
    if(x.isEmpty()){
        modificaMessageLabel->setText("Impossibile effettuare l'operazione: campo di modifica vuoto");
    }//if
    else{
        LogicClient->modificaProfiloUtente(x,6);
        EsperienzeList->addItem(x);
        EsperienzeList->sortItems();
        EsperienzaEdit->setText("");
        modificaMessageLabel->setText("Esperienza aggiunta con successo!");
    }//else

}//aggiungiEsperienzaSlot

void ClientWidget::rimuoviEsperienzaSlot(){

    QString x = EsperienzaEdit->text();
    if(x.isEmpty()){
        modificaMessageLabel->setText("Impossibile effettuare l'operazione: campo di modifica vuoto");
    }//if
    else{
        LogicClient->modificaProfiloUtente(x,7);
        QStringList a = LogicClient->utenteLoggato->getEsperienze();
        EsperienzeList->clear();
        EsperienzeList->addItems(a);
        modificaMessageLabel->setText("Esperienza rimossa con successo!");
    }//else

}//rimuoviEsperienzaSlot

void ClientWidget::aggiungiCompetenzaSlot(){

    QString x = CompetenzaEdit->text();
    if(x.isEmpty()){
        modificaMessageLabel->setText("Impossibile effettuare l'operazione: campo di modifica vuoto");
    }//if
    else{
       LogicClient->modificaProfiloUtente(x,8);
       CompetenzeList->addItem(x);
       CompetenzeList->sortItems();
       CompetenzaEdit->setText("");
       modificaMessageLabel->setText("Competenza aggiunta con successo!");
    }//else

}//aggiungiCompetenzaSlot

void ClientWidget::rimuoviCompetenzaSlot(){

    QString x = CompetenzaEdit->text();
    if(x.isEmpty()){
        modificaMessageLabel->setText("Impossibile effettuare l'operazione: campo di modifica vuoto");
    }//if
    else{
        LogicClient->modificaProfiloUtente(x,9);
        QStringList a = LogicClient->utenteLoggato->getCompetenze();
        CompetenzeList->clear();
        CompetenzeList->addItems(a);
        modificaMessageLabel->setText("Competenza rimossa con successo!");
    }//else

}//rimuoviCompetenzaSlot

void ClientWidget::aggiungiLinguaSlot(){

    QString x = LinguaEdit->text();
    if(x.isEmpty()){
        modificaMessageLabel->setText("Impossibile effettuare l'operazione: campo di modifica vuoto");
    }//if
    else{
        LogicClient->modificaProfiloUtente(x,10);
        LingueList->addItem(x);
        LingueList->sortItems();
        LinguaEdit->setText("");
        modificaMessageLabel->setText("Lingua aggiunta con successo!");
    }//else

}//aggiungiLinguaSlot

void ClientWidget::rimuoviLinguaSlot(){

    QString x = LinguaEdit->text();
    if(x.isEmpty()){
        modificaMessageLabel->setText("Impossibile effettuare l'operazione: campo di modifica vuoto");
    }//if
    else{
        LogicClient->modificaProfiloUtente(x,11);
        QStringList a = LogicClient->utenteLoggato->getLingue();
        LingueList->clear();
        LingueList->addItems(a);
        modificaMessageLabel->setText("Lingua rimossa con successo!");
    }//else

}//rimuoviLinguaSlot

void ClientWidget::salvaSlot(){

    LogicClient->salva();

}//salvaSlot

void ClientWidget::cercaUsernameSlot(){

    QString x = cercaUtenteUsernameEdit->text();
    if(x.isEmpty()){
        ricercaMessageLabel->setText("Impossibile cercare l'utente: campo di ricerca vuoto");
    }//if
    else{
        LogicClient->cercaUtenteUsername(x);
        if(LogicClient->utenteSelezionato==0){
            ricercaMessageLabel->setText("L'utente cercato non è presente su LinQedIn");
            modificaSelezionato();
        }//if
        else{
            ricercaMessageLabel->setText("L'utente cercato è iscritto a LinQedIn");
            modificaSelezionato();
            aggiungiButton->show();
            LogicClient->stampaInfoCercato();
            if(LogicClient->stampaProfiloCompleto){
                visualizzaCercatoCompletoButton->show();
            }//if
            else{
                if(LogicClient->stampaProfilo){
                    visualizzaCercatoButton->show();
                }//if
            }//else
        }//else
    }//else

}//cercaUsernameSlot

void ClientWidget::cercaNomeCognomeSlot(){

    QString n = cercaUtenteNomeEdit->text();
    QString c = cercaUtenteCognomeEdit->text();
    if((n.isEmpty())||(c.isEmpty())){
        ricercaMessageLabel->setText("Impossibile cercare l'utente: campo di ricerca vuoto");
    }//if
    else{
        LogicClient->cercaUtenteNomeCognome(n,c);
        if(LogicClient->utenteSelezionato==0){
            ricercaMessageLabel->setText("L'utente cercato non è presente su LinQedIn");
            modificaSelezionato();
        }//if
        else{
            ricercaMessageLabel->setText("L'utente cercato è iscritto a LinQedIn");
            modificaSelezionato();
            aggiungiButton->show();
            LogicClient->stampaInfoCercato();
            if(LogicClient->stampaProfiloCompleto){
                visualizzaCercatoCompletoButton->show();
            }//if
            else{
                if(LogicClient->stampaProfilo){
                    visualizzaCercatoButton->show();
                }//if
            }//else
        }//else
    }//else

}//cercaNomeCognomeSlot

void ClientWidget::aggiungiContattoSlot(){

    if(LogicClient->aggiungiUtenteSelezionato()){
        ricercaMessageLabel->setText("Contatto aggiunto alla propria rete!");
    }//if
    else{
        ricercaMessageLabel->setText("Contatto gia' presente nella propria rete");
    }//else
    cercaUtenteUsernameEdit->setText("");
    cercaUtenteNomeEdit->setText("");
    cercaUtenteCognomeEdit->setText("");
    aggiungiButton->hide();
    modificaContattiList();

}//aggiungiContattoSlot

void ClientWidget::cercaContattoSlot(){

    QString x = cercaContattoEdit->text();
    if(!x.isEmpty()){
        if(!LogicClient->cercaContatto(x)){
            contattiLabel->setText("Contatto non presente");
            contattiLabel->show();
            cercaContattoEdit->setText("");
            visualizzaContattoButton->hide();
            rimuoviButton->hide();
        }//if
        else{
            if(!LogicClient->utenteSelezionato){
                contattiLabel->setText("Il contatto cercato non è piu'\niscritto a LinQedIn\ndunque e' stato rimosso");
                contattiLabel->show();
                modificaContattiList();
                cercaContattoEdit->setText("");
                visualizzaContattoButton->hide();
                rimuoviButton->hide();
            }//if
            else{
                contattiLabel->setText("Contatto presente");
                contattiLabel->show();
                visualizzaContattoButton->show();
                rimuoviButton->show();
            }//else
        }//else
        modificaSelezionato();
        ricercaMessageLabel->setText("");
        aggiungiButton->hide();
        visualizzaCercatoButton->hide();
        visualizzaCercatoCompletoButton->hide();
    }//if

}//cercaContattoSlot

void ClientWidget::visualizzaContattoSlot(){

    profiloReteWidget* profilo = new profiloReteWidget(LogicClient->utenteSelezionato);
    profilo->show();

}//visualizzaContattoSlot

void ClientWidget::rimuoviContattoSlot(){

    LogicClient->rimuoviUtenteSelezionato();
    contattiLabel->setText("Contatto rimosso!");
    rimuoviButton->hide();
    visualizzaContattoButton->hide();
    ricercaMessageLabel->setText("");
    cercaContattoEdit->setText("");
    modificaContattiList();
    modificaSelezionato();

}//rimuoviContattoSlot

void ClientWidget::getContattoSlot(){

    QString x = ContattiList->currentItem()->text();
    if(!LogicClient->cercaContatto(x)){
        contattiLabel->setText("Contatto non presente");
        contattiLabel->show();
        cercaContattoEdit->setText("");
        visualizzaContattoButton->hide();
        rimuoviButton->hide();
    }//if
    else{
        if(!LogicClient->utenteSelezionato){
            contattiLabel->setText("Il contatto cercato non è piu'\niscritto a LinQedIn\ndunque e' stato rimosso");
            contattiLabel->show();
            modificaContattiList();
            cercaContattoEdit->setText("");
            visualizzaContattoButton->hide();
            rimuoviButton->hide();
        }//if
        else{
            contattiLabel->setText("Contatto presente");
            contattiLabel->show();
            visualizzaContattoButton->show();
            rimuoviButton->show();
        }//else
    }//else
    modificaSelezionato();
    ricercaMessageLabel->setText("");
    aggiungiButton->hide();
    visualizzaCercatoButton->hide();
    visualizzaCercatoCompletoButton->hide();

}//getContattoSlot


void ClientWidget::visualizzaCercatoSlot(){

    profiloWidget* profilo = new profiloWidget(LogicClient->utenteSelezionato);
    profilo->show();

}//visualizzaCercatoSlot

void ClientWidget::visualizzaCercatoCompletoSlot(){

    profiloReteWidget* profilo = new profiloReteWidget(LogicClient->utenteSelezionato);
    profilo->show();

}//visualizzaCercatoCompletoSlot

