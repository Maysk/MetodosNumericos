class DerivadaSegunda : public DerivadaNumerica{
public:
    DerivadaSegunda(double Deltax);
    double metodoFoward(double pontoX, int precisaoEscolhida);
    double metodoBackward(double pontoX, int precisaoEscolhida);
    double metodoCentral(double pontoX, int precisaoEscolhida);
};
