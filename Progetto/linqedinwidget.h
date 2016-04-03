#ifndef LINQEDINWIDGET_H
#define LINQEDINWIDGET_H

#include "loginwidget.h"
#include "adminwidget.h"

class LinqedinWidget : public QWidget{

    Q_OBJECT

    public:
        explicit LinqedinWidget(QWidget *parent = 0);

    private:
        DataBase* db;

        QVBoxLayout* mainLayout;            // layout principale
        QGroupBox* mainBox;                 // contenitore dei widget
        LoginWidget* clientLoginWidget;
        AdminWidget* amministratoreWidget;

    public slots:
        void ClientSlot();                  // passa alla schermata di login
        void AmministratoreSlot();          // passa alla schermata amministratore
        void chiudiClientSlot();
        void chiudiAdminSlot();

};//LinqedinWidget

#endif // LINQEDINWIDGET_H
