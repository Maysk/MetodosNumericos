#include "../lib/imports.h"

DerivadaPrimeira::DerivadaPrimeira(double deltaX):DerivadaNumerica(deltaX){}

double DerivadaPrimeira::metodoFoward(double pontoX, int ordemDoErro){
    double resultado;
    double delta = getDeltaX();
    switch(ordemDoErro){
        case '1':
            resultado = funcao(pontoX + delta) - funcao(pontoX);
            resultado = resultado/delta;
        break;
        case '2':
            resultado = funcao(pontoX + 2*delta) + 4 * funcao(pontoX + delta) - 3*funcao(pontoX);
            resultado = resultado/(2*delta);
        break;
        default:
            throw precisaoNaoImplementada;
        break;
    }
    return resultado;
}

double DerivadaPrimeira::metodoBackward(double pontoX, int ordemDoErro){}

double DerivadaPrimeira::metodoCentral(double pontoX, int ordemDoErro){}
