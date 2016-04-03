#include "profiloretewidget.h"

profiloReteWidget::profiloReteWidget(Utente * u, QWidget *parent) : QWidget(parent), user(u){

    mainLayout = new QHBoxLayout;
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


    QVBoxLayout* vlayout = new QVBoxLayout;
    reteBox = new QGroupBox;
    reteBox->setTitle("Rete contatti dell'utente:");
    ContattiList = new QListWidget;
    QStringList c = user->getListaContatti();
    ContattiList->addItems(c);
    vlayout->addWidget(ContattiList);
    reteBox->setLayout(vlayout);
    reteBox->setMaximumWidth(200);

    visualizzaBox->setLayout(flayout);
    QString un("Profilo dell'utente ");
    un.append(user->getUsername());
    visualizzaBox->setTitle(un);
    mainLayout->addWidget(reteBox);
    mainLayout->addWidget(visualizzaBox);
    setLayout(mainLayout);

}//profiloReteWidget

