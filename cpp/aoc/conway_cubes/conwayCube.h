//
// Created by Mattia Lunardi on 28/04/22.
//

#include <vector>
#include <iostream>

#ifndef PROGPROCEDURALE_CONWAYCUBE_H
#define PROGPROCEDURALE_CONWAYCUBE_H


class conwayCube {
public:
    conwayCube();
    conwayCube(int , int , int);
    conwayCube(int, int, int, bool);
    conwayCube(const std::vector<int>&);
    conwayCube(const conwayCube&);
    ~conwayCube();
    std::vector<int> getCoordinates();
    void setCoordinates(std::vector<int>&);
    void printCube();
private:
    std::vector<int> coordinatesVector;
    int x, y, z;
    bool active;
};


#endif //PROGPROCEDURALE_CONWAYCUBE_H
