#ifndef PUFF_H
#define PUFF_H

typedef struct {
    double x;           // Position latérale (m)
    double y;           // Position le long de la route (m)
    double z;           // Hauteur z (m)
    double t_emis;      // Temps depuis l'émission
    double Q_emis;      // Masse émise (g)
} Puff;

// Calcule la concentration du puff
double calc_puff_concentrat(Puff p, double x_cycliste, double y_cycliste, double z_cycliste);

#endif