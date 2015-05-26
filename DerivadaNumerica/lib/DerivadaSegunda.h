class DerivadaSegunda : public DerivadaNumerica{
public:
    DerivadaSegunda(double Deltax);
    double metodoFoward(double pontoX, int ordemDoErro);
    double metodoBackward(double pontoX, int ordemDoErro);
    double metodoCentral(double pontoX, int ordemDoErro);
};
