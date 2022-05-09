//
//  main.cpp
//  stack
//
//  Created by paolo massazza on 23/05/17.
//  Copyright © 2017 paolo massazza. All rights reserved.
//

#include <iostream>
using namespace std;

class complex{double re, im;
public: complex(double r=0.0,double i=0.0){re=r;im=i;};
    friend complex operator+(const complex&,const complex&);
    friend complex operator*(const complex&,const complex&);
    friend ostream& operator<<(ostream&,const complex&);
    ~complex(){cout<<"morte di un complesso all'indirizzo ->"<<this<<'\n';};
};

ostream& operator<<(ostream& s,const complex& z)
{return s<<'('<<z.re<<','<<z.im<<')';};

complex operator+(const complex& a,const complex& b)
{return  complex(a.re+b.re,a.im+b.im);};
complex operator*(const complex& a,const complex& b)
{return complex(a.re*b.re-a.im*b.im,a.re*b.im+a.im*b.re);};

template <class T>
class Stack{
    T* v; T* p;
    int sz;
    friend ostream& operator<<(ostream& os, const Stack<T>& c)
    {os<<'[';
        if(c.p!=c.v){
            for(int i=0;i<c.size();i++)
            {os<<*((c.p)-(i+1))<<' ';};
        }
        os<<']';
        return os;
    }
public:
    Stack(int s){v=p=new T[sz=s];} // s è la capacità massima
    ~Stack(){delete []v;}
    void push(T a){*p=a;++p;}
    T pop(){return *--p;}
    T top(){return *(p-1);}
    long size() const {return p-v;} // numero corrente di elementi
};


int main(int argc, const char * argv[]) {
    // insert code here...
    Stack<int> a(9);
    a.push(1);a.push(2);a.push(3);
    cout << "dimensione della pila: "<< a.size()<<'\n';
    cout << "Stato della pila: \n"<< a<<'\n';
    Stack<complex> b(10);
    complex c=complex();
    c=88+c;
    cout<<c<<'\n';
    b.push(c);
    cout << "Stato della pila: \n"<< b<<'\n';
    cout << "dimensione della pila: "<< b.size()<<'\n';
    
    return 0;
}
