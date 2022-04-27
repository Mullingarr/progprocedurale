//
//  main.cpp
//  Ambiguità
//
//  Created by admin on 08/05/17.
//  Copyright © 2017 admin. All rights reserved.
//

#include <iostream>

char p[]="mah";

class X {int e;
    public:
    int read(){return e;};
    X(int);X(char*);};

X::X(int a){e=a;};
X::X(char* a){e=*a;};

class Y {int e;
public:
    Y(int);};

Y::Y(int a){e = a;}

class Z {int e;
public:
    Z(X);};

Z::Z(X x){e=x.read();};

X f(X);
Y f(Y);
Z g(Z);

void h(double i){std::cout<<i*i;};

void h(X j){std::cout<<"X\n";};

void k1()
{
    //f(3); conversione ambigua
    //f(X(3));
    //f(Y(3));
    //g("mah"); //cpp non vuole concatenazione di conversioni (al massimo 1)
    //g(Z(X(p)));
}
void k2(){h(10);};

int main(int argc, const char * argv[]) {
    // insert code here...
    k2();
    return 0;
}
