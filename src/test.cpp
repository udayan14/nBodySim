#include<iostream>
#include<vector>
#include"solver.hpp"

typedef Vec3<double> vec;

void run(Solver sol, int iterations, int length){
    sol.log();
    for(int i=0 ; i<iterations ; i++){
        if(i%length == 0)
            sol.log();
        sol.step();
    }
    sol.output();
}



int main(){
    Particle earth(6e24, vec(0,1.5e11,0), vec(30000,0,0));
    Particle sun(2e30, vec(0,0,0), vec( 0,0,0));
    Particle::t_step = 10.0;
    std::vector<Particle> particle_list;
    particle_list.push_back(earth);
    particle_list.push_back(sun);
    std::string method = "naive";
    Solver solver(particle_list,method);
    run(solver,10000,1000);
}
