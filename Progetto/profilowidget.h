#ifndef PROFILOWIDGET_H
#define PROFILOWIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include <QListWidget>
#include <QGroupBox>
#include "utente.h"

class profiloWidget : public QWidget{

    Q_OBJECT

    public:
        explicit profiloWidget(Utente*,QWidget *parent = 0);
    private:
        Utente* user;

        QVBoxLayout* mainLayout;
        QGroupBox* visualizzaBox;

        QLabel* NomeLabel;
        QLabel* CognomeLabel;
        QLabel* ResidenzaLabel;
        QLabel* TitoloDiStudioLabel;
        QLabel* ProfessioneLabel;
        QLabel* DataNascitaLabel;
        QListWidget* EsperienzeList;
        QListWidget* CompetenzeList;
        QListWidget* LingueList;

};//profiloWidget

#endif // PROFILOWIDGET_H
