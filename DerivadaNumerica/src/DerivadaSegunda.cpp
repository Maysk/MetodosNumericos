#include "../lib/imports.h"

DerivadaSegunda::DerivadaSegunda(double deltaX):DerivadaNumerica(deltaX){}

double DerivadaSegunda::metodoForward(double pontoX, int precisaoEscolhida){
    double resultado;
    double delta = getDeltaX();
    switch(precisaoEscolhida){
        case 1:
            resultado = funcao(pontoX + 2*delta) - 2*funcao(pontoX + delta) + funcao(pontoX);
            resultado = resultado/pow(delta,2);
        break;
        case 2:
            //TODO: Calcular e implementar.
        break;
        default:
            throw PrecisaoNaoDefinidaParaEsteMetodo();
        break;
    }
    return resultado;

}

double DerivadaSegunda::metodoBackward(double pontoX, int precisaoEscolhida){
    double resultado;
    double delta = getDeltaX();
    switch(precisaoEscolhida){
        case 1:
            resultado = funcao(pontoX) - 2*funcao(pontoX - delta) + funcao(pontoX - 2*delta);
            resultado = resultado/pow(delta,2);
        break;
        case 2:
            //TODO: Calcular e implementar.
        break;
        default:
            throw PrecisaoNaoDefinidaParaEsteMetodo();
        break;
    }
    return resultado;
}

double DerivadaSegunda::metodoCentral(double pontoX, int precisaoEscolhida){
    double resultado;
    double delta = getDeltaX();
    switch(precisaoEscolhida){
        case 1:
            resultado = funcao(pontoX + delta) - 2*funcao(pontoX) + funcao(pontoX - delta);
            resultado = resultado/pow(delta,2);
        break;
        case 2:
            //TODO: Calcular e implementar.
        break;
        default:
            throw PrecisaoNaoDefinidaParaEsteMetodo();
        break;
    }
    return resultado;

}
