//
// Created by Mattia Lunardi on 28/04/22.
//
#include <string>
#include <iostream>
#include <vector>

#ifndef PROGPROCEDURALE_READER_H
#define PROGPROCEDURALE_READER_H

class Reader{
public:
    Reader();
    Reader(const std::string&);
    Reader(const std::string&, const std::string&);
    std::string getFilename();
    std::string getInputDir();
    void setInputDir(std::string&);
    void setOutputDir(std::string&);
    void setFilename(std::string&);
    std::vector<std::string> readInput();
    std::vector<int> convertVector(std::vector<std::string>&);
    std::vector<std::string> tokenizeStrings(std::vector<std::string>&);

private:
    std::string filename;
    std::string pathToInput = "/Users/mattiamac/Documents/GitHub/progprocedurale/cpp/aoc/input/";
    std::string pathToOutput = "/Users/mattiamac/Documents/GitHub/progprocedurale/cpp/aoc/out/";
    std::vector<std::string> v;
};


#endif //PROGPROCEDURALE_READER_H
