#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "puff.h"
#include "../data/params.h"
#include "../src/emissions.c"

int main() {
    double t = 0.0;
    double y_cycliste = 0.0; // Le cycliste avance sur Y
    
    Puff puffs[100]; 
    int num_puffs = 0;
    double temps_prochain_depassement = 0.0;

    FILE *f = fopen("output.csv", "w");
    fprintf(f, "time_s, C_traffic\n");

    while (t <= DUREE_SIMULATION) {
        y_cycliste = V_VELO * t;

        // Une voiture dépasse : elle est à y_cycliste, mais décalée latéralement (x = 1.0 m)
        if (t >= temps_prochain_depassement) {
            puffs[num_puffs].x = 1.0;               // 1 mètre latéral
            puffs[num_puffs].y = y_cycliste;        // Position sur la route
            puffs[num_puffs].z = 0.5;               // Pot d'échappement
            puffs[num_puffs].t_emis = 0.0;
            puffs[num_puffs].Q_emis = emissions();
            num_puffs++;
            temps_prochain_depassement += 15.0;     // Après 15 secondes, une nouvelle voiture intervient dans l'équation
        }

        double C_traffic_total = 0.0;
        
        for (int i = 0; i < num_puffs; i++) {
            puffs[i].t_emis += DT;
            
            // Distance sur l'axe Y (la route)
            double y_puff_actuel = puffs[i].y + V_VOITURE * puffs[i].t_emis;
            double distance_y = y_puff_actuel - y_cycliste;
            
            // Règle des 50 mètres sur l'axe Y
            if (distance_y > DISTANCE_MIN) {
                // Appel de la fonction (la voiture est à x=1.0, le vélo à x=0.0)
                double C_puff = calc_puff_concentration(
                    puffs[i], 
                    0.0,            // x_rec (cycliste à 0)
                    y_cycliste,     // y_rec (position actuelle)
                    1.5             // z_rec (hauteur de respiration)
                );
                C_traffic_total += C_puff;
            }
        }

        fprintf(f, "%.1f, %.8f\n", t, C_traffic_total);
        t += DT;
    }
    
    fclose(f);
    return 0;
}