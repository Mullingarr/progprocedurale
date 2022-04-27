//
//  main.cpp
//  Friend
//
//  Created by paolo massazza on 30/05/17.
//  Copyright © 2017 paolo massazza. All rights reserved.
//

#include <iostream>

class B;
class A{
    int a;
    void DoveSono(void){std::cout<<"oggetto allocato all'indirizzo: "<<this<<"\n";};
    friend class B;
public:
    A(int n){a=n;};
    void uses_class_B(B& b);
    void useB(B& b);
};
class B{
    int y;
    friend void A::uses_class_B(B&);
public:
    B(int n){x=n;};
    int x;
    void f(A& a){a.DoveSono();};
};
void A::uses_class_B(B& b){b.y++;};
//void A::useB(B& b){b.y++;}; //errore useB non è amica di B

int main(int argc, const char * argv[]) {
    // fate attenzione al passaggio per riferimento
    //provate a modificare A& in A e vedete cosa succede
    // spiegate il perché
    A aa(1);
    std::cout<<"oggetto aa allocato all'indirizzo: "<<&aa<<"\n";
    B bb(2);
    bb.f(aa);
    return 0;
}

