//
//  main.cpp
//  provavirt
//
//  Created by admin on 12/05/17.
//  Copyright © 2017 admin. All rights reserved.
//

#include <iostream>

class B {
public:
    virtual char f() {return 'B';};
    char g() {return 'B';};
    char Testf() {return f();};
    char Testg() {return g();};
};

class D:public B {
public:
    char f() {return 'D';};
    char g() {return 'D';};
};

class E:public D {
public:
    char f() {return 'E';};
    char Testf() {return f();};
    char g() {return 'E';};
};

int main(int argc, const char * argv[]) {
    // insert code here...
    B b; D d; E e;
    std::cout <<"Valore restituito da b.Testf():"<< b.Testf()<<"\n";
    std::cout <<"Valore restituito da b.Testg():"<< b.Testg()<<"\n";
    std::cout <<"Valore restituito da d.Testf():"<< d.Testf()<<"\n";
    std::cout <<"Valore restituito da d.Testg():"<< d.Testg()<<"\n";
    std::cout <<"Valore restituito da d.f():"<< d.f()<<"\n";
    std::cout <<"Valore restituito da d.g():"<< d.g()<<"\n";
    std::cout <<"Valore restituito da e.Testf():"<< e.Testf()<<"\n";
    std::cout <<"Dimensione di un oggetto B:"<< sizeof(B)<<"\n";
    std::cout <<"Dimensione di un oggetto D:"<< sizeof(D)<<"\n";
    return 0;
}
