#include "../lib/imports.h"


int main(){

/*  Caso de teste 0:
    Matrix A(3,3);
    A.setValue(0,0,4);    A.setValue(0,1,2);    A.setValue(0,2,1);
    A.setValue(1,1,2);    A.setValue(1,2,8);    A.setValue(1,0,2);
    A.setValue(2,0,1);    A.setValue(2,1,2);    A.setValue(2,2,6);

    Matrix x(3,1);
    x.setValue(0,0,2);     x.setValue(1,0,9);     x.setValue(2,0,7);


//*/

/*  Caso de teste 1
    Matrix A(2,2);
    Matrix x(2,1);
    x.setValue(0,0,1);
    x.setValue(1,0,1);

    A.setValue(0,0,2);
    A.setValue(1,0, 1);
    A.setValue(0,1, 1);
    A.setValue(1,1,-5);

//*/

/*  Caso de Teste 2:*/
    Matrix x(3,1);
    x.setValue(0,0,2);     x.setValue(1,0,9);     x.setValue(2,0,7);

    Matrix A(3,3);
    A.setValue(0,0,10);    A.setValue(0,1,6);     A.setValue(0,2,4);
    A.setValue(1,1,6);     A.setValue(1,2,2);     A.setValue(1,0,6);
    A.setValue(2,0,4);     A.setValue(2,1,2);     A.setValue(2,2,8);


//*/

/*  Caso de Teste 3:

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
//*/

/*  Metodos da potencia Demo
    cout <<"-- Entrada --"<<endl;
    cout<<"Matriz A: "<<endl;
    A.printMatrix();
    cout<<"chute x: "<<endl;
    x.printMatrix();

    cout <<"-------------------- Metodo da Potencia Regular---------------------"<<endl;

    PotenciaRegular p(A , x);
    p.solve(0.00001);
    cout<<"Autovetor: "<<endl;
    p.getAutovetor().printMatrix();
    cout<<"Autovalor: "<<endl;
    cout<<p.getAutovalor()<<endl<<endl;
    Matrix u = A * p.getAutovetor();
    Matrix v = p.getAutovetor() * p.getAutovalor();
    cout<<"A*autovetor: "<<endl;
    u.printMatrix();
    cout<<"autovetor*autovalor: "<<endl;
    v.printMatrix();

    cout <<"-------------------- Metodo da Potencia Inversa---------------------"<<endl;

    PotenciaInversa pinv(A , x);
    pinv.solve(0.00001);

    cout<<"Autovetor: "<<endl;
    pinv.getAutovetor().printMatrix();
    cout<<"Autovalor: "<<endl;
    cout<<pinv.getAutovalor()<<endl<<endl;
    Matrix w = A * pinv.getAutovetor();
    Matrix z = pinv.getAutovetor() * pinv.getAutovalor();
    cout<<"A*autovetor: "<<endl;
    w.printMatrix();
    cout<<"autovetor*autovalor: "<<endl;
    z.printMatrix();

    cout <<"-------------------- Metodo da Potencia com deslocamento ---------------------"<<endl;

    PotenciaComDeslocamento pdeslocameno(A , x, 9);
    pdeslocameno.solve(0.00001);
    cout<<"Matrix A"<<endl;
    A.printMatrix();
    cout<<"Matrix A deslocada: "<<endl;
    pdeslocameno.getMatrixADeslocada().printMatrix();
    cout<<"Autovetor: "<<endl;
    pdeslocameno.getAutovetor().printMatrix();
    cout<<"Autovalor: "<<endl;
    cout<<pdeslocameno.getAutovalor()<<endl<<endl;
    Matrix r = A * pdeslocameno.getAutovetor();
    Matrix t = pdeslocameno.getAutovetor() * pdeslocameno.getAutovalor();
    cout<<"A*autovetor: "<<endl;
    r.printMatrix();
    cout<<"autovetor*autovalor: "<<endl;
    t.printMatrix();


//*/

/*  Householder Demo*/
    cout<<"\n\n------------- Metodo Householder -----------------"<<endl;
    cout<<"--- Matrix A ---"<<endl;
    A.printMatrix();
    Householder h(A);
    h.tridiagonalizar();
    cout <<"--- A TriDiagonalizada T---" << endl;
    h.getMatrixT().printMatrix();
    cout <<"--- Matriz de Householder H---" << endl;
    h.getMatrixH().printMatrix();
    cout <<"--- Ht * A * H---" << endl;
    (h.getMatrixH().getTransposedOfSquareMatrix()*A*h.getMatrixH()).printMatrix();
//*/

/* Jacobi Demo */
    cout<<"\n\n------------- Metodo Jacobi -----------------"<<endl;
    cout<<"--- Matrix A ---"<<endl;
    A.printMatrix();
    Jacobi jacobi(A);
    jacobi.diagonalizarMatrix(0.0001);
    cout <<"--- A Diagonalizada ---" << endl;
    jacobi.getMatrixResultado().printMatrix();
    cout <<"--- J Resultante ---" <<endl;
    jacobi.getMatrixJ().printMatrix();
//

/*  QR Demo*/
    cout<<"\n\n------------- Metodo QR -----------------"<<endl;
    cout<<"--- Matrix A ---"<<endl;
    A.printMatrix();
    QR qr(A);
    qr.transformarEmTriangularSuperior(0.001);
    cout <<"--- Triangular resultante ---" << endl;
    qr.getMatrixResultado().printMatrix();
    cout <<"--- Q Resultante ---" <<endl;
    qr.getMatrixQ().printMatrix();

    cout <<"--- Q * R ---" <<endl;
    (qr.getMatrixQ()*qr.getMatrixResultado()).printMatrix();
    cout <<"--- R * Q ---" <<endl;
    (qr.getMatrixResultado()*qr.getMatrixQ()).printMatrix();

//*/
}
