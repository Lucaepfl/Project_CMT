#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265358979323846   // Valeur du chiffre pi
#define DUREE_SIMULATION 600        // 10 minutes = 600 secondes
#define DT 1.0                      // Pas de temps d'une seconde
#define DISTANCE_MIN 50.0           // Distance seuil pour que le puff soit entièrement formé [m]
#define V_VELO 5.0                  // 18 km/h = 5 m/s
#define V_VOITURE 12.5              // 45 km/h = 12.5 m/s
#define U_VENT 3.33                 // Vitesse du vent 12 km/h = 3.33 m/s
#define TAUX_DEPASSEMENT 15.0       // Toutes les 15 secondes, une voiture dépasse le vélo
#define HM 0.5                      // Hauteur de la zone de mixage, en m
#define TJM 15000                   // Daily traffic véhicule/jour
#define E_NOX 0.174                 // NO_X emission limit, in mg/(km * véhicule)
#define f_NO2 0.05                  // fraction of NOx emmited directly as NO2 (Euro 6) (dimensionless)

