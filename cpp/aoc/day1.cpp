//
// Created by Mattia Lunardi on 08/03/22.
//
#include "iostream"
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
    std::string pathToInput = "/Users/mattiamac/Documents/GitHub/progprocedurale/cpp/aoc/input/";
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
    std::cout<<"Reading started from file: " << Reader::getFilename() <<".\n";
    std::ifstream f(pathToInput+Reader::getFilename());
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

void convertVector(const std::vector<std::string>& v, std::vector<int>& ris){
    for(const auto& s : v)
        ris.push_back(std::stoi(s));
}

int main(){
    Reader r;
    std::vector<std::string> lines = r.getStrings();
    std::vector<int> nums;
    std::cout << "v size: " << lines.size() << "\n";
    convertVector(lines, nums);

    /**
     * for(const auto& n : nums)
        std::cout << n << "\n";
     */
    int depth = nums.at(0);
    int count = 0;
    int num = 0;

    int q = 0;
    for(int i = 1; i < nums.size(); i++){
        num = nums.at(i);
        if(num > depth){
            //std::cout << num << "+" << depth << "\n";
            depth = num;
            count++;
            //std::cout << count << "\n";
        }
        else{
            std::cout << num << "<" << depth << "\n";
            q++;
        }
    }

    std::cout<< "count: " << count << "\n";
    std::cout<< "q: " << q << "\n";
}
