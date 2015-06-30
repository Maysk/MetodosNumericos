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

    yAtual = this->autovetorChute;
    yAtualNormalizado = yAtual->normalizeVector();
    do{
        yPassado = yAtual;
        yPassadoNormalizado = yAtualNormalizado;
        yAtual = Matrix::multiplyMatrixByMatrix(A,yPassadoNormalizado);
        yAtualNormalizado = yAtual->normalizeVector();
        this->autovetor = Matrix::multiplyMatrixByMatrix(yAtualNormalizado->getTransposed(), Matrix::multiplyMatrixByMatrix(A, yAtualNormalizado));
        this->autovetor->printMatrix();
        cout<<"passouaqui"<<endl;
    }while(Matrix::subtractMatrixByMatrix(yAtual, yPassado)->calculeVectorNorm() < precisao);

    this->autovetor = yAtual;
}

Matrix* PotenciaRegular::getAutoVetor(){
    return this->autovetor;
}
