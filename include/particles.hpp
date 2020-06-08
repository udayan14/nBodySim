#pragma once
#include"Vec3.hpp"
#include<deque>
class Particle{
    //Might not need all these vectors;
    public:
        static double t_step;
        static double G;
                double mass;
        Vec3<double> position;
        void update();
        Particle();
        Particle(double,Vec3<double>,Vec3<double>); // mass, position, velocity in that order;
        void set_force(Vec3<double>);
        std::deque<Vec3<double> > locations;
        friend std::ostream& operator<<(std::ostream&, const Particle &p);
        friend std::istream& operator>>(std::istream&, Particle &p);
    //Perform the update according to laws of motion
    private:
        Vec3<double> velocity;
        Vec3<double> acceleration;
        Vec3<double> momentum;
        Vec3<double> force;         // Net total force on the particle
};
