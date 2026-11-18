#include "puff.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


#define PI 3.14159265358979323846
#define V_VELO 5.0                  // 18 km/h = 5 m/s
#define V_VOITURE 12.5              // 45 km/h = 12.5 m/s
#define DT 1.0                      // Pas de temps, en seconde

double calc_puff_concentrat(Puff p, double x_recept, double y_recept, double z_recept) {

    // Écarts-types (dispersion de la puff)
    // !! À définir comment les déviations/dispersion se calculent !!

    double simga_x = 1; // Latéral
    double sigma_y = 1; // Le long de la route
    double sigma_z = 1; // Vertical

    // Distance entre le puff et le récepteur (le cycliste)

    double dx = p.x - x_recept; // Distance latérale, fixe d'environ 1 m
    double dy = p.y - y_recept; // Distance le long de la route (accroît avec le temps)
    double dz = p.z - z_recept; // Différence de hauteur

    // Expression des différents facteurs de la Gaussian Puff Concentration

    double coeff = p.Q_emis/(pow(2*PI, 1.5) *simga_x*sigma_y*sigma_z);
    
    double exp_x = exp(-0.5 * (dx*dx)/(simga_x*simga_x));

    double exp_y = exp(-0.5 * (dy*dy)/(sigma_y*sigma_y));

    double exp_z1 = exp(-0.5 * (dz*dz)/(sigma_z*sigma_z));

    double exp_z2 = exp

}