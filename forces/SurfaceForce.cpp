
#include "SurfaceForce.h"
#include "../System.h"
#include "../Kernels.h"

SurfaceForce::SurfaceForce(vector<Particle *, allocator<Particle *>> particles) {
    this->setTarget(particles);
}

void SurfaceForce::setTarget(std::vector<Particle *> particles) {
    this->particles = particles;
}

void SurfaceForce::apply(System *s) {
    //Tension coefficient water-air
    float sigma = 72.75f/100.f;
    float certainThreshold = .05f;

    // Evaluate surface force for every particle
    for (Particle *pi : particles) {
        Vector3f n = s->colorField->dEval(pi->position);
        if (n.norm() > certainThreshold) {
            pi->force += -sigma * s->colorField->ddEval(pi->position) * n / n.norm();
        }
    }
}

void SurfaceForce::draw() {
    // TODO draw a sample of the pressure force field at random points in the field or something
    // Maybe on particles instead, not sure
}