#include "registrazionewidget.h"

RegistrazioneWidget::RegistrazioneWidget(DataBase * d, QWidget *parent) : QWidget(parent){

    db = d;
    RegistrazioneLayout = new QVBoxLayout;
    QLabel* istruzioni = new QLabel;
    QLabel* cObbligatori= new QLabel;
    RegistrazioneBox = new QGroupBox;
    UsernameEdit = new QLineEdit;
    NomeEdit = new QLineEdit;
    CognomeEdit = new QLineEdit;
    DataNascitaEdit = new QDateEdit;
    ResidenzaEdit = new QLineEdit;
    ProfessioneEdit = new QLineEdit;
    TitoloStudioEdit = new QLineEdit;
    QLabel* scelta = new QLabel;
    QPushButton* basic = new QPushButton;
    QPushButton* business = new QPushButton;
    QPushButton* executive = new QPushButton;
    QPushButton* indietro = new QPushButton;
    messaggio = new QLabel;

    RegistrazioneBox->setTitle("Iscrizione");
    istruzioni->setText("Inserisci i tuoi dati");
    QVBoxLayout* vlayout = new QVBoxLayout;
    QFormLayout* flayout = new QFormLayout;
    flayout->addRow("Username: * ",UsernameEdit);
    flayout->addRow("Nome: ",NomeEdit);
    flayout->addRow("Cognome: ",CognomeEdit);
    flayout->addRow("Data di nascita: ",DataNascitaEdit);
    flayout->addRow("Residenza: ",ResidenzaEdit);
    flayout->addRow("TitoloStudio: ",TitoloStudioEdit);
    flayout->addRow("Professione: ",ProfessioneEdit);
    DataNascitaEdit->setDate(QDate(1980,1,1));
    scelta->setText("Scegli la tipologia di account\nper effettuare la registrazione!");
    scelta->setAlignment(Qt::AlignCenter);
    basic->setText("Basic");
    business->setText("Business");
    executive->setText("Executive");
    indietro->setText("Annulla");
    cObbligatori->setText("* i dati sono obbligatori");
    QFont t( "Times New Roman", 10);
    cObbligatori->setFont(t);
    messaggio->setText("");
    messaggio->setAlignment(Qt::AlignCenter);
    connect(basic,SIGNAL(clicked()),this,SLOT(creaUtenteBasic()));
    connect(business,SIGNAL(clicked()),this,SLOT(creaUtenteBusiness()));
    connect(executive,SIGNAL(clicked()),this,SLOT(creaUtenteExecutive()));
    connect(indietro,SIGNAL(clicked()),this,SIGNAL(indietro()));
    QHBoxLayout* hlayout = new QHBoxLayout;
    hlayout->addWidget(basic);
    hlayout->addWidget(business);
    hlayout->addWidget(executive);
    vlayout->addWidget(istruzioni);
    vlayout->addSpacing(15);
    vlayout->addLayout(flayout);
    vlayout->addSpacing(10);
    vlayout->addWidget(scelta);
    vlayout->addLayout(hlayout);
    vlayout->addWidget(messaggio);
    vlayout->addSpacing(5);
    messaggio->hide();
    vlayout->addWidget(indietro);
    vlayout->addWidget(cObbligatori);
    RegistrazioneBox->setLayout(vlayout);
    RegistrazioneLayout->addWidget(RegistrazioneBox);
    RegistrazioneLayout->setAlignment(RegistrazioneBox,Qt::AlignCenter);
    setLayout(RegistrazioneLayout);

}//RegistrazioneWidget

void RegistrazioneWidget::creaUtenteBasic(){

    if(!UsernameEdit->text().isEmpty()){
        Utente* u = new UtenteBasic(UsernameEdit->text());
        if(db->aggiungi(u)){
            if(!NomeEdit->text().isEmpty()){
                u->setNome(NomeEdit->text());
            }//if
            if(!CognomeEdit->text().isEmpty()){
                u->setCognome(CognomeEdit->text());
            }//if
            u->setDataNascita(DataNascitaEdit->date());
            if(!ResidenzaEdit->text().isEmpty()){
                u->setResidenza(ResidenzaEdit->text());
            }//if
            if(!TitoloStudioEdit->text().isEmpty()){
                u->setTitoloStudio(TitoloStudioEdit->text());
            }//if
            if(!ProfessioneEdit->text().isEmpty()){
                u->setProfessione(ProfessioneEdit->text());
            }//if
            indietro();
        }//if
        else{
            delete u;
            messaggio->setText("Attenzione:\nNome utente gia' in uso");
            messaggio->show();
        }//else
    }//if
    else{
        messaggio->setText("Attenzione:\nAlcuni campi obbligatori sono incompleti");
        messaggio->show();
    }//else

}//creaUtenteBasic

void RegistrazioneWidget::creaUtenteBusiness(){

    if(!UsernameEdit->text().isEmpty()){
        Utente* u = new UtenteBusiness(UsernameEdit->text());
        if(db->aggiungi(u)){
            if(!NomeEdit->text().isEmpty()){
                u->setNome(NomeEdit->text());
            }//if
            if(!CognomeEdit->text().isEmpty()){
                u->setCognome(CognomeEdit->text());
            }//if
            u->setDataNascita(DataNascitaEdit->date());
            if(!ResidenzaEdit->text().isEmpty()){
                u->setResidenza(ResidenzaEdit->text());
            }//if
            if(!TitoloStudioEdit->text().isEmpty()){
                u->setTitoloStudio(TitoloStudioEdit->text());
            }//if
            if(!ProfessioneEdit->text().isEmpty()){
                u->setProfessione(ProfessioneEdit->text());
            }//if
            indietro();
        }//if
        else{
            delete u;
            messaggio->setText("Attenzione:\nNome utente gia' in uso");
            messaggio->show();
        }//else
    }//if
    else{
        messaggio->setText("Attenzione:\nAlcuni campi obbligatori sono incompleti");
        messaggio->show();
    }//else

}//creaUtenteBusiness

void RegistrazioneWidget::creaUtenteExecutive(){

    if(!UsernameEdit->text().isEmpty()){
        Utente* u = new UtenteExecutive(UsernameEdit->text());
        if(db->aggiungi(u)){
            if(!NomeEdit->text().isEmpty()){
                u->setNome(NomeEdit->text());
            }//if
            if(!CognomeEdit->text().isEmpty()){
                u->setCognome(CognomeEdit->text());
            }//if
            u->setDataNascita(DataNascitaEdit->date());
            if(!ResidenzaEdit->text().isEmpty()){
                u->setResidenza(ResidenzaEdit->text());
            }//if
            if(!TitoloStudioEdit->text().isEmpty()){
                u->setTitoloStudio(TitoloStudioEdit->text());
            }//if
            if(!ProfessioneEdit->text().isEmpty()){
                u->setProfessione(ProfessioneEdit->text());
            }//if
            indietro();
        }//if
        else{
            delete u;
            messaggio->setText("Attenzione:\nNome utente gia' in uso");
            messaggio->show();
        }//else
    }//if
    else{
        messaggio->setText("Attenzione:\nAlcuni campi obbligatori sono incompleti");
        messaggio->show();
    }//else

}//creaUtenteExecutive
