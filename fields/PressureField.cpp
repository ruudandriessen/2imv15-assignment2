//
// Created by Ruud Andriessen on 11/06/2017.
//

#include "PressureField.h"
#include "../Kernels.h"
#include "../System.h"

Vector3f PressureField::eval(Particle* pi, UniformGrid &grid) {
    Vector3f force = Vector3f(0, 0, 0);
    for (Particle* pj : grid.query(pi->position)) {
        force -= pj->mass * (pi->pressure + pj->pressure) / (2 * pj->density) * Spiky::dW(pi->position - pj->position, .05f);
    }
    return force;
}