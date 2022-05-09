//
//  main.cpp
//  complessi
//
//  Created by admin on 24/05/18.
//  Copyright © 2018 admin. All rights reserved.
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

void f(void){
    complex a(1,3.1);complex b(1.2,2);complex c=b;
    a=b+c;//uso abbreviato
    b=operator+(a,c);//uso esplicito
    b=b+c*a;
    cout<<b<<'\n';
    c=a*b+complex(1,2);
    cout<<1+c<<'\n';
}

complex operator+(const complex& a,const complex& b)
{return  complex(a.re+b.re,a.im+b.im);};
complex operator*(const complex& a,const complex& b)
{return complex(a.re*b.re-a.im*b.im,a.re*b.im+a.im*b.re);};

int main(int argc, const char * argv[]) {
    // insert code here...
    f();
    return 0;
}
