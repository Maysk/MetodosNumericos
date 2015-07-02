class PotenciaInversa{
    Matrix A;
    Matrix autovetorChute;
    Matrix AInv;
    Matrix autovetor;
    double autovalor;
public:
    PotenciaInversa(Matrix A, Matrix autovetorChute);
    void solve(double precisao);
    Matrix getAutovetorChute();
    Matrix getMatrixA();
    Matrix getMatrixInv();
    Matrix getAutovetor();
    double getAutovalor();
};
