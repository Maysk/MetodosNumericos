#include "../lib/imports.h"


int main(){
    Matrix *m = new Matrix(2,2);
    m->setValue(0,0,2);
    m->printMatrix();
    Matrix *t = Matrix::multiplyMatrixByMatrix(m,m);
    t->printMatrix();
    Matrix* k = Matrix::multiplyMatrixByScalar(m,5);
    k->printMatrix();
    return 0;
}
