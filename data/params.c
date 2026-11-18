#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265358979323846
#define DUREE_SIMULATION 600        // 10 minutes = 600 secondes
#define DT 1.0                      // Pas de temps d'une seconde
#define DISTANCE_MIN 50.0           // Distance seuil pour que le puff soit entièrement formé [m]
#define V_VELO 5.0                  // 18 km/h = 5 m/s
#define V_VOITURE 12.5              // 45 km/h = 12.5 m/s
#define U_VENT 3.33                 // Vitesse du vent 12 km/h = 3.33 m/s
#define TAUX_DEPASSEMENT 15.0       // Toutes les 15 secondes, une voiture dépasse le vélo



