#include "particles.hpp"

double Particle::t_step = 1.0;
double Particle::G = 6.67408e-11;   //m3 kg - 1 s - 2

Particle::Particle(double m, Vec3<double> pos, Vec3<double> vel)
: mass(m), position(pos), velocity(vel)
{}

Particle::Particle()
: mass(1.0), position(), velocity()
{}

void Particle::set_force(Vec3<double> f){
    force = f;
}

std::ostream& operator<<(std::ostream& out, const Particle &p){
    return out << "mass: " << p.mass << "\tpos: " << p.position << "\tvel: " << p.velocity;
}

std::istream& operator>>(std::istream& in, Particle &p){
    return in >> p.mass >> p.position >> p.velocity;
}

void Particle::update(){
    acceleration = force/mass;
    position += velocity*t_step + 0.5*acceleration*t_step*t_step;
    velocity += acceleration * t_step;
    momentum += force * t_step;
}
