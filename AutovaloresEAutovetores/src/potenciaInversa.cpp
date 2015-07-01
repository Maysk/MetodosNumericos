#include "../lib/imports.h"

PotenciaInversa::PotenciaInversa(const Matrix AInv, const Matrix autovetorChute): AInv(AInv), autovetorChute(autovetorChute){

}

void PotenciaInversa::solve(double precisao){
    Matrix yAtual = this->autovetorChute;
    Matrix ySeguinte;
    Matrix yAtualNormalizado;
    double lambdaAtual;
    double lambdaAnterior;

    yAtualNormalizado = yAtual.normalizeVector();
    ySeguinte = AInv * yAtualNormalizado;

    lambdaAtual = (ySeguinte.vectorColumnToLine()).internProduct(yAtualNormalizado);

    do{
        yAtual = ySeguinte;
        lambdaAnterior = lambdaAtual;
        yAtualNormalizado = yAtual.normalizeVector();
        ySeguinte = AInv * yAtualNormalizado;
        lambdaAtual = (ySeguinte.vectorColumnToLine()).internProduct(yAtualNormalizado);
    }while(lambdaAtual - lambdaAnterior > precisao);
    this->autovalor = 1/lambdaAtual;
    this->autovetor = yAtual;

}

Matrix PotenciaInversa::getAutovetor(){
    return this->autovetor;
}

double PotenciaInversa::getAutovalor(){
    return this->autovalor;
}
