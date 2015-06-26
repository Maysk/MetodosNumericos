#include "../lib/imports.h"

GenericSolver::GenericSolver(double t, double deltaT, double valorInicialDeY){
    this->t = t;
    this->deltaT = deltaT;
    this->valorInicialDeY = valorInicialDeY;
    calculeNumeroDeRodadas();
    this->valoresDeY = new double[numeroDeRodadas+1];
    this->derivadasDeY = new double[numeroDeRodadas+1];
}

void GenericSolver::setT(double t){
    this->t = t;
}

void GenericSolver::setDeltaT(double deltaT){
    this->deltaT = deltaT;
}

void GenericSolver::setValorInicialDeY(double valorInicialDeY){
    this->valorInicialDeY = valorInicialDeY;
}

void GenericSolver::setValorDeY(int posicao, double valor){
    valoresDeY[posicao] = valor;
}

void GenericSolver::setValorDeDerivadaDeY(int posicao, double valor){
    derivadasDeY[posicao] = valor;
}

double GenericSolver::getT(){
    return t;
}

double GenericSolver::getDeltaT(){
    return deltaT;
}

double GenericSolver::getValorInicialDeY(){
    return valorInicialDeY;
}

double GenericSolver::getValorDeY(int posicao){
    return valoresDeY[posicao];
}

double GenericSolver::getValorDeDerivadaDeY(int posicao){
    return derivadasDeY[posicao];
}

double GenericSolver::derivadaDaFuncao(double y, double tempo){
    double resultado = -1/(1 + pow(y,2));
    return resultado;
}

int GenericSolver::calculeNumeroDeRodadas(){
    this->numeroDeRodadas = floor(t/deltaT);
    return numeroDeRodadas;
}

void GenericSolver::realocarVetores(){
    delete valoresDeY;
    delete derivadasDeY;
    valoresDeY = new double[numeroDeRodadas+1];
    derivadasDeY = new double[numeroDeRodadas+1];
}

double GenericSolver::forwardEuler(){
    double yDaRodada;
    double tempo;

    calculeNumeroDeRodadas();
    realocarVetores();

    setValorDeY(0,valorInicialDeY);
    setValorDeDerivadaDeY(0, derivadaDaFuncao(valorInicialDeY, 0));

    tempo = 0;

    for(int i=1; i<=numeroDeRodadas; i++){
        yDaRodada = getValorDeY(i-1) + deltaT * getValorDeDerivadaDeY(i-1);
        setValorDeY(i, yDaRodada);

        tempo += deltaT;
        setValorDeDerivadaDeY(i, derivadaDaFuncao(yDaRodada, tempo));
    }

    return yDaRodada;

}

double GenericSolver::rungeKuttaSegundaOrdem(){
    double yDaRodada;
    double tempo;
    double k1, k2;

    calculeNumeroDeRodadas();
    realocarVetores();

    setValorDeY(0,valorInicialDeY);
    setValorDeDerivadaDeY(0, derivadaDaFuncao(valorInicialDeY, 0));

    tempo = 0;

    for(int i=1; i<=numeroDeRodadas; i++){
        k1 = deltaT * derivadaDaFuncao(getValorDeY(i-1), tempo);
        k2 = deltaT * derivadaDaFuncao(getValorDeY(i-1) + k1, tempo + deltaT);
        yDaRodada = getValorDeY(i-1) + (k1+k2)/2;
        setValorDeY(i, yDaRodada);

        tempo += deltaT;
        setValorDeDerivadaDeY(i, derivadaDaFuncao(yDaRodada, tempo));
    }

    return yDaRodada;

}


double GenericSolver::rungeKuttaTerceiraOrdem(){
    double yDaRodada;
    double tempo;
    double k1, k2, k3;

    calculeNumeroDeRodadas();
    realocarVetores();

    setValorDeY(0,valorInicialDeY);
    setValorDeDerivadaDeY(0, derivadaDaFuncao(valorInicialDeY, 0));

    tempo = 0;

    for(int i=1; i<=numeroDeRodadas; i++){
        k1 = deltaT * derivadaDaFuncao(getValorDeY(i-1), tempo);
        k2 = deltaT * derivadaDaFuncao(getValorDeY(i-1) + k1/2, tempo + deltaT/2);
        k3 = deltaT * derivadaDaFuncao(getValorDeY(i-1) - k1 + 2*k2, tempo + deltaT);

        yDaRodada = getValorDeY(i-1) + (k1 + 4*k2 + k3)/6;
        setValorDeY(i,yDaRodada);

        tempo += deltaT;
        setValorDeDerivadaDeY(i, derivadaDaFuncao(yDaRodada, tempo));
    }

    return yDaRodada;
}

