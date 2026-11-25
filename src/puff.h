#ifndef PUFF_H
#define PUFF_H

typedef struct {
    double x;
    double y;
    double z;
    double t_emis;
    double Q_emis;
} Puff;

double calc_puff_concentration(Puff p, double t_now, double x_recept, double y_recept, double z_recept);
#endif