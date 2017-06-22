//
// Created by Ruud Andriessen on 11/06/2017.
//

#include "PressureField.h"
#include "../Kernels.h"
#include "../System.h"

Vector3f PressureField::eval(Particle* pi) {
    Vector3f force = Vector3f(0, 0, 0);

    vector<Particle*> targets = sys->grid.query(pi->position);
    for (Particle* pj : targets) {
        force += pj->mass * (pi->pressure + pj->pressure) / (2 * pj->density) * Spiky::dW(pi->position - pj->position);
    }
    return force;
}