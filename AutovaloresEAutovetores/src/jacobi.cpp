#include "../lib/imports.h"

Jacobi::Jacobi(Matrix A):A(A){
    this->J = Matrix::generateIdentityMatrix(A.getNumberOfLines());
    this->Resultado = Matrix::generateIdentityMatrix(A.getNumberOfLines());
}

Matrix Jacobi::generateRotationMatrix(Matrix A, int i, int j){
    Matrix matrizDeRotacao = Matrix::generateIdentityMatrix(A.getNumberOfLines());
    double theta;
    if(A.getValue(i,i)!=A.getValue(j,j)){
        theta = atan(2*A.getValue(i,j)/(A.getValue(i,i)-A.getValue(j,j)))/2;
    }
    else{
        theta = M_PI/4;
    }
    matrizDeRotacao.setValue(i,i, cos(theta));
    matrizDeRotacao.setValue(i,j, -sin(theta));
    matrizDeRotacao.setValue(j,i, sin(theta));
    matrizDeRotacao.setValue(j,j, cos(theta));
    return matrizDeRotacao;
}

bool Jacobi::isDiagonal(Matrix A, double precisao){
    double tamanho = ((A.getNumberOfColumns())*(A.getNumberOfColumns()-1))/2;
    Matrix diagonalInferior(tamanho,1);
    double norma;
    int k = 0;
    for(int i=0;i<A.getNumberOfColumns()-1;i++){
        for(int j=i+1; j<A.getNumberOfLines(); j++){
            diagonalInferior.setValue(k,0, A.getValue(j,i));
            k++;
        }
    }

    norma = diagonalInferior.calculeVectorNorm();
    if(norma>precisao){
        return false;
    }
    else{
        return true;
    }

}

Matrix Jacobi::getMatrixA(){return this->A;}
Matrix Jacobi::getMatrixJ(){return this->J;}
Matrix Jacobi::getMatrixResultado(){return this->Resultado;}


void Jacobi::diagonalizarMatrix(double precisao){
    int numberOfLines = A.getNumberOfLines();
    Matrix JC = Matrix::generateIdentityMatrix(numberOfLines);
    Matrix JK;
    Matrix Ak = A;
    Matrix Jij;
    do{
        JK = Matrix::generateIdentityMatrix(numberOfLines);
        for(int j = 0; j<numberOfLines-1; j++){
            for(int i = j+1; i<numberOfLines; i++){
                Jij = this->generateRotationMatrix(Ak,i,j);
                Ak = Jij.getTransposedOfSquareMatrix()* Ak * Jij;
                JK=JK*Jij;
            }
        }
        JC = JC * JK;
    }while(!isDiagonal(Ak, precisao));
    this->J = JC;
    this->Resultado = Ak;
}

