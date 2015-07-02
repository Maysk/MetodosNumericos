#include "../lib/imports.h"


int main(){

/*
    Matrix A(2,2);
    Matrix x(2,1);
    x.setValue(0,0,1);
    x.setValue(1,0,1);

    A.setValue(0,0,2);
    A.setValue(1,0, 1);
    A.setValue(0,1, 1);
    A.setValue(1,1,-5);

*/
    /*Outro caso de teste

    Matrix A(3,3);
    Matrix x(3,1);
    x.setValue(0,0,2);
    x.setValue(1,0,9);
    x.setValue(2,0,7);

    A.setValue(0,0,10);
    A.setValue(0,1,6);
    A.setValue(0,2,4);
    A.setValue(1,1,6);
    A.setValue(1,2,2);
    A.setValue(1,0,6);
    A.setValue(2,0,4);
    A.setValue(2,1,2);
    A.setValue(2,2,8);

*/

/*mais um caso de teste: */

    Matrix A(4,4);

    A.setValue(0,0,4);
    A.setValue(0,1,3);
    A.setValue(0,2,2);
    A.setValue(0,3,1);

    A.setValue(1,0,3);
    A.setValue(1,1,6);
    A.setValue(1,2,1);
    A.setValue(1,3,4);

    A.setValue(2,0,2);
    A.setValue(2,1,1);
    A.setValue(2,2,8);
    A.setValue(2,3,2);

    A.setValue(3,0,1);
    A.setValue(3,1,4);
    A.setValue(3,2,2);
    A.setValue(3,3,10);

/*
    cout<<"Matriz A: "<<endl;
    A.printMatrix();
    cout<<"chute x: "<<endl;
    x.printMatrix();

    PotenciaRegular p(A , x);
    p.solve(0.0001);

    cout<<"Autovetor: "<<endl;
    p.getAutovetor().printMatrix();
    cout<<"Autovalor: "<<endl;
    cout<<p.getAutovalor()<<endl;
    Matrix u = A * p.getAutovetor();
    Matrix v = p.getAutovetor() * p.getAutovalor();
    cout<<"A*autovetor: "<<endl;
    u.printMatrix();
    cout<<"autovetor*autovalor: "<<endl;
    v.printMatrix();

    cout<<"\n\n Inversa de A:"<<endl;
    Matrix AInv = A.getInverse();
    AInv.printMatrix();

    PotenciaInversa pinv(AInv , x);
    pinv.solve(0.0001);

    cout<<"Autovetor: "<<endl;
    pinv.getAutovetor().printMatrix();
    cout<<"Autovalor: "<<endl;
    cout<<pinv.getAutovalor()<<endl;
    Matrix w = A * pinv.getAutovetor();
    Matrix z = pinv.getAutovetor() * pinv.getAutovalor();
    cout<<"A*autovetor: "<<endl;
    w.printMatrix();
    cout<<"autovetor*autovalor: "<<endl;
    z.printMatrix();
*/

/*
    Householder h(A);
    h.tridiagonalizar();
    Matrix resultado = h.getMatrixT();
    Matrix matrixHouse = h.getMatrixH();
    matrixHouse.printMatrix();
    resultado.printMatrix();
    (matrixHouse.getTransposedOfSquareMatrix()*A*matrixHouse).printMatrix();
*/
    Jacobi jacobi(A);
    jacobi.diagonalizarMatrix(0.0001);
    jacobi.getMatrixResultado().printMatrix();

}
