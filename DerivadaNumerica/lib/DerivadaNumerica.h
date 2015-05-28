class DerivadaNumerica{
private:
    double deltaX;
public:
    DerivadaNumerica(double deltaX);
    void setDeltaX(double deltaX);
    double getDeltaX();
    double funcao(double x);

    virtual double metodoFoward(double pontoX, int precisaoEscolhida) = 0;
    virtual double metodoBackward(double pontoX, int precisaoEscolhida) = 0;
    virtual double metodoCentral(double pontoX, int precisaoEscolhida) = 0;
};



