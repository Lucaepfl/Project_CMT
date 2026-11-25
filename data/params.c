#include "params.h"

const double PI = 3.14159265358979323846;   // Valeur du chiffre pi
const double DUREE_SIMULATION = 600.0;      // 10 minutes = 600 secondes
const double DT = 0.1;                      // Pas de temps (s), fin car le vélo traverse le puff en ~1-2 s
const double DISTANCE_MIN = 50.0;           // Distance seuil (axe y) pour que le puff soit entièrement formé [m]
const double V_VELO = 5.0;                  // 18 km/h = 5 m/s
const double V_VOITURE = 12.5;              // 45 km/h = 12.5 m/s
const double U_VENT = 3.33;                 // Vitesse du vent 12 km/h = 3.33 m/s
const double TAUX_DEPASSEMENT = 15.0;       // Toutes les 15 secondes, une voiture dépasse le vélo

// Mixing height for the Swiss Plateau (Payerne).
// Source: Collaud Coen et al. (2014), ACP. The planetary boundary layer height 
// ranges from 500-1200 m in winter to 1000-2000 m in summer. A value of 1000 m 
// is used here as a representative baseline.
const double HM = 1000.0; 

const double TJM = 15000.0;                 // Daily traffic véhicule/jour
const double E_NOX = 80.0;                  // NO_X emission limit, in mg/(km * véhicule) (Euro 6 diesel: 80, petrol: 60). TO CITE
const double f_NO2 = 0.05;                  // fraction of NOx emmited directly as NO2 (Euro 6) (dimensionless)