#include "../lib/imports.h"

Matrix::Matrix(int numberOfLines, int numberOfColumns){
    this->content = new double*[numberOfLines];
    this->numberOfLines = numberOfLines;
    this->numberOfColumns = numberOfColumns;

    if(this->numberOfColumns == 0 or this->numberOfLines == 0){
        throw INVALID_MATRIX;
    }

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

void Matrix::setValue(int line, int column, double newValue){
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

bool Matrix::isSquareMatrix(){
    if(this->numberOfColumns==this->numberOfLines){
        return true;
    }
    return false;
}

double Matrix::calculeVectorNorm(){
    double normaEuclidiana = 0;
    if(this->getNumberOfColumns()==1){
        for(int i=0; i<this->getNumberOfLines(); i++){
            normaEuclidiana = normaEuclidiana + pow(this->getValue(i,0),2);
        }
        return sqrt(normaEuclidiana);

    }else if(this->getNumberOfLines()==1){
        for(int i=0; i<this->getNumberOfColumns(); i++){
            normaEuclidiana = normaEuclidiana + pow(this->getValue(0,i),2);
        }
        return sqrt(normaEuclidiana);
    }
    else{
        throw NOT_VECTOR;
    }
}

Matrix* Matrix::normalizeVector(){
    double euclidianNorm = this->calculeVectorNorm();
    Matrix* resultado = Matrix::multiplyMatrixByScalar(this, 1/euclidianNorm);
    return resultado;
}




Matrix* Matrix::multiplyMatrixByScalar(Matrix *A, double scalar){
    Matrix *matrixResultado = new Matrix(A->getNumberOfLines(), A->getNumberOfColumns());
    for(int i = 0; i<A->numberOfLines; i++){
        for(int j = 0; j<A->numberOfColumns; j++){
            matrixResultado->setValue(i,j, scalar * A->getValue(i,j));
        }
    }
    return matrixResultado;

}


Matrix* Matrix::multiplyMatrixByMatrix(Matrix* A, Matrix* B){
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


Matrix* Matrix::subtractMatrixByMatrix(Matrix* A, Matrix* B){
    Matrix *matrixResultado = new Matrix(A->getNumberOfLines(), A->getNumberOfColumns());
    for(int i = 0; i<A->numberOfLines; i++){
        for(int j = 0; j<A->numberOfColumns; j++){
            matrixResultado->setValue(i,j, A->getValue(i,j) - B->getValue(i,j));
        }
    }
    return matrixResultado;
}

Matrix* Matrix::getCopy(){
    Matrix* matrixCopy = new Matrix(this->numberOfLines, this->numberOfColumns);
    for(int i = 0; i<this->numberOfLines; i++){
        for(int j =0; j<this->numberOfColumns; j++){
            matrixCopy->setValue(i, j, this->getValue(i,j));
        }
    }
    return matrixCopy;
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
