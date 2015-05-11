#include "../lib/imports.h"
GaussHermite::GaussHermite(double tolerancia)
    :QuadraturaDeGauss(inicioDoIntervalo, finalDoIntervalo, tolerancia){}

double GaussHermite::funcao(double x){
    return exp(x);
}

double GaussHermite::somatorio(int grauDoPolinomio, double a, double b){
    double resultado;
    switch(grauDoPolinomio){
        case 2:
            resultado = 0.88622692 * exp(pow(-0.70710678, 2)) * funcao(-0.70710678)
                      + 0.88622692 * exp(pow(0.70710678, 2)) * funcao(0.70710678);
        break;
        case 3:
            resultado = 0.29540897 * exp(pow(-1.22474487, 2)) * funcao(-1.22474487)
                      + 1.18163590 * exp(pow(0,2)) * funcao(0)
                      + 0.29540897 * exp(pow(1.22474487, 2)) * funcao(1.22474487);
        break;
        case 4:
            resultado = 0.08131283 * exp(pow(-1.65068012, 2)) * funcao(-1.65068012)
                      + 0.80491409 * exp(pow(-0.52464762, 2)) * funcao(-0.52464762)
                      + 0.80491409 * exp(pow(0.52464762, 2)) * funcao(0.52464762)
                      + 0.08131283 * exp(pow(1.65068012, 2)) * funcao(1.65068012);
        break;

    }
    return resultado;
}
