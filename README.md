# nBodySim
Parallel N-body simulator. Will be run on comet supercomputer at SDSC ⚡️

The toplevel directory structure of the submitted file is as follows 
.
├── comet_project
└── nBodySim

### Steps for compiling the code are as follows

1) Check whether there exists a directory called build inside nBodySim
2) cd build
3) cmake ..
4) make
5) Run the code using

    ./nbody -n 100 -s 100000
    
Use the command line option -h for additional flags

### Running on comet

I had problems compiling the code on COMET, as I couldn't use the cmake command for some reason.
In that case use the command below. You need to flatten the directory structure in that case to have all the files in the /include and /src directory in one place. This has already been done in the comet_project subdirectory, but that has a lot of data files in it

icpc -O3 -std=c++11 -qopenmp -xHOST -o nbody test.cpp particles.cpp solver.cpp

### Data

All the data, as well as scripts used to generate the data are located in the comet_project subdirectory
