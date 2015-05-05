#include "../lib/imports.h"

void solve(RegraEscolhida regraEscolhida){
    double pontoInicial, pontoFinal;
    double resultado;
    int numeroDeParticoes;
    cout << "Ponto Inicial: ";
    cin >> pontoInicial;
    cout << "Ponto Final: ";
    cin >> pontoFinal;
    cout << "Numero de particoes: ";
    cin >> numeroDeParticoes;
    resultado = IntegracaoNumerica(pontoInicial, pontoFinal, numeroDeParticoes, regraEscolhida);
    cout << "O resultado e' "<< resultado <<endl<<endl;
}

void menu(){
    char opcao;

    do{
        cout<<"\n\n------------------------"<<endl;
        cout<<"  Metodos Numericos II  "<<endl;
        cout<<"------------------------"<<endl;
        cout<<"Selecione qual regra e filosofia voce deseja utilizar para integrar a funcao: "<<endl;

        cout<<" -Filosofia fechada: "<<endl;
        cout<<" 1. Regra do Trapezio"<<endl;
        cout<<" 2. Regra de Simpson 1/3"<<endl;
        cout<<" 3. Regra de Simpson 3/8"<<endl;
        cout<<" -Filosofia aberta: "<<endl;
        cout<<" 4. Polinomio interpolador de grau 1"<<endl;
        cout<<" 5. Polinomio interpolador de grau 2"<<endl;
        cout<<" 6. Polinomio interpolador de grau 3"<<endl;
        cout<<" 9. Sair"<<endl;
        cout<<" Sua escolha e': ";
        cin >> opcao ;

        switch(opcao){
            case '1':
                solve(regraDoTrapezioFechado);
            break;
            case '2':
                solve(regraDeSimpsonUmTercoFechado);
            break;
            case '3':
                solve(regraDeSimpsonTresOitavosFechado);
            break;
            case '4':
                solve(regraDoTrapezioAberto);
            break;
            case '5':
                solve(regraDeSimpsonUmTercoAberto);
            break;
            case '6':
                solve(regraDeSimpsonTresOitavosAberto);
            break;
            case '9':
                cout<<"\n\n Ate logo! \n\n";
            break;
            default:
                cout<<"\n\n Nao e' opcao valida. \n\n";
            break;

        }
    }while(opcao!='9');

}


int main(){
     menu();
}
