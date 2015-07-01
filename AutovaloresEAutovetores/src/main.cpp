#include "../lib/imports.h"


int main(){
    Matrix A(2,2);
    Matrix x(2,1);
    x.setValue(0,0,1);
    x.setValue(1,0,1);

    A.setValue(0,0,2);
    A.setValue(1,0, 1);
    A.setValue(0,1, 1);
    A.setValue(1,1,-5);

    /*Outro caso de teste

    Matrix A(3,3);
    Matrix x(3,1);
    x.setValue(0,0,1);
    x.setValue(1,0,1);
    x.setValue(2,0,1);

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


    cout<<"Matriz A: "<<endl;
    A.printMatrix();
    cout<<"chute x: "<<endl;
    x.printMatrix();

    PotenciaRegular p(A , x);

    p.solve(0.01);

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

}
