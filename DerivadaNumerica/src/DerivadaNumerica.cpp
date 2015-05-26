#include "../lib/imports.h"
DerivadaNumerica::DerivadaNumerica(double deltaX){
    this->deltaX = deltaX;
}
void DerivadaNumerica::setDeltaX(double deltaX){
    this->deltaX = deltaX;
}

double DerivadaNumerica::getDeltaX(){
    return deltaX;
}

double DerivadaNumerica::funcao(double x){
    return pow(1+pow(x/2,2),2);
};
