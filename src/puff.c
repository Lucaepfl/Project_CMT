#include <math.h>
#include "puff.h"
#include "../data/params.h"

double calc_puff_concentration(Puff p, double t_now, double x_recept, double y_recept, double z_recept) {

    // Calculate the age of the puff
    double age = t_now - p.t_emis;
    if (age <= 0.0) return 0.0; // Puff not emitted yet

    // Current position of the puff center
    // The car is only the SOURCE: once the puff is formed, it stays fixed along
    // the road (Y-axis) and drifts laterally with the wind (X-axis)
    double x_puff = p.x + U_VENT * age;
    double y_puff = p.y;

    // Distance used for dispersion: the puff is created once the car is DISTANCE_MIN
    // ahead of the cyclist, so its dispersion is already developed over that distance.
    // This also avoids sigma = 0.
    double distance_travelled = DISTANCE_MIN + U_VENT * age;

    // Puff growth rate coefficients for Stability Class D (Neutral).
    // Source: Scire et al. (1984). User's Guide to the MESOPUFF II Model, Table 6 (p. 28).
    double a_y = 0.13;
    double b_y = 0.9;
    double a_z = 0.57;
    double b_z = 0.58;

    // Dispersion parameters using the power-law formulation: sigma = a * (x)^b
    // Source: Scire et al. (1984), Equations 2-32 and 2-33 (p. 28).
    double sigma_y = a_y * pow(distance_travelled, b_y);
    double sigma_z = a_z * pow(distance_travelled, b_z);
    // For a Gaussian puff, horizontal dispersion is assumed isotropic (sigma_x = sigma_y).
    double sigma_x = sigma_y; 

    // Distances from the puff center to the receptor (cyclist)
    double dx = x_puff - x_recept;
    double dy = y_puff - y_recept;
    double dz = p.z - z_recept;

    // Gaussian puff concentration formula
    double coeff = p.Q_emis / (pow(2 * PI, 1.5) * sigma_x * sigma_y * sigma_z);

    double exp_x = exp(-0.5 * (dx * dx) / (sigma_x * sigma_x));
    double exp_y = exp(-0.5 * (dy * dy) / (sigma_y * sigma_y));
    double exp_z1 = exp(-0.5 * (dz * dz) / (sigma_z * sigma_z));
    double exp_z2 = exp(-0.5 * (p.z + z_recept) * (p.z + z_recept) / (sigma_z * sigma_z));
    double exp_z3 = exp(-0.5 * pow(2 * HM - p.z - z_recept, 2) / (sigma_z * sigma_z));

    return coeff * exp_x * exp_y * (exp_z1 + exp_z2 + exp_z3);
}