#include "loginwidget.h"

LoginWidget::LoginWidget(DataBase * d, QWidget *parent) : QWidget(parent){

    db = d;
    loginLayout = new QVBoxLayout;
    QLabel* loginLabel = new QLabel;
    QLabel* spazio = new QLabel;
    loginEdit = new QLineEdit;
    QPushButton* loginButton = new QPushButton;
    QPushButton* signUpButton = new QPushButton;
    QLabel* signUpLabel = new QLabel;
    QPushButton* indietroButton = new QPushButton;
    loginBox = new QGroupBox;
    QVBoxLayout* boxLayout = new QVBoxLayout;
    QVBoxLayout* boxLayout2 = new QVBoxLayout;

    loginLabel->setText("Username");
    loginLabel->setAlignment(Qt::AlignCenter);
    loginEdit->setMaximumWidth(100);
    loginEdit->setFixedSize(120,20);
    loginButton->setText("Login");
    loginButton->setFixedSize(100,25);
    signUpLabel->setText("                  Vuroi Registrarti?");
    signUpLabel->setAlignment(Qt::AlignCenter);
    signUpButton->setText("Registrati!");
    signUpButton->setFixedSize(100,25);
    indietroButton->setText("Indietro");

    connect(loginButton,SIGNAL(clicked()),this,SLOT(effettuaLogin()));
    connect(indietroButton,SIGNAL(clicked()),this,SIGNAL(indietro()));
    connect(signUpButton,SIGNAL(clicked()),this,SLOT(registrazioneSlot()));

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(loginLabel);
    layout->addWidget(loginEdit);
    layout->addWidget(signUpLabel);

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(loginButton);
    buttonLayout->addWidget(spazio);
    buttonLayout->addWidget(signUpButton);

    boxLayout->addLayout(layout);
    boxLayout->addLayout(buttonLayout);
    boxLayout->addWidget(indietroButton);
    boxLayout->setAlignment(indietroButton,Qt::AlignCenter);
    loginBox->setLayout(boxLayout);
    loginLayout->addWidget(loginBox);
    loginLayout->setAlignment(loginBox,Qt::AlignCenter);

    setLayout(loginLayout);

}//LoginWidget

void LoginWidget::effettuaLogin(){

    if(!loginEdit->text().isEmpty()){
        sessioneClient = new ClientWidget(loginEdit->text(),db);
        connect(sessioneClient,SIGNAL(logoutSignal()),this,SLOT(sessioneTerminata()));
        loginBox->hide();
        loginEdit->setText("");
        loginLayout->addWidget(sessioneClient);
    }//if

}//effettuaLogin

void LoginWidget::sessioneTerminata(){

    if(sessioneClient){
        delete sessioneClient;
    }//if
    loginBox->show();

}//sessioneTerminata

void LoginWidget::registrazioneSlot(){

    registrazione = new RegistrazioneWidget(db);
    connect(registrazione,SIGNAL(indietro()),this,SLOT(annullaRegistrazione()));
    loginBox->hide();
    loginEdit->setText("");
    loginLayout->addWidget(registrazione);

}//registrazioneSlot

void LoginWidget::annullaRegistrazione(){

    delete registrazione;
    loginBox->show();

}//annullaRegistrazione
