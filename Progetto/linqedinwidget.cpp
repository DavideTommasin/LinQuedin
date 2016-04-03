#include "linqedinwidget.h"

LinqedinWidget::LinqedinWidget(QWidget *parent) : QWidget(parent){

    db = new DataBase;
    db->carica();

    setWindowTitle("LinQedIn");

    mainLayout = new QVBoxLayout;
    QVBoxLayout* boxLayout = new QVBoxLayout;
    mainBox = new QGroupBox;

    QFont t( "Times New Roman", 20);
    QLabel* welcomeLabel = new QLabel;
    QPushButton* clientButton = new QPushButton;
    QPushButton* adminButton = new QPushButton;

    welcomeLabel->setText("                                      LinQedIn");
    welcomeLabel->setAlignment(Qt::AlignBottom);
    welcomeLabel->setFont(t);
    clientButton->setText("Utente");
    clientButton->setFixedSize(150,50);
    adminButton->setText("Amministratore");
    adminButton->setFixedSize(150,50);

    connect(adminButton,SIGNAL(clicked()),this,SLOT(AmministratoreSlot()));
    connect(clientButton,SIGNAL(clicked()),this,SLOT(ClientSlot()));

    boxLayout->addWidget(clientButton);
    boxLayout->addWidget(welcomeLabel);
    boxLayout->addWidget(adminButton);
    boxLayout->addSpacing(4);
    boxLayout->setAlignment(clientButton,Qt::AlignLeft);
    boxLayout->setAlignment(adminButton,Qt::AlignLeft);
    mainBox->setLayout(boxLayout);
    mainBox->setMaximumSize(400,150);
    mainLayout->addWidget(mainBox);
    mainLayout->setAlignment(mainBox,Qt::AlignCenter);
    setLayout(mainLayout);

}//LinqedinWidget


void LinqedinWidget::ClientSlot(){

    clientLoginWidget = new LoginWidget(db);
    mainLayout->addWidget(clientLoginWidget);
    connect(clientLoginWidget,SIGNAL(indietro()),this,SLOT(chiudiClientSlot()));
    mainBox->hide();

}//ClientSlot

void LinqedinWidget::AmministratoreSlot(){

    amministratoreWidget = new AdminWidget(db);
    mainLayout->addWidget(amministratoreWidget);
    connect(amministratoreWidget,SIGNAL(indietro()),this,SLOT(chiudiAdminSlot()));
    mainBox->hide();

}//AmministratoreSlot

void LinqedinWidget::chiudiClientSlot(){

    delete clientLoginWidget;
    mainBox->show();

}//chiudiClientSlot

void LinqedinWidget::chiudiAdminSlot(){

    delete amministratoreWidget;
    mainBox->show();

}//chiudiAdminSlot
