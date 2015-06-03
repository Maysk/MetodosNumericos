#include "../lib/imports.h"
#define FORWARD 1
#define BACKWARD 2
#define CENTRAL 3


void solve(char opcao){
    char temp;
    double pontoX, deltaX;
    double resultado;
    DerivadaNumerica* derivada;
    cout << "Ponto que ira ser derivado: ";
    cin >> pontoX;
    cout << "Distancia entre os pontos (Delta X): ";
    cin >> deltaX;
    if(opcao>='a' && opcao<='f'){
        derivada = new DerivadaPrimeira(deltaX);
    }
    else{
        derivada = new DerivadaSegunda(deltaX);
    }
    switch(opcao){
        case 'a': case 'g':
            resultado = derivada->metodoForward(pontoX,1);
        break;
        case 'b': case 'h':
            resultado = derivada->metodoForward(pontoX,2);
        break;
        case 'c': case 'i':
            resultado = derivada->metodoBackward(pontoX,1);
        break;

        case 'd': case 'j':
            resultado = derivada->metodoBackward(pontoX,2);
        break;
        case 'e': case 'l':
            resultado = derivada->metodoCentral(pontoX,1);
        break;
        case 'f': case 'k':
            resultado = derivada->metodoCentral(pontoX,2);
        break;
    }


    cout << "O resultado e' "<< resultado <<endl;
    cout<<"Pressione qualquer tecla para continuar."<<endl<<endl;
    cin.ignore();
    cin.get();
}

void menu(){
    char opcao;

    do{
        cout<<"\n\n------------------------"<<endl;
        cout<<"  Metodos Numericos II  "<<endl;
        cout<<"------------------------"<<endl;
        cout<<"Seleciona uma das opcoes abaixo: "<<endl;

        cout<<"- Derivada Primeira"<<endl;
        cout<<"\t Forward"<<endl;
        cout<<"\t  a. 2 Pontos "<<endl;
        cout<<"\t  b. 3 Pontos "<<endl;
        cout<<"\t Backward"<<endl;
        cout<<"\t  c. 2 Pontos "<<endl;
        cout<<"\t  d. 3 Pontos "<<endl;
        cout<<"\t Central"<<endl;
        cout<<"\t  e. 2 Pontos "<<endl;
        cout<<"\t  f. 4 Pontos "<<endl;
        cout<<"- Derivada Segunda"<<endl;
        cout<<"\t Forward"<<endl;
        cout<<"\t  g. 3 Pontos "<<endl;
        cout<<"\t  h. 4 Pontos "<<endl;
        cout<<"\t Backward"<<endl;
        cout<<"\t  i. 3 Pontos "<<endl;
        cout<<"\t  j. 4 Pontos "<<endl;
        cout<<"\t Central"<<endl;
        cout<<"\t  k. 3 Pontos "<<endl;
        cout<<"\t  l. 5 Pontos "<<endl;
        cout<<" 9. Sair"<<endl;
        cout<<" Sua escolha e': ";
        cin >> opcao ;

        if(opcao>='a' && opcao<='l'){
            solve(opcao);
        }
        else if(opcao == '9'){
            cout<<"\n\n Ate logo! \n\n";
        }
        else{
            cout<<"\n\n Nao e' opcao valida. \n\n";
        }


    }while(opcao!='9');

}




int main(){
     menu();
}
