class PotenciaRegular{
    Matrix A;
    Matrix autovetorChute;
    Matrix autovetor;
    double autovalor;
public:
    PotenciaRegular(const Matrix A, const Matrix autovetorChute);
    void solve(double precisao);
    Matrix getAutovetor();
    double getAutovalor();
};
