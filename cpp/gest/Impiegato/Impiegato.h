//
// Created by Mattia Lunardi on 05/05/22.
//

#ifndef PROGPROCEDURALE_IMPIEGATO_H
#define PROGPROCEDURALE_IMPIEGATO_H
#include <string>
#include "../List/List.h"

class Impiegato {
public:
    Impiegato(std::string&, std::string&);
    ~Impiegato();
    [[nodiscard]] std::string get_nome() const;
    void set_nome(std::string&);
    [[nodiscard]] std::string get_ruolo() const ;
    void set_ruolo(std::string&);
    void print_lista(void);
    virtual void print(void) const;
    bool operator!=(Impiegato&);
    bool operator==(Impiegato&);

private:
    List<Impiegato> lista_impiegati;
    std::string nome;
    std::string ruolo;
};

#endif //PROGPROCEDURALE_IMPIEGATO_H
