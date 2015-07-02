class QR{
    Matrix A;
    Matrix Q;
    Matrix Resultado;

    Matrix generateRotationMatrix(Matrix A, int i, int j);
    bool isTriangularSuperior(Matrix A, double precisao);

public:
    QR(Matrix A);
    Matrix getMatrixA();
    Matrix getMatrixQ();
    Matrix getMatrixResultado();
    void transformarEmTriangularSuperior(double precisao);

};
