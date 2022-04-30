//
// Created by Mattia Lunardi on 08/03/22.
//
#include "iostream"
#include "string"
#include "vector"
#include "fstream"
#include "utils/Reader.h"

int main(){
    Reader r;
    std::vector<std::string> lines = r.getStrings(r);
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
