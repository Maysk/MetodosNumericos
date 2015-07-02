class Householder{
    Matrix A;
    Matrix H;
    Matrix T;
    int getSinal(double x);
public:
    Householder(Matrix A);
    void setMatrixA(Matrix A);
    Matrix getMatrixA();
    Matrix getMatrixH();
    Matrix getMatrixT();

    void tridiagonalizar();
};
