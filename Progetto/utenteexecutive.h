#ifndef UTENTEEXECUTIVE_H
#define UTENTEEXECUTIVE_H

#include "utentebusiness.h"

class UtenteExecutive: public UtenteBusiness{

    public:
        UtenteExecutive(QString);
        void stampaInfo(bool&,bool&);

};//UtenteExecutive

#endif // UTENTEEXECUTIVE_H
