#ifndef SIGNUPWIDGET_H
#define SIGNUPWIDGET_H

#include <QWidget>
#include "clientwidget.h"

class RegistrazioneWidget : public QWidget{

    Q_OBJECT

    public:
        explicit RegistrazioneWidget(DataBase*,QWidget *parent = 0);

    private:
        DataBase* db;

        QVBoxLayout* RegistrazioneLayout;
        QGroupBox* RegistrazioneBox;
        QLineEdit* UsernameEdit;
        QLineEdit* NomeEdit;
        QLineEdit* CognomeEdit;
        QDateEdit* DataNascitaEdit;
        QLineEdit* ResidenzaEdit;
        QLineEdit* ProfessioneEdit;
        QLineEdit* TitoloStudioEdit;
        QLabel* messaggio;

    signals:
        void indietro();

    public slots:
        void creaUtenteBasic();
        void creaUtenteBusiness();
        void creaUtenteExecutive();

};//SignUpWidget

#endif // SIGNUPWIDGET_H
