//
//  main.cpp
//  ErediMulti
//
//  Created by admin on 12/05/17.
//  Copyright © 2017 admin. All rights reserved.
//

#include <iostream>

class A{
    public:
     int a=1;
    int get1(){return this->a;};
    int virtual get2(){return a;};
};

class B:  public  A{
    int cc;
    public:
    int a=2;
    int virtual get2(){return a;};
};

class C:  public A{
    public:
   // int virtual get2(){return 10;};
    int c;};

class D:public  B, public C,  public A{
    int d;int virtual get2(){return B::a++;};};


int main(int argc, const char * argv[]) {
    // insert code here...
    A aobj;
    B bobj;
    B bbobj;
    B& f=bbobj;
    A* pa;
    B* pb;
    D ob;
    pb=&ob;
    pb->get2();
    // pa=&ob; // ambiguità: più indirizzi corrispondenti a oggetti di tipo A
    std::cout << "indirizzo di ob:"<<&ob<<'\n';
    //<< pa <<'\n'<<
    std::cout << "Dimensione di A: "<<sizeof(A)<<'\n';
    std::cout << "Dimensione di B: "<<sizeof(B)<<'\n';
    std::cout << "Dimensione di C: "<<sizeof(C)<<'\n';
    std::cout << "Dimensione di D: "<<sizeof(D)<<'\n';
    
    
    std::cout<<"valore di pb:"<<pb<<'\n';
    std::cout << bobj.get2() <<'\n';
    return 0;
}
