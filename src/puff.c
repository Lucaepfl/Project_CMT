#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "puff.h"
#include "../data/params.h"



double calc_puff_concentrat(Puff p, double x_recept, double y_recept, double z_recept) {

    // Écarts-types (dispersion de la puff)
    // !! À définir comment les déviations/dispersion se calculent !!

    double simga_x = 1;     // Latéral
    double sigma_y = 1;     // Le long de la route
    double sigma_z = 1;     // Vertical

    // Position actuelle du puff selon Y (la voiture a avancé)

    double y_puff = p.y + V_VOITURE * p.t_emis; 

    // Distance entre le puff et le récepteur (le cycliste)

    double dx = p.x - x_recept;     // Distance latérale, fixe d'environ 1 m
    double dy = y_puff - y_recept;  // Distance le long de la route (accroît avec le temps)
    double dz = p.z - z_recept;     // Différence de hauteur

    // Expression des différents facteurs de la Gaussian Puff Concentration

    double coeff = p.Q_emis/(pow(2*PI, 1.5) *simga_x*sigma_y*sigma_z);
    
    double exp_x = exp(-0.5 * (dx*dx)/(simga_x*simga_x));

    double exp_y = exp(-0.5 * (dy*dy)/(sigma_y*sigma_y));

    double exp_z1 = exp(-0.5 * (dz*dz)/(sigma_z*sigma_z));

    double exp_z2 = exp(-0.5 * (p.z + z_recept)*(p.z + z_recept)/(sigma_z*sigma_z));

    double exp_z3 = exp(-0.5 * pow(2*HM - p.z - z_recept, 2)/(sigma_z*sigma_z));

    return coeff * exp_x * exp_y * exp_z1 * (exp_z2 + exp_z3);

}