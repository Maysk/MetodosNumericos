#include "../lib/imports.h"
GaussChebyshev::GaussChebyshev(){}

double GaussChebyshev::funcao(double x){
    return exp(x);
}

double GaussChebyshev::somatorio(int grauDoPolinomio){
    double resultado = 0;
    for(int k = 1; k<=grauDoPolinomio; k++ ){
        resultado = resultado + cos(((k-1)*M_PI)/grauDoPolinomio);

    }
    resultado = resultado * (M_PI/grauDoPolinomio);
    return resultado;
}

double GaussChebyshev::integrar(int grauDoPolinomioDesejado){
    double resultado = somatorio(grauDoPolinomioDesejado);
    return resultado;
}
