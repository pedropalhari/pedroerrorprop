#ifndef PROP_ERRO_H
#define PROP_ERRO_H

#include <iostream>
#include <cmath>

using namespace std;

class Num{
public:
    double valor, erro;
    
    Num(double i = 0, double j = 0);
    
    Num& operator+=(Num outro);
    Num operator+(Num outro);    
    friend Num operator+(double d, Num outro);
    
    Num& operator-=(Num outro);
    Num operator-(Num outro);    
    friend Num operator-(double d, Num outro);
    
    Num& operator*=(Num outro);
    Num operator*(Num outro);
    friend Num operator*(double d, Num outro);
    
    Num pow(double x);
    
    friend ostream& operator<<(ostream&, Num);

};

#endif /* PROP_ERRO_H */

