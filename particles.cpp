#include "particles.hpp"

double Particle::t_step;

Particle::Particle(double m, Vec3<double> pos, Vec3<double> vel)
: mass(m), position(pos), velocity(vel)
{}

void Particle::update(){
    acceleration = force/mass;
    position += velocity*t_step + acceleration*t_step*t_step*0.5;
    velocity += acceleration * t_step;
    momentum += force * t_step;
}
