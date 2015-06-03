class DerivadaPrimeira : public DerivadaNumerica{
public:
    DerivadaPrimeira(double Deltax);
    double metodoForward(double pontoX, int precisaoEscolhida);
    double metodoBackward(double pontoX, int precisaoEscolhida);
    double metodoCentral(double pontoX, int precisaoEscolhida);
};
