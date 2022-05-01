//
// Created by Mattia Lunardi on 28/04/22.
//

#include <vector>
#include <iostream>
#include "../utils/Coordinate.h"

#ifndef PROGPROCEDURALE_CONWAYCUBE_H
#define PROGPROCEDURALE_CONWAYCUBE_H


class conwayCube {
public:
    conwayCube();
    conwayCube(int , int , int);
    conwayCube(int, int, int, bool);
    conwayCube(int, int, int, std::string&);
    conwayCube(Coordinate&, std::string&);
    conwayCube(const std::vector<int>&);
    conwayCube(const conwayCube&);
    ~conwayCube();
    std::vector<int> getCoordinates();
    void setCoordinates(std::vector<int>&);
    bool isActive();
    void setActive(bool);
    std::string getS();
    void setS(std::string);
    void printCube();
    std::string toString();
private:
    std::vector<int> coordinatesVector;
    int x, y, z;
    bool active;
    std::string s;
};


#endif //PROGPROCEDURALE_CONWAYCUBE_H
