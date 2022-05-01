//
// Created by Mattia Lunardi on 28/04/22.
//

#include "Reader.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include <istream>
#include <sstream>


Reader::Reader() {filename = "input.txt";}

Reader::Reader(const std::string& filename){this->filename = filename;}

Reader::Reader(const std::string& filename, const std::string& pathToInput){
    this->filename = filename;
    this->pathToInput = pathToInput;
}
std::string Reader::getFilename(){return this->filename;}

void Reader::setFilename(std::string& filename){this->filename = filename;}

std::string Reader::getInputDir() {return this->pathToInput;}
void Reader::setInputDir(std::string &pathToInput){this->pathToInput = pathToInput;}
void Reader::setOutputDir(std::string& pathToOutput){this->pathToOutput = pathToOutput;}

std::vector<std::string> Reader::readInput() {
    std::cout<<"Reading started from file: " << this->Reader::getInputDir()
        << this->Reader::getFilename() <<".\n";
    std::fstream f(this->Reader::getInputDir()+"/"+this->Reader::getFilename());
    std::vector<std::string> ris;
    if(!f.is_open()){
        std::cout<<"Error opening the file\n";
        throw std::runtime_error("could not open file!");
    }
    else{
        std::string line;
        while(std::getline(f, line)){
            ris.push_back(line);
        }
    }
    return ris;
}

/**
 * Converts the passed vector of strings
 * to a vector of integers
 */
std::vector<int> Reader::convertVector(std::vector<std::string> &vec) {
    std::vector<int> ris;
    for(const auto& str : vec){
        ris.push_back(std::stoi(str));
    }
    return ris;
}

std::vector<std::string> Reader::tokenizeStrings(std::vector<std::string> &strings) {
    std::vector<std::string> tokenizedStrings;
    for(const auto&str : strings){
       char char_array[str.length() + 1];
       strcpy(char_array, str.c_str());
       for(int i = 0; i < str.length(); i++)
           tokenizedStrings.emplace_back(std::string(1, char_array[i])); //emplace_back vs push_back ?
    }
    return tokenizedStrings;
}






