#include "../lib/imports.h"


int main(){
    Matrix* A = new Matrix(2,2);
    Matrix* x = new Matrix(2,1);
    Matrix* c;
    x->setValue(0,0,2);
    x->setValue(1,0,2);

    A->setValue(0,0,1);
    A->setValue(1,0,2);
    A->setValue(0,1,4);
    A->setValue(1,1,3);

    c = Matrix::multiplyMatrixByMatrix(A, x);
    c->printMatrix();
    c = x->normalizeVector();
    c->printMatrix();

    /*
    double a = x->calculeVectorNorm();
    a = 1/a;
    cout<< x->getValue(0,0)*a<<endl;

    c = Matrix::multiplyMatrixByScalar(x, a);
    cout<<c->getValue(0,0)<<endl;

    cout<<x->calculeVectorNorm()<<endl;

    */
}
