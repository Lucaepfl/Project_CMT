#include "params.h"

const double PI = 3.14159265358979323846;   // Valeur du chiffre pi
const double DUREE_SIMULATION = 600.0;      // 10 minutes = 600 secondes
const double DT = 1.0;                      // Pas de temps d'une seconde
const double DISTANCE_MIN = 50.0;           // Distance seuil pour que le puff soit entièrement formé [m]
const double V_VELO = 5.0;                  // 18 km/h = 5 m/s
const double V_VOITURE = 12.5;              // 45 km/h = 12.5 m/s
const double U_VENT = 3.33;                 // Vitesse du vent 12 km/h = 3.33 m/s
const double TAUX_DEPASSEMENT = 15.0;       // Toutes les 15 secondes, une voiture dépasse le vélo
const double HM = 0.5;                      // Hauteur de la zone de mixage, en m
const double TJM = 15000.0;                 // Daily traffic véhicule/jour
const double E_NOX = 0.174;                 // NO_X emission limit, in mg/(km * véhicule)
const double f_NO2 = 0.05;                  // fraction of NOx emmited directly as NO2 (Euro 6) (dimensionless)
