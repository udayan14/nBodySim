#include "particles.hpp"

double Particle::t_step;

Particle::Particle(double m, Vec3<double> pos, Vec3<double> vel)
: mass(m), position(pos), velocity(vel)
{}

void Particle::set_force(Vec3<double> f){
    force = f;
}

std::ostream& operator<<(std::ostream& out, const Particle &p){
    return out << "mass: " << p.mass << "\tpos: " << p.position << "\tvel: " << p.velocity;
}

void Particle::update(){
    acceleration = force/mass;
    position += velocity*t_step + 0.5*acceleration*t_step*t_step;
    velocity += acceleration * t_step;
    momentum += force * t_step;
}
