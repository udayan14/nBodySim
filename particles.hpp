#include"Vec3.hpp"

class Particle{
    //Might not need all these vectors;
    public:
        static double t_step;
        Particle(double,Vec3<double>,Vec3<double>); // mass, position, velocity in that order;
        void set_force(Vec3<double>);
        friend std::ostream& operator<<(std::ostream&, const Particle &p);
    private:
        Vec3<double> position;
        Vec3<double> velocity;
        Vec3<double> acceleration;
        Vec3<double> momentum;
        Vec3<double> force;         // Net total force on the particle
        double mass;

        void update();             //Perform the update according to laws of motion
};
