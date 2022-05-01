//
// Created by Mattia Lunardi on 28/04/22.
//
#include <iostream>
#include <vector>
#include "conwayCube.h"

conwayCube::conwayCube() {
    std::cout << "init new cube at default coords\n";
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

conwayCube::conwayCube(int x, int y, int z){
    std::vector<int> vec;
    vec.push_back(x);
    vec.push_back(y);
    vec.push_back(z);
    this->coordinatesVector = vec;
    this->x = x;
    this->y = y;
    this->z = z;
}

conwayCube::conwayCube(int x, int y, int z, bool active) {
    std::vector<int> vec;
    vec.push_back(x);
    vec.push_back(y);
    vec.push_back(z);
    this->coordinatesVector = vec;
    this->x = x;
    this->y = y;
    this->z = z;
    this->active = active;
}

conwayCube::conwayCube(Coordinate& c, std::string& s){
   std::vector<int> v;
   v = c.getCoords();
   this->x = v[0];
   this->y = v[1];
   this->z = v[2];
   this->s = s;
   if(s == ".")
       this->active = false;
   else if(s == "#")
       this->active = true;

}

conwayCube::conwayCube(int x, int y, int z, std::string& s){
    std::vector<int> vec;
    vec.push_back(x);
    vec.push_back(y);
    vec.push_back(z);
    this->coordinatesVector = vec;
    this->x = x;
    this->y = y;
    this->z = z;
    if(s == ".")
        this->active = false;
    else if(s == "#")
        this->active = true;
}

conwayCube::conwayCube(const std::vector<int>& v){
    this->coordinatesVector = v;
    this->x = v[0];
    this->y = v[1];
    this->z = v[2];
}

//copy constructor
conwayCube::conwayCube(const conwayCube &otherCube) {
    //std::cout << "copy constructor called\n";
    this->coordinatesVector = otherCube.coordinatesVector;
    this->x = otherCube.x;
    this->y = otherCube.y;
    this->z = otherCube.z;
    this->active = otherCube.active;
    this->coordinatesVector = otherCube.coordinatesVector;
    //std::cout << "deep copy created\n";
}

conwayCube::~conwayCube()= default;

std::vector<int> conwayCube::getCoordinates() {return this->coordinatesVector;}
void conwayCube::setCoordinates(std::vector<int>& vec){this->coordinatesVector = vec;}

bool conwayCube::isActive(){return this->active;}
void conwayCube::setActive(bool active){this->active = active;}

std::string conwayCube::getS() {return this->s;}
void conwayCube::setS(std::string s){this->s = s;}

void conwayCube::printCube(){
   std::cout << "{" << this->x << "}" << "{" << this->y << "}"
        << "{" << this->z << "}\n";
   std::cout << "{status} : " << "{" << this->active << "}" << "\n";
}


