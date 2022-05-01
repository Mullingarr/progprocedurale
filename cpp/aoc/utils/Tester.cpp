//
// Created by Mattia Lunardi on 01/05/22.
//

#include "Tester.h"
#include <iostream>

Tester::Tester(){
    std::cout << "Tester started." << std::endl;
}

Tester::~Tester()=default;

std::string Tester::getPath(){
    return this->pathToInputFiles;
}

void Tester::setPath(std::string& pathToInputFiles){
    this->pathToInputFiles = pathToInputFiles;
}

std::vector<std::string> Tester::getTests(){return this->tests;}
void Tester::addFileToTests(std::string& file){this->tests.push_back(file);}

std::vector<std::string> splitString(std::string& s){
    std::vector<std::string> v;
    char arr[s.length() + 1];
    strcpy(arr, s.c_str());
    for(int i = 0; i < s.length(); i++) v.emplace_back(std::string(1, arr[i]));
    return v;
}

std::vector<conwayCube> buildCubes(std::vector<std::string>& tokenizedString, int x, int y, int z){
    std::vector<conwayCube> cubes;
    for(auto& tkn: tokenizedString){
        cubes.emplace_back(conwayCube(x, y, z, tkn));
        y++;
    }

    return cubes;
}

bool compareCubes(conwayCube& c, conwayCube& cc){
    std::vector<int> cCoords = c.getCoordinates();
    std::string cS = c.getS();
    std::vector<int> ccCoords = c.getCoordinates();
    std::string ccS = cc.getS();

    if(cCoords[0] != ccCoords[0]) return false;
    if(cCoords[1] != ccCoords[1]) return false;
    if(cCoords[2] != ccCoords[2]) return false;
    if(cS != ccS) return false;
    return true;
}

bool Tester::test(std::string& filenameTestFile, std::vector<conwayCube>& cubesToTest){
    Reader r = Reader(filenameTestFile);
    std::cout << "Reading from: " << filenameTestFile << "\n";
    std::vector<std::string> input = r.readInput();
    std::vector<conwayCube> cubes;
    int x = 0, y = 0;
    const int z = 0;

    for(auto& s : input){
        std::vector<std::string> split_string = splitString(s);
        std::vector<conwayCube> tmp = buildCubes(split_string, x, y, z);
        x++;
        for(auto& c : tmp) cubes.emplace_back(c);
    }
    //check size
    if(cubesToTest.size() < cubes.size()){
        std::cout << "Less cubes than expected!\n";
        return false;
    }
    else if(cubesToTest.size() > cubes.size()){
        std::cout << "More cubes than expected\n";
        return false;
    }else{ //same size
        for(int i = 0; i < cubes.size(); i++){
            if(!compareCubes(cubes[i], cubesToTest[i])){
                std::cout << "Cube: " << cubes[i].toString()
                    << "doesn't match" << cubesToTest[i].toString() << "\n";
                return false;
            }
        }
    }
    return true;
}

bool Tester::testAll(){

}