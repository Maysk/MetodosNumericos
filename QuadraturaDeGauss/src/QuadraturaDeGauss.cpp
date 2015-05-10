#include "../lib/imports.h"

QuadraturaDeGauss::QuadraturaDeGauss(double inicioDoIntervalo, double finalDoIntervalo, double tolerancia){
    this->inicioDoIntervalo = inicioDoIntervalo;
    this->finalDoIntervalo = finalDoIntervalo;
    this->tolerancia = tolerancia;

}

double QuadraturaDeGauss::getInicioDoIntervalo(){
    return inicioDoIntervalo;
}
void QuadraturaDeGauss::setInicioDoIntervalo(double novoInicio){
    this->inicioDoIntervalo = novoInicio;
}

double QuadraturaDeGauss::getFinalDoIntervalo(){
    return finalDoIntervalo;
}
void QuadraturaDeGauss::setFinalDoIntervalo(double novoFinal){
    this->finalDoIntervalo = novoFinal;
}

double QuadraturaDeGauss::getTolerancia(){
    return tolerancia;
}
void QuadraturaDeGauss::setTolerancia(double novaTolerancia){
    this->tolerancia = novaTolerancia;
}

double QuadraturaDeGauss::funcaoPolinomial(double x){
     return pow(1+pow(x/2,2),2);
}

double QuadraturaDeGauss::integrar(int grauDoPolinomioDesejado){
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

    }while(abs(resultadoAtual - resultadoAnterior)<getTolerancia());

    return resultadoAtual;
}
