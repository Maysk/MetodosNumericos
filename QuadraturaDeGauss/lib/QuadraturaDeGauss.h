class QuadraturaDeGauss
{
    double inicioDoIntervalo;
    double finalDoIntervalo;
    double tolerancia;
public:
    double getInicioDoIntervalo();
    void setInicioDoIntervalo(double novoInicio);
    double getFinalDoIntervalo();
    void setFinalDoIntervalo(double novoFim);
    double getTolerancia();
    void setTolerancia(double novaTolerancia);

    double funcaoPolinomial(double x);
    virtual double mudancaDeVariavel(double x, double a, double b) = 0;
    virtual double somatorio(int grauDoPolinomio, double a, double b) = 0;
    double integrar(int grauDoPolinomioDesejado);

protected:
    QuadraturaDeGauss(double inicioDoIntervalo, double finalDoIntervalo, double tolerancia);
};
