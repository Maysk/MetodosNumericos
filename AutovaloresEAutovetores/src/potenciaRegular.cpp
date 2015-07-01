#include "../lib/imports.h"

PotenciaRegular::PotenciaRegular(Matrix autovetorChute, Matrix A){
    this->autovetorChute = autovetorChute;
    this->A = A;
}

void PotenciaRegular::solve(double precisao){
    Matrix yAtual = this->autovetorChute;
    Matrix ySeguinte;
    Matrix yAtualNormalizado;
    double lambdaAtual;
    double lambdaAnterior;

    yAtualNormalizado = yAtual.normalizeVector();
    ySeguinte = A * yAtualNormalizado;

    lambdaAtual = (A*yAtualNormalizado).internProduct(yAtualNormalizado);



    do{
        yAtual = ySeguinte;
        lambdaAnterior = lambdaAtual;
        yAtualNormalizado = yAtual.normalizeVector();
        ySeguinte = A * yAtualNormalizado;
        lambdaAtual = (A*yAtualNormalizado).internProduct(yAtualNormalizado);

    }while(lambdaAtual - lambdaAnterior > precisao);
    this->autovalor = lambdaAtual;
    this->autovetor = yAtual;

}

Matrix PotenciaRegular::getAutovetor(){
    return this->autovetor;
}

double PotenciaRegular::getAutovalor(){
    return this->autovalor;
}
