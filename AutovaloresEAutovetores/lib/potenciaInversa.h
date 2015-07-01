class PotenciaInversa{
    Matrix AInv;
    Matrix autovetorChute;
    Matrix autovetor;
    double autovalor;
public:
    PotenciaInversa(Matrix AInv, Matrix autovetorChute);
    void solve(double precisao);
    Matrix getAutovetor();
    double getAutovalor();
};
