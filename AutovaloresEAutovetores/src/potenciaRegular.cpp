#include "../lib/imports.h"

PotenciaRegular::PotenciaRegular(Matrix* autovetorChute, Matrix* A){
    this->autovetorChute = autovetorChute;
    this->A = A;
}

void PotenciaRegular::solve(double precisao){
    Matrix* yPassado;
    Matrix* yAtual;
    Matrix* condicaoDeParada;
    yAtual = autovetorChute->normalizeVector();
    do{
        yAtual->printMatrix();
        yPassado = yAtual;
        yAtual = Matrix::multiplyMatrixByMatrix(A, yPassado);
        yAtual = yAtual->normalizeVector();
        condicaoDeParada = Matrix::subtractMatrixByMatrix(yAtual, yPassado);

        cout<<condicaoDeParada->calculeVectorNorm()<<endl;

    }while(condicaoDeParada->calculeVectorNorm() < precisao);

    this->autovetor = yAtual;
}

Matrix* PotenciaRegular::getAutoVetor(){
    return this->autovetor;
}
