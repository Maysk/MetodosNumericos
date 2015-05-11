class GaussLegendre : public QuadraturaDeGauss{
public:
    GaussLegendre(double inicioDoIntervalo, double finalDoIntervalo, double tolerancia);
    double funcao(double x);
    double mudancaDeVariavel(double x, double a, double b);
    double somatorio(int grauDoPolinomio, double a, double b);
};
