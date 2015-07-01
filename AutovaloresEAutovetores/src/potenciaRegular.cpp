#include "../lib/imports.h"

PotenciaRegular::PotenciaRegular(const Matrix A, const Matrix autovetorChute): A(A), autovetorChute(autovetorChute){

}

void PotenciaRegular::solve(double precisao){
    Matrix yAtual = this->autovetorChute;
    Matrix ySeguinte;
    Matrix yAtualNormalizado;
    double lambdaAtual;
    double lambdaAnterior;

    yAtualNormalizado = yAtual.normalizeVector();
    ySeguinte = A * yAtualNormalizado;

    lambdaAtual = (yAtualNormalizado.vectorColumnToLine()*ySeguinte).getValue(0,0);


    do{
        yAtual = ySeguinte;
        lambdaAnterior = lambdaAtual;
        yAtualNormalizado = yAtual.normalizeVector();
        ySeguinte = A * yAtualNormalizado;
        lambdaAtual = (yAtualNormalizado.vectorColumnToLine()*ySeguinte).getValue(0,0);

    }while(abs(lambdaAtual - lambdaAnterior) > precisao);
    this->autovalor = lambdaAtual;
    this->autovetor = yAtualNormalizado;

}

Matrix PotenciaRegular::getAutovetor(){
    return this->autovetor;
}

double PotenciaRegular::getAutovalor(){
    return this->autovalor;
}
