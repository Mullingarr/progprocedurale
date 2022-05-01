//
// Created by Mattia Lunardi on 28/04/22.
//

#include "Reader.h"
#include <iostream>
#include <fstream>
#include <istream>


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
        << "/" << this->Reader::getFilename() <<".\n";
    std::fstream f(this->Reader::getInputDir()+"/"+this->Reader::getFilename());
    std::vector<std::string> ris;
    if(!f.is_open()){
        std::cout<<"Error opening the file\n";
        throw std::runtime_error("could not open file!");
    }
    else{
        std::string line;
        while(std::getline(f, line)) ris.push_back(line);
    }
    return ris;
}

std::vector<std::string> Reader::readAndTokenizeInput() {
    std::vector<std::string> input = readInput();
    std::vector<std::string> tokenizedInput;
    for(const auto& str : input){
       char arr[str.length() + 1];
       for(int i = 0; i < str.length(); i++) tokenizedInput.emplace_back(std::string(1, arr[i]));
    }
    return tokenizedInput;
}

