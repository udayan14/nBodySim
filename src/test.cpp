#include<cstdlib>
#include<ctime>
#include<iostream>
#include<vector>
#include<random>
#include"solver.hpp"
#include <omp.h>
typedef Vec3<double> vec;

std::random_device rd;
std::mt19937 e(rd());
std::uniform_real_distribution<double> dist(-1,1);

void run(Solver sol, int iterations, int length){
    double wtime = omp_get_wtime();
    sol.log();
    for(int i=0 ; i<iterations ; i++){
        if(i%length == 0)
            sol.log();
        sol.step();
    }
    wtime = omp_get_wtime() - wtime;
    std::cout << "Time elapsed : " << wtime << "\n";
    //sol.output();

}



int main(){
    srand(time(0));
    //Particle earth(6e24, vec(0,1.5e11,0), vec(30000,0,0));
    //Particle sun(2e30, vec(0,0,0), vec( 0,0,0));
    Particle::t_step = 0.01;
    Particle::G = 1.0;
    std::vector<Particle> particle_list;
    int num_particles = 100;
    int num_time_steps = 100000;

    std::cout << "\n";
    std::cout << "N body Simulation:\n";
    std::cout << "C++/OpenMP version\n";
    std::cout << "Computes the future of N partcicles bound by gravity\n";

    std::cout << "\n";
    std::cout << "The number of processors available = " << omp_get_num_procs() << "\n";
    std::cout << "The number of threads available = " << omp_get_max_threads() << "\n";
    std::cout << "The number of particles in the system is " << num_particles << " and the we go " << num_time_steps << " in the future\n";

    for(int i=0 ; i < num_particles ; i++){
        double mass = dist(e);
        if(mass<0) mass*=-1.0;
        vec pos(dist(e),dist(e),dist(e));
        vec vel(dist(e),dist(e),dist(e));
        pos*=10.0;
        particle_list.push_back(Particle(mass,pos,vel));
    }

    //particle_list.push_back(earth);
    //particle_list.push_back(sun);
    std::string method = "naive";
    Solver solver(particle_list,method);
    run(solver,num_time_steps,num_time_steps/10);
}
