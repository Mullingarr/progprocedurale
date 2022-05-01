//
// Created by Mattia Lunardi on 01/05/22.
//

#ifndef PROGPROCEDURALE_TESTER_H
#define PROGPROCEDURALE_TESTER_H

#include "Reader.h"
#include "Coordinate.h"
#include "../conway_cubes/conwayCube.h"
#include <vector>
#include <string>
#include <assert.h>

class Tester {
public:
    Tester();
    ~Tester();
    std::string getPath();
    void setPath(std::string&);
    std::vector<std::string> getTests();
    void addFileToTests(std::string&);
    bool test(std::string&, std::vector<conwayCube>&);
    bool testAll();

private:
    std::vector<std::string> tests;
    std::string pathToInputFiles;
};


#endif //PROGPROCEDURALE_TESTER_H
