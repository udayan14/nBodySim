#include<cstdlib>
#include<ctime>
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<random>
#include"solver.hpp"
#include <omp.h>
typedef Vec3<double> vec;

std::random_device rd;
std::mt19937 e(rd());
std::uniform_real_distribution<double> dist(-1,1);


static void show_usage(std::string name){
    std::cerr << "Usage: " << name << " <option(s)> SOURCES"
              << "Options:\n"
              << "\t-h,--help\t\tShow this help message\n"
              << "\t-i,--inputFile ParticleFile\tSpecify the initial positions and velocities of particles\n"
              << "\t-n,--numParticles N\t Number of random particles to use if inputFile is not specified. By default 100\n"
              << "\t-s,--numSteps N\t number of timesteps to compute. By default 1000000\n"
              << "\t-t,--timeStep T\t length of the timestep. By default 1e-6\n"
              << "\t-G,--G val\tThe value of the universal constant of Gravitation. By default 1.0\n"
              << "\t-p,--Log\tWhether to log the output of each particle. By default false\n"
              << "\t-l,--numLogs\tNumber of log entries per particle, By default 100"
              << std::endl;
}


void run(Solver sol, int iterations, int length, bool output_log){
    double init_E = sol.total_energy();
    double wtime = omp_get_wtime();
    if(output_log) sol.log();
    for(int i=0 ; i<iterations ; i++){
        if(output_log && (i%length == 0))
            sol.log();
        sol.step();
    }
    wtime = omp_get_wtime() - wtime;
    std::cout << "Time elapsed : " << wtime << "\n";
    double final_E = sol.total_energy();
    std::cout << "The initial Total Energy of the system is: " << init_E << "\n";
    std::cout << "The final Total Energy of the system is: " << final_E << "\n";
    std::cout << "The percentage change in the Total Energy is " << 100.0*(final_E-init_E)/init_E << "\n";
    if(output_log) sol.output();

}



int main(int argc, char* argv[]){
    srand(time(0));
    //Particle earth(6e24, vec(0,1.5e11,0), vec(30000,0,0));
    //Particle sun(2e30, vec(0,0,0), vec( 0,0,0));
    Particle::t_step = 1e-6;
    Particle::G = 1.0;
    int num_particles = 100;
    int num_time_steps = 1000000;
    int num_logs = 100;
    bool do_log = false;
    bool do_random = true;
    std::vector<Particle> particle_list;
    
    for(int i=1 ; i<argc ; i++){
        std::string arg = argv[i];
        if(arg=="-h" || arg=="--help"){
            show_usage(argv[0]);
            return 0;
        }
        else if(arg=="-n" || arg=="--numParticles"){
            if(i+1<argc){
                num_particles = std::stoi(argv[++i]);
            }
            else{
                show_usage(argv[0]);
                return 0;
            }
        }
        else if(arg=="-s" || arg=="--numSteps"){
            if(i+1<argc){
                num_time_steps = std::stoi(argv[++i]);
            }
            else{
                show_usage(argv[0]);
                return 0;
            }
        }
        else if(arg=="-t" || arg=="--timeStep"){
            if(i+1<argc){
                Particle::t_step = std::stod(argv[++i]);
            }
            else{
                show_usage(argv[0]);
                return 0;
            }
        }
        else if(arg=="-G" || arg=="--G"){
            if(i+1<argc){
                Particle::G = std::stod(argv[++i]);
            }
            else{
                show_usage(argv[0]);
                return 0;
            }
        }
        else if(arg=="-l" || arg=="--numLogs"){
            if(i+1<argc){
                num_logs = std::stoi(argv[++i]);
            }
            else{
                show_usage(argv[0]);
                return 0;
            }
        }
        else if(arg=="-p" || arg=="--Log"){
               do_log = true;
        }
        else if(arg=="-i" || arg=="--inputFile"){
            if(i+1<argc){
                do_random = false;
                std::string filepath = argv[++i];
                std::ifstream f;
                f.open(filepath);
                Particle p;
                while(f >> p)
                    particle_list.push_back(p);
                f.close();
            }
            else{
                show_usage(argv[0]);
                return 0;
            }
        }
    }
    if(do_random){
        for(int i=0 ; i < num_particles ; i++){
            double mass = dist(e);
            if(mass<0) mass*=-1.0;
            vec pos(dist(e),dist(e),dist(e));
            vec vel(dist(e),dist(e),dist(e));
            pos*=10.0;
            particle_list.push_back(Particle(mass,pos,vel));
        }
    }

    std::cout << "\n";
    std::cout << "N body Simulation:\n";
    std::cout << "C++/OpenMP version\n";
    std::cout << "Computes the future of N particles bound by gravity\n";

    std::cout << "\n";
    std::cout << "The number of processors available = " << omp_get_num_procs() << "\n";
    std::cout << "The number of threads available = " << omp_get_max_threads() << "\n";
    std::cout << "The number of particles in the system is " << num_particles << " and the we go " << num_time_steps << " in the future\n";


    //particle_list.push_back(earth);
    //particle_list.push_back(sun);
    std::string method = "naive";
    Solver solver(particle_list,method);
    run(solver,num_time_steps,num_time_steps/num_logs,do_log);
}
