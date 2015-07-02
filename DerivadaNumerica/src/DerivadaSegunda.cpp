#include "../lib/imports.h"

DerivadaSegunda::DerivadaSegunda(double deltaX):DerivadaNumerica(deltaX),d(deltaX){}

double DerivadaSegunda::metodoForward(double pontoX, int precisaoEscolhida){
    double resultado;
    double delta = getDeltaX();
    resultado = d.metodoForward(pontoX+delta,precisaoEscolhida) - d.metodoForward(pontoX,precisaoEscolhida);
    resultado = resultado/delta;
    return resultado;

}

double DerivadaSegunda::metodoBackward(double pontoX, int precisaoEscolhida){
    double resultado;
    double delta = getDeltaX();
    resultado = d.metodoBackward(pontoX, precisaoEscolhida) - d.metodoBackward(pontoX-delta, precisaoEscolhida);
    resultado = resultado/delta;
    return resultado;
}

double DerivadaSegunda::metodoCentral(double pontoX, int precisaoEscolhida){
    double resultado;
    double delta = getDeltaX();
    resultado = d.metodoCentral(pontoX+delta, precisaoEscolhida) - d.metodoCentral(pontoX-delta,precisaoEscolhida);
    resultado = resultado/(2*delta);
    return resultado;

}
