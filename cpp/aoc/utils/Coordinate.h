//
// Created by Mattia Lunardi on 28/04/22.
//
#include <iostream>
#include <vector>

#ifndef PROGPROCEDURALE_COORDINATE_H
#define PROGPROCEDURALE_COORDINATE_H

class Coordinate {
public:
   Coordinate();
   Coordinate(int);
   Coordinate(int, int);
   Coordinate(int, int, int);
   Coordinate(const std::vector<int>&);
   ~Coordinate();


private:
    std::vector<int> v;
    int x, y, z;
};


#endif //PROGPROCEDURALE_COORDINATE_H
