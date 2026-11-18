#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "../data/params.h"

double emissions() {

    double E_NO2 = f_NO2 * E_NOX;

    double Q = E_NO2*TJM/(1*1e+3 + 8.64*1e+4);

    return Q;
}

