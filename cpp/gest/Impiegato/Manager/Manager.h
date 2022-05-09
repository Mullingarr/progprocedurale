//
// Created by Mattia Lunardi on 05/05/22.
//

#ifndef PROGPROCEDURALE_MANAGER_H
#define PROGPROCEDURALE_MANAGER_H

#include "../Impiegato.h"
class Manager : public Impiegato{
public:
    Manager(std::string&, std::string&, short);
    void print(void) const;
    friend void Impiegato::print_lista(void);
private:
    short livello;
    std::string ruolo;
    List gruppo;
};


#endif //PROGPROCEDURALE_MANAGER_H
