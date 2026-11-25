#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "puff.h"
#include "../data/params.h"
#include "emissions.h"

#define MAX_PUFFS 100 // Maximum number of puffs allowed in the simulation (one per overtaking car)

int main() {
    double t = 0.0;
    double y_cycliste = 0.0; // Cyclist position along the road (Y-axis)

    // Lateral positions (X-axis is perpendicular to the road, wind blows toward +x)
    const double X_VOITURE = 0.0;   // Line of cars
    const double X_VELO = 1.0;      // Cyclist is shifted laterally by 1 m from the cars

    // Background concentration in µg/m^3 (data from the Vaud'Air network)
    double C_background = 20.0; 
    Puff puffs[MAX_PUFFS]; 
    int num_puffs = 0;

    // A car overtakes the cyclist every TAUX_DEPASSEMENT seconds. The puff is created
    // when the car is DISTANCE_MIN ahead of the cyclist along the road (Y-axis),
    // i.e. after DISTANCE_MIN / (V_VOITURE - V_VELO) seconds.
    double delai_formation = DISTANCE_MIN / (V_VOITURE - V_VELO);
    double temps_prochaine_emission = delai_formation;
    double C_traffic_max = 0.0;     // to check the order of magnitude of the result

    FILE *f = fopen("output.csv", "w");
    if (f == NULL) {
        printf("Error opening file output.csv\n");
        return 1;
    }
    // Write header with explicit units (no spaces, easier to read with pandas)
    fprintf(f, "time_s,C_background_ug_m3,C_traffic_ug_m3,C_total_ug_m3\n");

    while (t <= DUREE_SIMULATION) {
        y_cycliste = V_VELO * t;

        // Emit a new puff when the overtaking car is DISTANCE_MIN ahead of the cyclist
        if (t >= temps_prochaine_emission) {
            if (num_puffs < MAX_PUFFS) {
                puffs[num_puffs].x = X_VOITURE;                                     // Lateral position at emission (m)
                puffs[num_puffs].y = V_VELO * temps_prochaine_emission + DISTANCE_MIN; // Car position along the road at emission
                puffs[num_puffs].z = 0.5;                                           // Exhaust pipe height
                puffs[num_puffs].t_emis = temps_prochaine_emission;                 // REAL emission time (s), not an age
                puffs[num_puffs].Q_emis = emissions();
                num_puffs++;
            } else {
                printf("Warning: Maximum puff limit reached (%d). Increase MAX_PUFFS if needed.\n", MAX_PUFFS);
            }
            temps_prochaine_emission += TAUX_DEPASSEMENT;
        }

        double C_traffic_total_mg = 0.0;
        for (int i = 0; i < num_puffs; i++) {
            // Age and position of the puff are handled inside calc_puff_concentration
            C_traffic_total_mg += calc_puff_concentration(
                puffs[i], 
                t,              // current time
                X_VELO,         // x_rec (cyclist)
                y_cycliste,     // y_rec (current cyclist position)
                1.5             // z_rec (breathing height)
            );
        }

        // UNIT CONVERSION (mg/m^3 -> µg/m^3)
        double C_traffic_ug = C_traffic_total_mg * 1000.0;
        double C_total = C_background + C_traffic_ug;
        if (C_traffic_ug > C_traffic_max) C_traffic_max = C_traffic_ug;

        // Write results to CSV
        fprintf(f, "%.1f, %.2f, %.12e, %.12e\n", t, C_background, C_traffic_ug, C_total);
        t += DT;
    }
    fclose(f);
    printf("Simulation completed. Max C_traffic = %.3e ug/m3\n", C_traffic_max);
    return 0;
}