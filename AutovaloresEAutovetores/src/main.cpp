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

    A->printMatrix();

    x->printMatrix();


    c = x->normalizeVector();
    cout<<x->calculeVectorNorm()<<endl;


}
