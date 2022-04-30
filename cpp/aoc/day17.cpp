//
// Created by Mattia Lunardi on 28/04/22.
//

#include <iostream>
#include <string>
#include <vector>
#include "utils/Reader.h"
#include "conway_cubes/conwayCube.h"

conwayCube buildConwayCube(int x, int y, int z, bool active){
    return {x, y, z, active};
}

int main(int argc, char *argv[]){
   std::string pathToInputFile = argv[1];
   std::string filename = argv[2];

   Reader r = Reader(filename, pathToInputFile);
   std::vector<std::string> strings = r.readInput();
   std::vector<std::string> tokenizedStrings = r.tokenizeStrings(strings);
   std::vector<conwayCube> cubes;

   int x = 0, y = 0;
   const int z = 0;
   conwayCube c;

   for(const auto& str: tokenizedStrings){
       if(str == "."){
           c = buildConwayCube(x, y, z, false);
       }else{
           c = buildConwayCube(x, y, z, true);
       }
       cubes.push_back(c);

   }

   for(auto&cube : cubes){
       cube.printCube();
       std::cout << "------------" << std::endl;
   }


}