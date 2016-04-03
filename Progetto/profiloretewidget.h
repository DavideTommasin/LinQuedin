#ifndef PROFILORETEWIDGET_H
#define PROFILORETEWIDGET_H

#include "profilowidget.h"

class profiloReteWidget : public QWidget {

    Q_OBJECT

    public:
        explicit profiloReteWidget(Utente*,QWidget *parent = 0);
    private:
        Utente* user;

        QHBoxLayout* mainLayout;
        QGroupBox* visualizzaBox;
        QGroupBox* reteBox;

        QLabel* NomeLabel;
        QLabel* CognomeLabel;
        QLabel* ResidenzaLabel;
        QLabel* TitoloDiStudioLabel;
        QLabel* ProfessioneLabel;
        QLabel* DataNascitaLabel;
        QListWidget* EsperienzeList;
        QListWidget* CompetenzeList;
        QListWidget* LingueList;
        QListWidget* ContattiList;

};//profiloReteWidget

#endif // PROFILORETEWIDGET_H
