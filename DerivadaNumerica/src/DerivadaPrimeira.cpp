#include "../lib/imports.h"

DerivadaPrimeira::DerivadaPrimeira(double deltaX):DerivadaNumerica(deltaX){}

double DerivadaPrimeira::metodoFoward(double pontoX, int precisaoEscolhida){
    double resultado;
    double delta = getDeltaX();
    switch(precisaoEscolhida){
        case 1:
            resultado = funcao(pontoX + delta) - funcao(pontoX);
            resultado = resultado/delta;
        break;
        case 2:
            resultado =   4 * funcao(pontoX + delta) - funcao(pontoX + 2*delta) - 3*funcao(pontoX);
            resultado = resultado/(2*delta);
        break;
        default:
            throw PrecisaoNaoDefinidaParaEsteMetodo();
        break;
    }
    return resultado;
}

double DerivadaPrimeira::metodoBackward(double pontoX, int precisaoEscolhida){
    double resultado;
    double delta = getDeltaX();
    switch(precisaoEscolhida){
        case 1:
            resultado = funcao(pontoX) - funcao(pontoX - delta);
            resultado = resultado/delta;
        break;
        case 2:
            resultado =   3 * funcao(pontoX) - 4*funcao(pontoX - delta) + funcao(pontoX - 2 * delta);
            resultado = resultado/(2*delta);
        break;
        default:
            throw PrecisaoNaoDefinidaParaEsteMetodo();
        break;
    }
    return resultado;
}

double DerivadaPrimeira::metodoCentral(double pontoX, int precisaoEscolhida){
    double resultado;
    double delta = getDeltaX();
    switch(precisaoEscolhida){
        case 1:
            resultado = funcao(pontoX + delta) - funcao(pontoX - delta);
            resultado = resultado/2*delta;
        break;
        case 2:
            resultado =   (-1)*funcao(pontoX + 2*delta) + 8*funcao(pontoX + delta) - 8*funcao(pontoX - delta) + funcao(pontoX - 2 * delta);
            resultado = resultado/(12*delta);
        break;
        default:
            throw PrecisaoNaoDefinidaParaEsteMetodo();
        break;
    }
    return resultado;
}
