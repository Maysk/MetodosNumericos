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


    cout<<"Matriz A: "<<endl;
    A.printMatrix();
    cout<<"chute x: "<<endl;
    x.printMatrix();

    PotenciaRegular p(A , x);

    p.solve(0.1);

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
