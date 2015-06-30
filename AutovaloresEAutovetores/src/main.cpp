#include "../lib/imports.h"


int main(){
    Matrix* A = new Matrix(2,2);
    Matrix* x = new Matrix(2,1);
    x->setValue(0,0,2);
    x->setValue(1,0,2);

    A->setValue(0,0,-5);
    A->setValue(1,0,2);
    A->setValue(0,1,2);
    A->setValue(1,1,-2);

    PotenciaRegular p(x,A);
    p.solve(0.01);
    cout<<"fora"<<endl;
    p.getAutoVetor()->printMatrix();

}
