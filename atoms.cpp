#include "Eigen"

struct Atoms
{
    Eigen::Array3Xd positions;
    Eigen::Array3Xd velocities;
    Eigen::Array3Xd forces;

    Atoms(Eigen::Array3Xd &p) : positions{p},
                                velocities{3, p.cols()},
                                forces{3, p.cols()}
    {
        velocities.setZero();
        forces.setZero();
    }

    size_t num_atoms() const
    {
        return positions.cols();
    }

    void verlet1(Atoms &atoms, double timestep, double mass)
    {
        atoms.velocities += 0.5 * atoms.forces * timestep / mass;
        atoms.positions += atoms.velocities * timestep;
    }

    void verlet2(Atoms &atoms, double timestep, double mass)
    {
        atoms.velocities += 0.5 * atoms.velocities * timestep / mass;
    }
};
