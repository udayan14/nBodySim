#include"solver.hpp"
#include<iostream>
#include<omp.h>
//class Solver{
    //public:
        //vector<Particles> p_arr;
        //string method;
        //Solver();
        //Solver(vector<Particles>&);
        //Solver(vector<Particles>, string);
        //step();
//};

Solver::Solver(){
    method="naive";
    num_particles = 0;
}

Solver::Solver(const std::vector<Particle>& v){
    num_particles = v.size();
    p_arr = v;
    method = "naive";
}

Solver::Solver(const std::vector<Particle>& v, std::string s){
    num_particles = v.size();
    p_arr = v;
    method = s;
}

void Solver::step(){
    if(method=="naive"){
        // Calculate forces
        for(int i=0 ; i<num_particles ; i++){
            double tmp = Particle::G * p_arr[i].mass;
            for(int j=i+i ; j<num_particles ; j++){
                Vec3<double> del = p_arr[j].position - p_arr[i].position;
                double r = del.norm<double>();
                Vec3<double> f = tmp*p_arr[j].mass*del/(r*r*r);
                p_arr[i].set_force(f);
                p_arr[j].set_force(-f);
            }
        }
        for(auto &p : p_arr){
            p.update();
        }
    }
}

void Solver::log(){
    for(auto &p : p_arr){
        p.locations.push_back(p.position);
    }
}

void Solver::output(){
    for(int i=0 ; i<num_particles ; i++){
        std::cout << "Particle " << i << "\n";
        std::cout << p_arr[i];
        for(const auto &v : p_arr[i].locations){
            std::cout << v << "\n";
        }
        std::cout << "\n";
    }
}
