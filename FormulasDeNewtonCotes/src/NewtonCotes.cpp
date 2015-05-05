#include "../lib/imports.h"

double IntegracaoNumerica(double pontoInicial, double pontoFinal, int numeroDePartes, RegraEscolhida regraEscolhida){
    double somatorio = 0;
    double pontoAtual = pontoInicial;
    double tamanhoDeCadaParticao = (pontoFinal-pontoInicial)/numeroDePartes;
    for(int i = 0; i < numeroDePartes; i++){
        pontoAtual = pontoInicial + tamanhoDeCadaParticao * i;
        somatorio = (regraEscolhida)(pontoAtual, pontoAtual + tamanhoDeCadaParticao) + somatorio;
    }
    return somatorio;
}


double regraDoTrapezioFechado(double a, double b){
    double deltaX = (b-a)/2;
    return deltaX * (funcaoPolinomial(a) + funcaoPolinomial(b));
}


double regraDoTrapezioAberto(double a, double b){
    double deltaX = (b-a)/3;
    return ((3*deltaX)/2) * (funcaoPolinomial(a + deltaX) + funcaoPolinomial(a + 2*deltaX));
}


double regraDeSimpsonUmTercoFechado(double a, double b){
    double deltaX = (b-a)/2;
    return (deltaX/3) * (funcaoPolinomial(a) + 4*funcaoPolinomial((a+b)/2) + funcaoPolinomial(b));
}


double regraDeSimpsonUmTercoAberto(double a, double b){
    double deltaX = (b-a)/4;
    return ((4*deltaX)/3) * (2*funcaoPolinomial(a+deltaX) - funcaoPolinomial(a+2*deltaX) + 2*funcaoPolinomial(a+3*deltaX));
}


double regraDeSimpsonTresOitavosFechado(double a, double b){
    double deltaX = (b-a)/3;
    return ((3 * deltaX)/8) * (funcaoPolinomial(a) + 3*funcaoPolinomial(a+deltaX) + 3*funcaoPolinomial(a + 2*deltaX) + funcaoPolinomial(b));
}

double regraDeSimpsonTresOitavosAberto(double a, double b){
    double deltaX = (b-a)/5;
    return ((5 * deltaX)/24) * (11*funcaoPolinomial(a+deltaX) + funcaoPolinomial(a + 2*deltaX) + funcaoPolinomial(a + 3*deltaX) + 11*funcaoPolinomial(a + 4*deltaX));
}

double funcaoPolinomial(double x){
    return pow(1+pow(x/2,2),2);
}

