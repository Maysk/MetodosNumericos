#include "../lib/imports.h"
Householder::Householder(Matrix A):A(A){
    this->H = Matrix::generateIdentityMatrix(A.getNumberOfLines());
    this->T = A;
}

void Householder::setMatrixA(Matrix A){this->A = A;}

Matrix Householder::getMatrixA(){return this->A;}

Matrix Householder::getMatrixH(){return this->H;}

Matrix Householder::getMatrixT(){return this->T;}

int Householder::getSinal(double x){
    if(x<0){
        return -1;
    }
    else{
        return 1;
    }
}

void Householder::tridiagonalizar(){
    int k,i,j;
    int numberOfLines = A.getNumberOfLines();
    Matrix H = Matrix::generateIdentityMatrix(numberOfLines);
    Matrix T = A;
    Matrix Hj;
    Matrix Nj;
    Matrix P;
    Matrix PLinha;
    Matrix Aux;
    for(j=1; j <= numberOfLines-2; j++){
        //Comeco da fase construir Hj
        Hj = Matrix::generateIdentityMatrix(numberOfLines);
        //Construir nj
        Nj = Matrix(numberOfLines,1);
        P = Matrix(numberOfLines-j, 1);
        PLinha = Matrix(numberOfLines-j, 1);
        for(i=0, k = j; k<numberOfLines; k++, i++){
            P.setValue(i,0,T.getValue(k, j-1));
        }
        PLinha.setValue(0,0, -1*getSinal(P.getValue(0,0))*P.calculeVectorNorm());
        Aux = (P-PLinha).normalizeVector();
        for(i=0, k=j; k < numberOfLines; k++, i++){
            Nj.setValue(k,0,Aux.getValue(i,0));
        }
        //nj construido
        Hj = Hj - (Nj*Nj.vectorColumnToLine())*2;
        //Hj Construido
        T = Hj*T*Hj;
        H = H*Hj;
    }
    this->H = H;
    this->T = T;

}

