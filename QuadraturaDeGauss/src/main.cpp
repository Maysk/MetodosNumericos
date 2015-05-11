#include "../lib/imports.h"
int main(){
    GaussHermite* g = new Hermite(0, 1, 0.1);
    cout << g->integrar(2) <<endl;
    return 0;
}
