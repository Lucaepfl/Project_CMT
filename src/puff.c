#include <math.h>
#include "puff.h"
#include "../data/params.h"

double calc_puff_concentration(Puff p, double x_recept, double y_recept, double z_recept) {

    // Dispersion (à raffiner plus tard)
    double sigma_x = 1.0;
    double sigma_y = 1.0;
    double sigma_z = 1.0;

    double y_puff = p.y + V_VOITURE * p.t_emis;

    double dx = p.x - x_recept;
    double dy = y_puff - y_recept;
    double dz = p.z - z_recept;

    double coeff = p.Q_emis / (pow(2 * PI, 1.5) * sigma_x * sigma_y * sigma_z);

    double exp_x = exp(-0.5 * (dx * dx) / (sigma_x * sigma_x));
    double exp_y = exp(-0.5 * (dy * dy) / (sigma_y * sigma_y));
    double exp_z1 = exp(-0.5 * (dz * dz) / (sigma_z * sigma_z));
    double exp_z2 = exp(-0.5 * (p.z + z_recept) * (p.z + z_recept) / (sigma_z * sigma_z));
    double exp_z3 = exp(-0.5 * pow(2 * HM - p.z - z_recept, 2) / (sigma_z * sigma_z));

    return coeff * exp_x * exp_y * exp_z1 * (exp_z2 + exp_z3);
}