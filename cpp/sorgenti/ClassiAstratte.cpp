//
//  main.cpp
//  ClassiAstratte
//
//  Created by admin on 12/05/17.
//  Copyright © 2017 admin. All rights reserved.
//


#include <iostream>

class Articolo{
    int codice;
    int prezzo;
    int virtual iva()=0;
public:
    Articolo(int c,float p){codice=c;prezzo=p;};
    float prezzoiva(){return(prezzo+(prezzo*iva()/100));};
};

class ArticoloLusso:public Articolo{
    int prezzo;
    int virtual iva(){return 36;};
public:
    ArticoloLusso(int c,float p):Articolo(c,p){};
};

int main(int argc, const char * argv[]) {
    // insert code here...
    ArticoloLusso a=ArticoloLusso(1,100);
    
    
    std::cout << "Prezzo con iva:"<<a.prezzoiva()<<"\n";
    return 0;
}
