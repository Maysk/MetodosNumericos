class GaussHermite : public QuadraturaDeGauss{
public:
    GaussHermite(double inicioDoIntervalo, double finalDoIntervalo, double tolerancia);
    double funcao(double x);
    double somatorio(int grauDoPolinomio, double a, double b);
};
