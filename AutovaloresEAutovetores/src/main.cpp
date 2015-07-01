#include "../lib/imports.h"


int main(){
    Matrix A(2,2);
    Matrix x(2,1);
    x.setValue(0,0,1);
    x.setValue(1,0,1);

    A.setValue(0,0,2);
    A.setValue(1,0, 1);
    A.setValue(0,1, -12);
    A.setValue(1,1,-5);


    PotenciaRegular p(x , A);
    p.solve(0.0001);
    cout<<"fora"<<endl;
    p.getAutovetor().printMatrix();


}
