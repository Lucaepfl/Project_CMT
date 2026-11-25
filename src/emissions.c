#include "emissions.h"
#include "../data/params.h"

double emissions(void) {

    // E_NO2 is in mg/(km * vehicle).
    // Convert it to mg/m by dividing by 1000, then multiply by the distance
    // travelled by the car before the puff is considered formed (DISTANCE_MIN)
    // to get the MASS (mg) of NO2 contained in ONE puff.
    double E_NO2 = f_NO2 * E_NOX;
    double Q = (E_NO2 / 1000.0) * DISTANCE_MIN;
    return Q;
}