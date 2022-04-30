#include "verlet.h"

void verlet_step1(double &x, double &y, double &z, double &vx, double &vy, double &vz,
                  double fx, double fy, double fz, double timestep)
{
    vx += 0.5 * fx * timestep / 2;
    vy += 0.5 * fy * timestep / 2;
    vz += 0.5 * fz * timestep / 2;

    x += vx * timestep;
    y += vy * timestep;
    z += vz * timestep;
}

void verlet_step2(double &vx, double &vy, double &vz, double fx, double fy, double fz,
                  double timestep)
{
    vx = 0.5 * fx * timestep / 2;
    vy = 0.5 * fy * timestep / 2;
    vz = 0.5 * fz * timestep / 2;
}
