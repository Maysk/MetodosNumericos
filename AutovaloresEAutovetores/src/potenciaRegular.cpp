#include "../lib/imports.h"

PotenciaRegular::PotenciaRegular(const Matrix A, const Matrix autovetorChute): A(A), autovetorChute(autovetorChute){

}

void PotenciaRegular::solve(double precisao){
    Matrix xAtual;
    Matrix xSeguinte;
    Matrix yAtual;
    double lambdaAtual;
    double lambdaAnterior;

    xAtual = this->autovetorChute;
    yAtual = xAtual.normalizeVector();
    xSeguinte = A * yAtual;

    lambdaAtual = (yAtual.vectorColumnToLine()*xSeguinte).getValue(0,0);

    do{
        yAtual = xSeguinte.normalizeVector();
        xSeguinte = A * yAtual;
        lambdaAnterior = lambdaAtual;
        lambdaAtual = (yAtual.vectorColumnToLine()*xSeguinte).getValue(0,0);

    }while(abs(lambdaAtual - lambdaAnterior) >= precisao);
    this->autovalor = lambdaAtual;
    this->autovetor = yAtual;

}

Matrix PotenciaRegular::getAutovetor(){
    return this->autovetor;
}

double PotenciaRegular::getAutovalor(){
    return this->autovalor;
}
