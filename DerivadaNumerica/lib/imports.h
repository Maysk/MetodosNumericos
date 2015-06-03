#include <iostream>
#include <cmath>
#include <exception>
#include <iostream>
#include "DerivadaNumerica.h"
#include "DerivadaPrimeira.h"
#include "DerivadaSegunda.h"

using namespace std;

struct PrecisaoNaoDefinidaParaEsteMetodo: public exception
{
  const char * what () const throw ()
  {
    return "Precisao nao definida.";
  }
};


