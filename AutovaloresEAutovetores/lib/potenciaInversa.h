class PotenciaInversa{
    Matrix A;
    Matrix AInv;
    Matrix autovetorChute;
    Matrix autovetor;
    double autovalor;
public:
    PotenciaInversa(Matrix autovetorChute, Matrix A);
    void solve(double precisao);
    Matrix getAutovetor();
    double getAutovalor();
};
