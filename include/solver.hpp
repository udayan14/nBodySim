#pragma once
#include"particles.hpp"
#include<vector>
#include<string>
class Solver{
    public:
        unsigned num_particles;
        std::vector<Particle> p_arr;
        std::string method;
        Solver();
        Solver(const std::vector<Particle>&);
        Solver(const std::vector<Particle>&, std::string);
        void step();
        void log();
        void output();
        double total_energy();
};

