#include "../lib/imports.h"

GaussLaguerre::GaussLaguerre(double inicioDoIntervalo, double finalDoIntervalo, double tolerancia)
    :QuadraturaDeGauss(inicioDoIntervalo, finalDoIntervalo, tolerancia){}

double GaussLaguerre::funcao(double x){
    return exp(pow(-x,2));
}
double GaussLaguerre::mudancaDeVariavel(double x, double a, double b){
    return (a+b)/2 + ((b-a)*x)/2;
}
double GaussLaguerre::somatorio(int grauDoPolinomio, double a, double b){
    double resultado;
    switch(grauDoPolinomio){
        case 2:
            resultado = ((b-a)/2) * (funcao(mudancaDeVariavel(-0.577350269, a, b))
                                     + funcao(mudancaDeVariavel(0.577350269, a, b)));
        break;
        case 3:
            resultado = ((b-a)/2) * (0.555555556 * funcao(mudancaDeVariavel(-0.774596669, a, b))
                                     + 0.888888889 * funcao(mudancaDeVariavel(0, a, b))
                                     + 0.555555556 * funcao(mudancaDeVariavel(0.774596669,a,b)));
        break;
        case 4:
            resultado = ((b-a)/2) * (0.347854845 * funcao(mudancaDeVariavel(-0.861136312, a, b))
                                     + 0.652145155 * funcao(mudancaDeVariavel(-0.339981043, a, b))
                                     + 0.652145155 * funcao(mudancaDeVariavel(0.339981043,a,b))
                                     + 0.347854845 * funcao(mudancaDeVariavel(0.861136312,a,b)));
        break;

    }
    return resultado;
}
