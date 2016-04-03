#ifndef UTENTEBASIC_H
#define UTENTEBASIC_H

#include "utente.h"

class UtenteBasic: public Utente{

    public:
        UtenteBasic(QString);
        void stampaInfo(bool &, bool &);

};//UtenteBasic

#endif // UTENTEBASIC_H
