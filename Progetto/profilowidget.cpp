#include "profilowidget.h"

profiloWidget::profiloWidget(Utente* u,QWidget *parent) : QWidget(parent), user(u){

    mainLayout = new QVBoxLayout;
    visualizzaBox = new QGroupBox;

    NomeLabel = new QLabel;
    CognomeLabel = new QLabel;
    ResidenzaLabel = new QLabel;
    TitoloDiStudioLabel = new QLabel;
    ProfessioneLabel = new QLabel;
    DataNascitaLabel = new QLabel;
    EsperienzeList = new QListWidget;
    CompetenzeList = new QListWidget;
    LingueList = new QListWidget;

    NomeLabel->setText(user->getNome());
    CognomeLabel->setText(user->getCognome());
    ResidenzaLabel->setText(user->getResidenza());
    TitoloDiStudioLabel->setText(user->getTitoloStudio());
    ProfessioneLabel->setText(user->getProfessione());
    DataNascitaLabel->setText(user->getDataNascita().toString());

    QStringList x = user->getEsperienze();
    EsperienzeList->addItems(x);
    x = user->getCompetenze();
    CompetenzeList->addItems(x);
    x = user->getLingue();
    LingueList->addItems(x);

    QFormLayout* flayout = new QFormLayout;

    flayout->addRow("Nome: ",NomeLabel);
    flayout->addRow("Cognome: ",CognomeLabel);
    flayout->addRow("Data di nascita: ",DataNascitaLabel);
    flayout->addRow("Residenza: ",ResidenzaLabel);
    flayout->addRow("Titolo di studio: ",TitoloDiStudioLabel);
    flayout->addRow("Professione: ",ProfessioneLabel);
    flayout->addRow("Esperienze: ",EsperienzeList);
    flayout->addRow("Competenze: ",CompetenzeList);
    flayout->addRow("Lingue parlate: ",LingueList);

    visualizzaBox->setLayout(flayout);
    QString un("Profilo dell'utente ");
    un.append(user->getUsername());
    visualizzaBox->setTitle(un);
    mainLayout->addWidget(visualizzaBox);
    setLayout(mainLayout);

}//profiloWidget


