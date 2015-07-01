#include "../lib/imports.h"

PotenciaRegular::PotenciaRegular(Matrix* autovetorChute, Matrix* A){
    this->autovetorChute = autovetorChute;
    this->A = A;
}

void PotenciaRegular::solve(double precisao){
    Matrix* yPassado;
    Matrix* yAtual;
    Matrix* yPassadoNormalizado;
    Matrix* yAtualNormalizado;
    Matrix* aux;

    yAtual = this->autovetorChute;
    yAtualNormalizado = yAtual->normalizeVector();

    int i =0;
    do{
        i++;
        yAtual->printMatrix();
        yPassado = yAtual;
        yPassadoNormalizado = yAtualNormalizado;
        yAtual = Matrix::multiplyMatrixByMatrix(A,yPassado);
        yAtualNormalizado = yAtual->normalizeVector();
        aux = Matrix::subtractMatrixByMatrix(yAtualNormalizado, yPassadoNormalizado);
    }while( aux->calculeVectorNorm() > precisao);
    yAtual->printMatrix();
    this->autovetor = yAtual;
}

Matrix* PotenciaRegular::getAutoVetor(){
    return this->autovetor;
}
