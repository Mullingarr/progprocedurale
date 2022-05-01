//
// Created by Mattia Lunardi on 28/04/22.
//
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include "utils/Reader.h"
#include "conway_cubes/conwayCube.h"

conwayCube buildConwayCube(int x, int y, int z, bool active){
    return {x, y, z, active};
}

std::vector<std::string> splitString(std::string& s){
    std::vector<std::string> ris;
    char arr[s.length() + 1];
    strcpy(arr, s.c_str());
    for(int i = 0; i < s.length(); i++)
        ris.emplace_back(std::string(1, arr[i]));
    return ris;
}

int main(int argc, char *argv[]){
   std::string pathToInputFile = argv[1];
   std::string filename = argv[2];

   Reader r = Reader(filename, pathToInputFile);
   std::vector<std::string> strings = r.readInput();
   std::vector<conwayCube> cubes;

   //calcola la lunghezza di una stringa
   int length = strings[0].length();

   int x = 0, y = 0;
   const int z = 0;

   for(auto& str: strings){
       std::vector<std::string> stringTokenized = splitString(str);
       for(auto& tkn : stringTokenized){
           conwayCube c = conwayCube(x, y, z, tkn);
           y++;
           cubes.push_back(c);
       }
       x++;
       if(y == length) y = 0;
   }
   
   for(auto&cube : cubes){
       cube.printCube();
       std::cout << "------------" << std::endl;
   }

}