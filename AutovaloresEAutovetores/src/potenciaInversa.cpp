#include "../lib/imports.h"

PotenciaInversa::PotenciaInversa(const Matrix A, const Matrix autovetorChute): A(A), autovetorChute(autovetorChute){
    this->AInv = A.getInverse();
}

void PotenciaInversa::solve(double precisao){
    Matrix xAtual;
    Matrix xSeguinte;
    Matrix yAtual;
    double lambdaAtual;
    double lambdaAnterior;

    xAtual = this->autovetorChute; //x0
    yAtual = xAtual.normalizeVector(); //theta 0
    xSeguinte = AInv * yAtual; //x1

    lambdaAtual = (yAtual.vectorColumnToLine()*xSeguinte).getValue(0,0); //lambda0
    do{
        yAtual = xSeguinte.normalizeVector(); // theta i
        xSeguinte = AInv * yAtual; // xi+1
        lambdaAnterior = lambdaAtual;
        lambdaAtual = (yAtual.vectorColumnToLine()*xSeguinte).getValue(0,0); //lambda i = thetaT i * xi+1
    }while(abs(1/lambdaAtual - 1/lambdaAnterior) >= precisao);

    this->autovalor = 1/lambdaAtual;
    this->autovetor = yAtual;
}


Matrix PotenciaInversa::getMatrixA(){
    return this->A;
}

Matrix PotenciaInversa::getMatrixInv(){
    return this->AInv;
}

Matrix PotenciaInversa::getAutovetorChute(){
    return this->autovetorChute;
}


Matrix PotenciaInversa::getAutovetor(){
    return this->autovetor;
}

double PotenciaInversa::getAutovalor(){
    return this->autovalor;
}
