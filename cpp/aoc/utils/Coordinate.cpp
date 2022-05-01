//
// Created by Mattia Lunardi on 28/04/22.
//

#include "Coordinate.h"
#include <iostream>

Coordinate::Coordinate(){
    this->x = 0;
    this->y = 0;
    this->z = 0;
}
Coordinate::Coordinate(int x){
    this->x = x;
    this->y = 0;
    this->z = 0;
}
Coordinate::Coordinate(int x, int y){
    this->x = x;
    this->y = y;
    this->z = 0;
}
Coordinate::Coordinate(int x, int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
}
Coordinate::Coordinate(const std::vector<int>& v){
    this->v = v;
    this->x = v[0];
    this->y = v[1];
    this->z = v[2];
}
Coordinate::~Coordinate(){
    std::cout << "Destroyer called\n";
}

std::vector<int> Coordinate::getCoords() {return this->v;}

std::vector<Coordinate> Coordinate::mapStringToCoordinates(std::string &s, int height) {
   std::vector<Coordinate> ris;
   for(int i = 0; i < s.length(); i++){
       //Coordinate c = Coordinate(i, height);
       ris.push_back(Coordinate(i, height));
   }
   return ris;
}

