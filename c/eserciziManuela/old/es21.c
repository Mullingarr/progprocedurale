//
// Created by Mattia Lunardi on 11/02/22.
//

#include <stdio.h>
#include <math.h>

double P(double a);
double R(double b);
double S(double x, double y);

int main()
{
    double n, m;
    //double p, r, var;
    double s;
    printf("Inserire due numeri\n");
    scanf("%lf", &n);
    scanf("%lf", &m);
    //p = P(n);
    //var = n - m;
    //r = R(var);
    //s = S(p, r);
    s = S(P(n), R(n-m));
    printf("Il valore dell'espressione e' %f\n", s);
    return 0;
}

double P(double a)
{
    double quadrato = a*a;
    double cubo = pow(a, 3);
    return quadrato - cubo + sin(a);
}

double R(double b)
{
    return sqrt(b*b + 12);
}

double  S(double x, double y)
{
    return (13*x) + ((x + y) / 3);
}