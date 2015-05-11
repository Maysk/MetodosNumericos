#include "../lib/imports.h"
GaussLegendre::GaussLegendre(double inicioDoIntervalo, double finalDoIntervalo, double tolerancia){
    this->inicioDoIntervalo = inicioDoIntervalo;
    this->finalDoIntervalo = finalDoIntervalo;
    this->tolerancia = tolerancia;
}

double GaussLegendre::getInicioDoIntervalo(){
    return inicioDoIntervalo;
}
void GaussLegendre::setInicioDoIntervalo(double novoInicio){
    this->inicioDoIntervalo = novoInicio;
}

double GaussLegendre::getFinalDoIntervalo(){
    return finalDoIntervalo;
}
void GaussLegendre::setFinalDoIntervalo(double novoFinal){
    this->finalDoIntervalo = novoFinal;
}

double GaussLegendre::getTolerancia(){
    return tolerancia;
}
void GaussLegendre::setTolerancia(double novaTolerancia){
    this->tolerancia = novaTolerancia;
}

double GaussLegendre::funcao(double x){
    return exp(x);
}
double GaussLegendre::mudancaDeVariavel(double x, double a, double b){
    return (a+b)/2 + ((b-a)*x)/2;
}
double GaussLegendre::somatorio(int grauDoPolinomio, double a, double b){
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


double GaussLegendre::integrar(int grauDoPolinomioDesejado){
    int numeroDeParticoes;
    double tamanhoDeCadaParticao;
    double pontoAtual;
    double tamanhoTotal;
    double resultadoAnterior;
    double resultadoAtual;

    numeroDeParticoes = 1;
    tamanhoTotal = getFinalDoIntervalo() -  getInicioDoIntervalo();
    resultadoAtual = somatorio(grauDoPolinomioDesejado, getInicioDoIntervalo(), getFinalDoIntervalo());

    do{
        numeroDeParticoes++;
        tamanhoDeCadaParticao = tamanhoTotal/numeroDeParticoes;
        pontoAtual = getInicioDoIntervalo();
        resultadoAnterior = resultadoAtual;
        resultadoAtual = 0;

        for(int i=1; i<=numeroDeParticoes; i++){
            resultadoAtual = resultadoAtual + somatorio(grauDoPolinomioDesejado, pontoAtual, pontoAtual + tamanhoDeCadaParticao);
            pontoAtual = pontoAtual + tamanhoDeCadaParticao;
        }

    }while(abs(resultadoAtual - resultadoAnterior) > getTolerancia());

    return resultadoAtual;
}
