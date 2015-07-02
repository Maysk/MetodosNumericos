#include <iostream>
#include <cmath>
#include <exception>
#include <iomanip>
#include "exceptions.h"
#include "matrix.h"
#include "potenciaRegular.h"
#include "potenciaInversa.h"
#include "potenciaComDeslocamento.h"
#include "householder.h"
#include "jacobi.h"
#include "qr.h"

#define NOT_MULTIPLIABLE 43
#define NOT_SUB 42
#define INVALID_MATRIX 41
#define NOT_VECTOR 40
#define GENERIC_ERROR 50

using namespace std;
