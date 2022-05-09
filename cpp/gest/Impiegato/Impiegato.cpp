//
// Created by Mattia Lunardi on 05/05/22.
//

#include "Impiegato.h"
#include <iostream>

Impiegato::Impiegato(std::string& nome, std::string& ruolo) {
    this->nome = nome;
    this->ruolo = ruolo;
}

Impiegato::~Impiegato() = default;
std::string Impiegato::get_nome() const {return this->nome;}
std::string Impiegato::get_ruolo() const {return this->ruolo;}
void Impiegato::set_nome(std::string& n){this->nome = n;}
void Impiegato::set_ruolo(std::string& r){this->ruolo = r;}

bool Impiegato::operator!=(Impiegato& other){
    if(this->nome == other.nome && this->ruolo == other.ruolo)
        return true;
    return false;
}

bool Impiegato::operator==(Impiegato& other){
    if(this->nome != other.nome && this->ruolo != other.ruolo)
        return false;
    return true;
}

//Impiegato Impiegato::operator++(){
   //TODO
//}

void Impiegato::print() const{
    std::cout << "Nome impiegato: " << this->nome << "\nRuolo: "
        << this->ruolo << "\n";
}

void Impiegato::print_lista() {
    printf("===== printing list =====\n");
    for(const auto& i : this->lista_impiegati) i.print();
    printf("===== end list =====\n");
}