double GenericSolver::rungeKuttaQuartaOrdem(){
    double yDaRodada;
    double tempo;
    double k1, k2, k3, k4;

    calculeNumeroDeRodadas();
    realocarVetores();

    setValorDeY(0,valorInicialDeY);
    setValorDeDerivadaDeY(0, derivadaDaFuncao(valorInicialDeY, 0));

    tempo = 0;

    for(int i=1; i<=numeroDeRodadas; i++){
        k1 = deltaT * derivadaDaFuncao(getValorDeY(i-1), tempo);
        k2 = deltaT * derivadaDaFuncao(getValorDeY(i-1) + k1/3, tempo + deltaT/3);
        k3 = deltaT * derivadaDaFuncao(getValorDeY(i-1) + k1/3 + k2/3, tempo + 2*deltaT/3);
        k4 = deltaT * derivadaDaFuncao(getValorDeY(i-1) + k1 - k2 + k3, tempo + deltaT);

        yDaRodada = getValorDeY(i-1) + (k1 + 3*k2 + 3*k3 + k4)/8;
        setValorDeY(i, yDaRodada);

        tempo += deltaT;
        setValorDeDerivadaDeY(i, derivadaDaFuncao(yDaRodada, tempo));
    }
    return yDaRodada;
}


double GenericSolver::preditorCorretorTerceiraOrdem(int metodoEscolhido){
    GenericSolver generic(this->t, this->deltaT, this->valorInicialDeY);
    double preditorResult;
    double derivadaDoPreditor;
    double corretorResult;


    if(metodoEscolhido == FORWARD_EULER)
    {
        generic.forwardEuler();
    }
    else if(metodoEscolhido ==  RUNGEKUTTA_2ORDEM)
    {
        generic.rungeKuttaSegundaOrdem();
    }
    else if(metodoEscolhido ==  RUNGEKUTTA_3ORDEM)
    {
        generic.rungeKuttaTerceiraOrdem();
    }
    else if(metodoEscolhido ==  RUNGEKUTTA_4ORDEM)
    {
        generic.rungeKuttaQuartaOrdem();
    }
    else{
        throw METHOD_NOT_DEFINED;
    }

    for(int i = 0; i<3; i++){
        setValorDeY(i,generic.getValorDeY(i));
        setValorDeDerivadaDeY(i, generic.getValorDeDerivadaDeY(i));
    }


    for(int i = 3; i<=numeroDeRodadas; i++){
        preditorResult = getValorDeY(i-1) + deltaT * (23 * getValorDeDerivadaDeY(i-1) - 16 * getValorDeDerivadaDeY(i-2) + 5 * getValorDeDerivadaDeY(i - 3)) / 12;
        derivadaDoPreditor = derivadaDaFuncao(preditorResult, i*deltaT);
        corretorResult = getValorDeY(i-1) + deltaT * (5 * derivadaDoPreditor + 8 * getValorDeDerivadaDeY(i-1) - getValorDeDerivadaDeY(i-2)) /12;
        setValorDeDerivadaDeY(i,derivadaDaFuncao(corretorResult,i*deltaT));
    }

    return getValorDeY(numeroDeRodadas);


}

double GenericSolver::preditorCorretorQuartaOrdem(int metodoEscolhido){
    GenericSolver generic(this->t, this->deltaT, this->valorInicialDeY);
    double preditorResult;
    double derivadaDoPreditor;
    double corretorResult;


    if(metodoEscolhido == FORWARD_EULER)
    {
        generic.forwardEuler();
    }
    else if(metodoEscolhido ==  RUNGEKUTTA_2ORDEM)
    {
        generic.rungeKuttaSegundaOrdem();
    }
    else if(metodoEscolhido ==  RUNGEKUTTA_3ORDEM)
    {
        generic.rungeKuttaTerceiraOrdem();
    }
    else if(metodoEscolhido ==  RUNGEKUTTA_4ORDEM)
    {
        generic.rungeKuttaQuartaOrdem();
    }
    else{
        throw METHOD_NOT_DEFINED;
    }

    for(int i = 0; i<4; i++){
        setValorDeY(i,generic.getValorDeY(i));
        setValorDeDerivadaDeY(i, generic.getValorDeDerivadaDeY(i));
    }


    for(int i = 4; i<=numeroDeRodadas; i++){
        preditorResult = getValorDeY(i-1) + deltaT * (55 * getValorDeDerivadaDeY(i-1) - 59 * getValorDeDerivadaDeY(i-2) + 37 * getValorDeDerivadaDeY(i-3) - 9 * getValorDeDerivadaDeY(i-4)) / 24;
        derivadaDoPreditor = derivadaDaFuncao(preditorResult, i*deltaT);
        corretorResult = getValorDeY(i-1) + deltaT * (9 * derivadaDoPreditor + 19 * getValorDeDerivadaDeY(i-1) - 5 * getValorDeDerivadaDeY(i-2) + getValorDeDerivadaDeY(i-3)) / 24;
        setValorDeDerivadaDeY(i,derivadaDaFuncao(corretorResult,i*deltaT));
    }

    return getValorDeY(numeroDeRodadas);

}


