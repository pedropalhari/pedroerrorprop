#include "error_prop.h"

Num::Num(double i, double j) : valor(i), erro(j) {
}

Num& Num::operator+=(Num outro) {
    Num aux = *this + outro;
    
    *this = aux;
    
    return *this;
}

Num Num::operator+(Num outro) {
    double valor, erro;
    
    valor = this->valor + outro.valor;
    erro = sqrt(std::pow(this->erro, 2) + std::pow(outro.erro, 2));
    
    return Num(valor, erro);
}

Num operator+(double d, Num outro) {
    return outro + d;
}

Num& Num::operator-=(Num outro) {
    Num aux = *this - outro;
    
    *this = aux;
    
    return *this;
}

Num Num::operator-(Num outro) {
    double valor, erro;
    
    valor = this->valor - outro.valor;
    erro = sqrt(std::pow(this->erro, 2) + std::pow(outro.erro, 2));
    
    return Num(valor, erro);
}

Num operator-(double d, Num outro) {
    return outro - d;
}

Num& Num::operator*=(Num outro) {
    Num aux = *this * outro;
    
    *this = aux;
    
    return *this;
}


Num Num::operator*(Num outro) {
    double valor, erro;
    
    valor = this->valor * outro.valor;
    erro = valor * sqrt(std::pow(this->erro/this->valor, 2) + std::pow(outro.erro/outro.valor, 2));
    
    return Num(valor, erro);
}

Num operator*(double d, Num outro) {
    return outro * d;
}

ostream& operator<<(ostream& out, Num num) {
    out << num.valor << "!" << num.erro;
    return out;
}

Num Num::pow(double x) {    
    //O erro é calculado com o valor antes de elevar ele a uma potência
    this->erro = x*this->erro*this->valor;
    this->valor = std::pow(valor, x);
    
    return *this;
}



