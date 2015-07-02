class Jacobi{
    Matrix A;
    Matrix J;
    Matrix Resultado;

    Matrix generateRotationMatrix(Matrix A, int i, int j);
    bool isDiagonal(Matrix A, double precisao);

public:
    Jacobi(Matrix A);
    Matrix getMatrixA();
    Matrix getMatrixJ();
    Matrix getMatrixResultado();
    void diagonalizarMatrix(double precisao);

};
