//
// Created by Mattia Lunardi on 05/05/22.
//

#include <iostream>
#include "Manager.h"
Manager::Manager(std::string& nome, std::string& ruolo, short livello)
    : Impiegato(nome, ruolo){
    this->livello = livello;
}

void Manager::print() const{
    std::cout << "Manager: " << "TODO" << "\nRuolo: " << this->ruolo
    << "\nlivello: " << this->livello;
}

void Impiegato::print_lista() {
    //TODO: implement for based loop
}

