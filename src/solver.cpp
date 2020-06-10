#include"solver.hpp"
#include<iostream>
#include<fstream>
#include<string>
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
         # pragma omp parallel shared (p_arr)
        {
            # pragma omp for
            for(unsigned i=0 ; i<num_particles ; i++){
                double tmp = Particle::G * p_arr[i].mass;
                Vec3<double> f(0.0);
                for(unsigned j=0 ; j<num_particles ; j++){
                    if(i==j) continue;
                    Vec3<double> del = p_arr[j].position - p_arr[i].position;
                    double r = del.norm<double>();
                    f += p_arr[j].mass*del/(r*r*r);
                }
                p_arr[i].set_force(tmp*f);
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
    for(unsigned i=0 ; i<num_particles ; i++){
        std::ofstream f;
        f.open(std::to_string(i)+".dat");
        //f << "Particle " << i << "\n";
        //f << p_arr[i];
        for(const auto &v : p_arr[i].locations){
            f << v << "\n";
        }
        f.close();
    }
}

double Solver::total_energy(){
    double output = 0.0;
    for(unsigned i=0 ; i<num_particles ; i++){
        double tmp = Particle::G * p_arr[i].mass;
        double acc = 0.0;
        for(unsigned j=0 ; j<num_particles ; j++){
            if(i==j) continue;
            Vec3<double> del = p_arr[j].position - p_arr[i].position;
            double r = del.norm<double>();
            acc += p_arr[j].mass/r;
        }
        output += -1.0*acc*tmp;
    }
    for(const auto& p : p_arr){
        output += 0.5 * p.mass * p.velocity.dot(p.velocity);
    }
    return output;
}
 
