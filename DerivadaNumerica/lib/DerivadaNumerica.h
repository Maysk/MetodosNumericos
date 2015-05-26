class DerivadaNumerica{
private:
    double deltaX;
public:
    DerivadaNumerica(double deltaX);
    void setDeltaX(double deltaX);
    double getDeltaX();
    double funcao(double x);

    virtual double metodoFoward(double pontoX, int ordemDoErro) = 0;
    virtual double metodoBackward(double pontoX, int ordemDoErro) = 0;
    virtual double metodoCentral(double pontoX, int ordemDoErro) = 0;
};



