#include "emissions.h"
#include "../data/params.h"

double emissions(void) {
    double E_NO2 = f_NO2 * E_NOX;
    double Q = E_NO2 * TJM / (1000.0 * 86400.0);
    return Q;
}