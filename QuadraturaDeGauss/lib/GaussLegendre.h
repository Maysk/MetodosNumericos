class GaussLegendre {
    double inicioDoIntervalo;
    double finalDoIntervalo;
    double tolerancia;

    double funcao(double x);
    double mudancaDeVariavel(double x, double a, double b);
    double somatorio(int grauDoPolinomio, double a, double b);

public:
    GaussLegendre(double inicioDoIntervalo, double finalDoIntervalo, double tolerancia);
    double getInicioDoIntervalo();
    void setInicioDoIntervalo(double novoInicio);
    double getFinalDoIntervalo();
    void setFinalDoIntervalo(double novoFim);
    double getTolerancia();
    void setTolerancia(double novaTolerancia);
    double integrar(int grauDoPolinomioDesejado);
};
