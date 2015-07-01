class PotenciaRegular{
    Matrix A;
    Matrix autovetorChute;
    Matrix autovetor;
    double autovalor;
public:
    PotenciaRegular(Matrix autovetorChute, Matrix A);
    void solve(double precisao);
    Matrix getAutovetor();
    double getAutovalor();
};
