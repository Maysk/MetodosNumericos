#include "../lib/imports.h"

Matrix::Matrix(){
    this->numberOfLines = 0;
    this->numberOfColumns = 0;
    this->content = NULL;
}


Matrix::Matrix(const Matrix &obj){
    this->numberOfLines = obj.numberOfLines;
    this->numberOfColumns = obj.numberOfColumns;
    this->content = new double*[numberOfLines];
    double aux;

    for(int i = 0; i < this->numberOfLines; i++){
        this->content[i] = new double[this->numberOfColumns];
        for(int j = 0; j < this->numberOfColumns; j++){
            aux = obj.getValue(i,j);
            this->setValue(i, j, aux);
        }
    }
}

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

double Matrix::getValue(int line, int column) const{
    return this->content[line][column];
}

int Matrix::getNumberOfLines() const{
    return this->numberOfLines;
}

int Matrix::getNumberOfColumns() const{
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

Matrix Matrix::normalizeVector(){
    double euclidianNorm = this->calculeVectorNorm();
    Matrix resultado = (*this) * (1/euclidianNorm);
    return resultado;
}

Matrix Matrix::vectorLineToColumn(){
    if(this->numberOfLines == 1 ){
        Matrix trans(this->numberOfColumns, 1);
        for(int i = 0; i < this->numberOfColumns; i++){
            trans.setValue(i,0,this->getValue(0,i));
        }
        return trans;
    }
    else{
        throw NOT_VECTOR;
    }
}
Matrix Matrix::vectorColumnToLine(){
    if(this->numberOfColumns == 1 ){
        Matrix trans(1, this->numberOfLines);
        for(int i = 0; i < this->numberOfLines; i++){
            trans.setValue(0,i,this->getValue(i,0));
        }
        return trans;
    }
    else{
        throw NOT_VECTOR;
    }
}


Matrix& Matrix::operator=(const Matrix& obj){
    this->numberOfLines = obj.numberOfLines;
    this->numberOfColumns = obj.numberOfColumns;
    this->content = new double*[numberOfLines];
    double aux;

    for(int i = 0; i < this->numberOfLines; i++){
        this->content[i] = new double[this->numberOfColumns];
        for(int j = 0; j < this->numberOfColumns; j++){
            aux = obj.getValue(i,j);
            this->setValue(i, j, aux);
        }
    }
    return *this;
}



Matrix Matrix::operator*(double scalar){
    Matrix matrixResultado(this->getNumberOfLines(), this->getNumberOfColumns());
    for(int i = 0; i < this->numberOfLines; i++){
        for(int j = 0; j < this->numberOfColumns; j++){
            matrixResultado.setValue(i,j, scalar * this->getValue(i,j));
        }
    }
    return matrixResultado;
}

Matrix Matrix::operator*(Matrix B){
    double resultadoDaPosicao;

    if(this->getNumberOfColumns() == B.getNumberOfLines()){
        Matrix matrixResultado(this->getNumberOfLines(), B.getNumberOfColumns());

        for(int i = 0; i < this->getNumberOfLines(); i++){
            for(int j = 0; j < B.getNumberOfColumns(); j++){
                resultadoDaPosicao = 0;
                for(int k = 0; k < this->getNumberOfColumns(); k++){
                    resultadoDaPosicao = resultadoDaPosicao + this->getValue(i,k) * B.getValue(k,j);
                }
                matrixResultado.setValue(i, j, resultadoDaPosicao);
            }
        }
        return matrixResultado;
    }else{
        throw NOT_MULTIPLIABLE;
    }

}


Matrix Matrix::operator-(Matrix B){

    if(this->getNumberOfLines() == B.getNumberOfLines() and this->getNumberOfColumns() == B.getNumberOfColumns()){
        Matrix matrixResultado(this->getNumberOfLines(), this->getNumberOfColumns());
        for(int i = 0; i<this->numberOfLines; i++){
            for(int j = 0; j<this->numberOfColumns; j++){
                matrixResultado.setValue(i,j, this->getValue(i,j) - B.getValue(i,j));
            }
        }
        return matrixResultado;
    }
    else{
        throw NOT_SUB;
    }
}

double Matrix::internProduct(Matrix B){
    double resultado = 0;
    if(this->numberOfColumns == B.getNumberOfLines() and this->numberOfLines == 1 and B.getNumberOfColumns() == 1){
        for(int i = 0; i < this->numberOfLines; i++){
            resultado = resultado + (this->getValue(0,i) * B.getValue(i,0));
        }
        return resultado;
    }
    else{
        throw GENERIC_ERROR;
    }

}

Matrix Matrix::getTransposedOfSquareMatrix(){
    if(this->isSquareMatrix()){
        Matrix trans(this->numberOfColumns, this->numberOfLines);
        for(int i=0; i<this->numberOfLines ; i++){
            for(int j=i; j<this->numberOfColumns; j++){
                trans.setValue(j, i, this->getValue(i,j));
                trans.setValue(i, j, this->getValue(j,i));
            }
        }
        return trans;
    }
    else{
        throw GENERIC_ERROR;
    }
}



Matrix Matrix::getInverse(){
    Matrix inverse = Matrix::generateIdentityMatrix(this->numberOfLines);
    Matrix original = (*this);
    double pivo;
    double posZerada;
    if(this->isSquareMatrix())

    for(int k=0; k < this->numberOfLines; k++){
        pivo=original.getValue(k, k);
        for(int j=k; j < this->numberOfLines; j++){
            original.setValue(k,j, original.getValue(k,j)/pivo);
        }
        for(int j=0; j < this->numberOfLines; j++){
            inverse.setValue(k,j, inverse.getValue(k,j)/pivo);
        }


        for(int i=0; i < this->numberOfLines; i++){
            if(i!=k){
                posZerada = original.getValue(i,k);
                for(int j=k; j < this->numberOfLines;j++){
                    original.setValue(i,j, original.getValue(i,j) - original.getValue(k,j)*posZerada);
                }
                for(int j=0; j < this->numberOfLines;j++){
                    inverse.setValue(i,j, inverse.getValue(i,j) - inverse.getValue(k,j)*posZerada);
                }
            }

        }
    }
    return inverse;
}



Matrix Matrix::getCopy(){
    Matrix matrixCopy(this->numberOfLines, this->numberOfColumns);
    for(int i = 0; i < this->numberOfLines; i++){
        for(int j = 0; j < this->numberOfColumns; j++){
            matrixCopy.setValue(i, j, this->getValue(i,j));
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


Matrix Matrix::generateIdentityMatrix(int numberOfLines){
    Matrix identity(numberOfLines, numberOfLines);
    for(int i = 0; i<numberOfLines; i++){
        identity.setValue(i,i,1);
    }
    return identity;
}


