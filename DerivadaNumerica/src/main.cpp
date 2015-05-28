#include "../lib/imports.h"

int main(){
    DerivadaPrimeira *derivadaPrimeira = new DerivadaPrimeira(0.001);
    try{
        cout << derivadaPrimeira->metodoFoward(2,3);
    }
    catch(PrecisaoNaoDefinidaParaEsteMetodo& e){
        cout<<e.what()<<endl;
    }
    return 0;
}
