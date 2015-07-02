
class PotenciaComDeslocamento{
    PotenciaInversa pInv;
    double deslocamento;
public:
    PotenciaComDeslocamento(Matrix A, Matrix autovetorChute, double deslocamento);
    void solve(double precisao);
    Matrix getAutovetorChute();
    Matrix getMatrixADeslocada();
    Matrix getMatrixInvDeAdeslocada();
    Matrix getAutovetor();
    double getDeslocamento();
    double getAutovalor();
};
