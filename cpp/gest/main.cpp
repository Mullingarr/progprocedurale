//
// Created by Mattia Lunardi on 05/05/22.
//

#include <iostream>
#include "List/List.h"

int main(){

    List<int> lista = List(10);
    lista.push(20);
    lista.push(30);

    std::vector<int> v = lista.get_list();
    for(int i : v)
        printf("%d\n", i);

}