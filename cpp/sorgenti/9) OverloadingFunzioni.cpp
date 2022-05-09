//
//  main.cpp
//  Overloading
//
//  Created by paolo massazza on 17/05/17.
//  Copyright © 2017 paolo massazza. All rights reserved.
//

#include <iostream>


void print(double d){std::cout <<"questo è un double->"<< d<<"\n";};

void print(long d)
{std::cout << "questo è un long->"<<d<<"\n";};

int f(short i){return i;};
int f(int& i){return 2*i;};
int f(long i){return 3*i;};

void f(char* n){};
// void f(char v[]){};

int h(int primo, char secondo){return primo*primo;};
int h(char primo, int secondo){return secondo*secondo;};
int h(int r){return r*r;};
// int h(const int r){return r*r;};


int main(int argc, const char * argv[]) {
    // insert code here...
    int a=1;
    int& aref=a;
    print((double)a);
    std::cout << h(1,3.4)<<"\n";
    std::cout <<f(a) <<"\n";
   // std::cout <<f(a) <<"\n";
    return 0;
}
