#include "../lib/imports.h"

PotenciaComDeslocamento::PotenciaComDeslocamento(Matrix A, Matrix autovetorChute, double deslocamento):
    pInv(A - Matrix::generateIdentityMatrix(A.getNumberOfLines()) * deslocamento, autovetorChute){
    this->deslocamento = deslocamento;
}

double PotenciaComDeslocamento::getAutovalor(){
    double resultado = (1/pInv.getAutovalor())+deslocamento;
    return 1/resultado;
}

double PotenciaComDeslocamento::getDeslocamento(){
    return this->deslocamento;
}

Matrix PotenciaComDeslocamento::getAutovetor(){
    return pInv.getAutovetor();
}

Matrix PotenciaComDeslocamento::getAutovetorChute(){
    return pInv.getAutovetorChute();
}

Matrix PotenciaComDeslocamento::getMatrixADeslocada(){
    return pInv.getMatrixA();
}

Matrix PotenciaComDeslocamento::getMatrixInvDeAdeslocada(){
    return pInv.getMatrixInv();
}

void PotenciaComDeslocamento::solve(double precisao){
    pInv.solve(precisao);
}

