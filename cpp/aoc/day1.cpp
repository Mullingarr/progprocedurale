//
// Created by Mattia Lunardi on 08/03/22.
//
#include "iostream"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "string"
#include "vector"
#include "fstream"

class Reader{
public:
    Reader(const std::string& filename);
    Reader();
    std::string getFilename();
    void setFilename(std::string&);
    std::vector<std::string> getStrings();

private:
    std::string filename;
    std::vector<std::string> v;
};

Reader::Reader(){
 std::cout<<"No filename specified, using default input file!\n";
 this->filename = "input.txt";
 std::cout<<"Input file set to: input.txt\n";
}
Reader::Reader(const std::string& filename){
    this->filename = filename;
    std::cout<<"Input file set to: " << filename << ".\n";
}

std::string Reader::getFilename(){
    return this->filename;
}

void Reader::setFilename(std::string& filename){
    this->filename = filename;
}

std::vector<std::string> Reader::getStrings() {
    std::cout<<"Reading started from file" << Reader::getFilename() <<".\n";
    std::ifstream f(Reader::getFilename());
    std::vector<std::string> ris;
    if(!f.is_open()){
        std::cout<<"Error opening the file";
        throw std::runtime_error("could not open file!");
    }
    else{
        std::string line;
        while(std::getline(f, line)){
            ris.push_back(line);
        }
    }
    return v;
}

int main(){

}
