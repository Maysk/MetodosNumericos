#include "../lib/imports.h"
int main(){
    GenericSolver g(1, 0.01, 1);
    cout << "Foward Euler: " << g.forwardEuler() << endl;
    cout << "RungeKutta 2 Ordem: " << g.rungeKuttaSegundaOrdem() << endl;
    cout << "RungeKutta 3 Ordem: " << g.rungeKuttaTerceiraOrdem() << endl;
    cout << "RungeKutta 4 Ordem: " << g.rungeKuttaQuartaOrdem() << endl;
    cout << "PreditorCorretor 3: " << g.preditorCorretorTerceiraOrdem(1) << endl;
    cout << "PreditorCorretor 4: " << g.preditorCorretorQuartaOrdem(1) << endl;
    return 0;
}
