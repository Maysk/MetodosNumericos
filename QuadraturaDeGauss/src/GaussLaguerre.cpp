#include "../lib/imports.h"

GaussLaguerre::GaussLaguerre(){}

double GaussLaguerre::funcao(double x){
    return exp(pow(-x,2));
}

double GaussLaguerre::somatorio(int grauDoPolinomio){
    double resultado;
    switch(grauDoPolinomio){
        case 2:
            resultado = 0.85355339 * exp(0.58578643) * funcao(0.58578643)
                      + 0.14644660 * exp(3.41421356) * funcao(3.41421356);
        break;
        case 3:
            resultado = 0.71109300 * exp(0.41577455) * funcao(0.41577455)
                      + 0.27851973 * exp(2.24428036) * funcao(2.24428036)
                      + 0.01038926 * exp(6.28994508) * funcao(6.28994508);
        break;
        case 4:
            resultado = 0.60315410 * exp(0.32254768) * funcao(0.32254768)
                      + 0.35741869 * exp(1.74576110) * funcao(1.74576110)
                      + 0.03888791 * exp(4.53662029) * funcao(4.53662029)
                      + 0.00053929 * exp(9.39507091) * funcao(9.39507091);
        break;

    }
    return resultado;
}

double GaussLaguerre::integrar(int grauDoPolinomioDesejado){
    double resultado = somatorio(grauDoPolinomioDesejado);
    return resultado;
}
