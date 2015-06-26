#include "../lib/imports.h"

Matrix::Matrix(int numberOfLines, int numberOfColumns){
    this->content = new double*[numberOfLines];
    this->numberOfLines = numberOfLines;
    this->numberOfColumns = numberOfColumns;

    for(int i=0; i < numberOfLines; i++){
        this->content[i] = new double[numberOfColumns];
        for(int j = 0; j < numberOfColumns; j++){
            this->content[i][j] = 0;
        }
    }
}

Matrix::~Matrix(){
    for(int i = 0; i<numberOfLines; i++){
        delete [] content[i];
    }
    delete [] content;
}

void Matrix::setValue(int line, int column, int newValue){
    this->content[line][column] = newValue;
}

double Matrix::getValue(int line, int column){
    return this->content[line][column];
}

int Matrix::getNumberOfLines(){
    return this->numberOfLines;
}

int Matrix::getNumberOfColumns(){
    return this->numberOfColumns;
}



Matrix* Matrix::multiplyMatrix(Matrix* A, Matrix* B){
    double resultadoDaPosicao;
    Matrix *matrixResultado;

    if(A->getNumberOfColumns() == B->getNumberOfLines()){
        matrixResultado = new Matrix(A->getNumberOfLines(), B->getNumberOfColumns());

        for(int i = 0; i < A->getNumberOfLines(); i++){
            for(int j = 0; j < B->getNumberOfColumns(); j++){
                resultadoDaPosicao = 0;
                for(int k = 0; k < A->getNumberOfColumns(); k++){
                    resultadoDaPosicao = resultadoDaPosicao + A->getValue(i,k) * B->getValue(k,j);
                }
                matrixResultado->setValue(i,j,resultadoDaPosicao);
            }
        }
        return matrixResultado;
    }else{
        throw NOT_MULTIPLIABLE;
    }

}

void Matrix::printMatrix(){
    for(int i = 0; i<numberOfLines;i++){
        cout << "[ ";
        for(int j = 0; j<numberOfColumns; j++){
            cout << this->content[i][j] << " ";
        }
        cout << "]" <<endl;
    }
    cout << endl;
}
