class GenericSolver{
    double t;
    double deltaT;
    double valorInicialDeY;
    int numeroDeRodadas;
    double* valoresDeY;
    double* derivadasDeY;

    void setValorDeY(int posicao, double y);
    void setValorDeDerivadaDeY(int posicao, double dy);
    void realocarVetores();
public:
    GenericSolver(double t, double deltaT, double valorInicialDeY);

    void setT(double t);
    void setDeltaT(double deltaT);
    void setValorInicialDeY(double valorInicialDeY);

    double getT();
    double getDeltaT();
    double getValorInicialDeY();
    double getValorDeY(int posicao);
    double getValorDeDerivadaDeY(int posicao);

    double derivadaDaFuncao(double y, double tempo);
    int calculeNumeroDeRodadas();

    double forwardEuler();
    double rungeKuttaSegundaOrdem();
    double rungeKuttaTerceiraOrdem();
    double rungeKuttaQuartaOrdem();
    double preditorCorretorTerceiraOrdem();
    double preditorCorretorQuartaOrdem();
};
