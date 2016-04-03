#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include "registrazionewidget.h"

class LoginWidget : public QWidget{

    Q_OBJECT

    public:
        explicit LoginWidget(DataBase*,QWidget *parent = 0);

    private:
        DataBase* db;

        QVBoxLayout* loginLayout;       // layout della schermata di login
        QGroupBox* loginBox;
        QLineEdit* loginEdit;
        ClientWidget* sessioneClient;   // widget della sessione utente a cui si accede dal login
        RegistrazioneWidget* registrazione;

    signals:
        void indietro();

    public slots:
        void effettuaLogin();
        void sessioneTerminata();
        void registrazioneSlot();
        void annullaRegistrazione();

};//LoginWidget

#endif // LOGINWIDGET_H
