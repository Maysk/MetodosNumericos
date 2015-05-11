#include "../lib/imports.h"
int main(){
    GaussLegendre* g = new GaussLegendre(0, 1, 0.1);
    cout << g->integrar(2) <<endl;
    return 0;
}
