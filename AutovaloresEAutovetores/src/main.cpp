#include "../lib/imports.h"


int main(){
    Matrix *m = new Matrix(2,2);
    m->setValue(0,0,1);
    m->printMatrix();
    Matrix *t = Matrix::multiplyMatrix(m,m);
    t->printMatrix();
    return 0;
}
