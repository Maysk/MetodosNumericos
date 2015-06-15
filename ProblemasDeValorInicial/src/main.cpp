#include "../lib/imports.h"
int main(){
    GenericSolver g(1, 1, 1);
    cout << "Foward Euler: " << g.forwardEuler() << endl;
    cout << "RungeKutta 2 Ordem: " << g.rungeKuttaSegundaOrdem() << endl;
    cout << "RungeKutta 3 Ordem: " << g.rungeKuttaTerceiraOrdem() << endl;
    cout << "RungeKutta 4 Ordem: " << g.rungeKuttaQuartaOrdem() << endl;


    return 0;
}
