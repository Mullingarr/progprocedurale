//
//  main.cpp
//  Creazione Oggetti
//
//  Created by admin on 15/05/18.
//  Copyright © 2018 admin. All rights reserved.
//


#include <iostream>
#include <string>
using namespace std;

class Demo
{
public:
    Demo(const char* nm);
    ~Demo();
private:
    char name[20];
};

Demo::Demo(const char* nm)
{
    strncpy(name, nm, 20);
    cout<<"Costruttore chiamato per "<<name<<'\n';
    
}

Demo::~Demo()
{
    cout<<"Distruttore chiamato per "<<name<<'\n';
}


class DemoD:public Demo
{
public:
    DemoD(const char*,const char*);
    ~DemoD();
private:
    Demo secondname=("SecondoNome");
    char surname[20];
};

DemoD::DemoD(const char* nm,const char* sr):Demo(nm)
{
    strncpy(surname, sr, 20);
    cout<<"Costruttore chiamato per "<<surname<<'\n';
    
}

DemoD::~DemoD()
{
    cout<<"Distruttore chiamato per "<<surname<<'\n';
}



int main(int argc, const char * argv[]) {
    // insert code here...
    DemoD nome("Paolo","Massazza");
    return 0;
}
