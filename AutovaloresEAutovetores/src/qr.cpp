#include "../lib/imports.h"
QR::QR(Matrix A):A(A){
    this->Q = Matrix::generateIdentityMatrix(A.getNumberOfLines());
    this->Resultado = Matrix::generateIdentityMatrix(A.getNumberOfLines());
}

Matrix QR::getMatrixA(){return this->A;}

Matrix QR::getMatrixQ(){return this->Q;}

Matrix QR::getMatrixResultado(){return this->Resultado;}


Matrix QR::generateRotationMatrix(Matrix A, int i, int j){
    Matrix matrizDeRotacao = Matrix::generateIdentityMatrix(A.getNumberOfLines());
    double theta;
    if(A.getValue(j,j)!=0){
        theta = atan(A.getValue(i,j)/A.getValue(j,j));
    }
    else{
        theta = M_PI/2;
    }
    matrizDeRotacao.setValue(i,i, cos(theta));
    matrizDeRotacao.setValue(i,j, sin(theta));
    matrizDeRotacao.setValue(j,i, -sin(theta));
    matrizDeRotacao.setValue(j,j, cos(theta));
    return matrizDeRotacao;
}

bool QR::isTriangularSuperior(Matrix A, double precisao){
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

void QR::transformarEmTriangularSuperior(double precisao){
    int numberOfLines = A.getNumberOfLines();
    Matrix QC = Matrix::generateIdentityMatrix(numberOfLines);
    Matrix QK;
    Matrix Ak = A;
    Matrix Qij;
    do{
        QK = Matrix::generateIdentityMatrix(numberOfLines);
        for(int j = 0; j<numberOfLines-1; j++){
            for(int i = j+1; i<numberOfLines; i++){
                Qij = this->generateRotationMatrix(Ak,i,j);
                Ak = Qij.getTransposedOfSquareMatrix() * Ak;
                QK=QK*Qij;
            }
        }
        QC = QC * QK;
    }while(!isTriangularSuperior(Ak, precisao));
    this->Q = QC;
    this->Resultado = Ak;

}

