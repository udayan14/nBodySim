#include<iostream>
#include"particles.hpp"
int main(){
    Particle::t_step = 0.0001;
    Vec3<double> a(3.0);
    Vec3<double> b(1.0,2.0,3.0);
    Particle p = Particle();
    std::cout << "Enter a particle\n";
    std::cin >> p;
    std::cout << p << "\n";
    b *= 2;
    std::cout << a << "|" <<b << "\n";
    std::cout << a+b << "\n";
    std::cout << (Vec3<int>(1,3,4)).norm<float>() << "\n";
}
