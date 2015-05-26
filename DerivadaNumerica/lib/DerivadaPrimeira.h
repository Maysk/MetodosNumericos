class DerivadaPrimeira : public DerivadaNumerica{
public:
    DerivadaPrimeira(double Deltax);
    double metodoFoward(double pontoX, int ordemDoErro);
    double metodoBackward(double pontoX, int ordemDoErro);
    double metodoCentral(double pontoX, int ordemDoErro);
};
