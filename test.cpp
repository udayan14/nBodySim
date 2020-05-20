#include<iostream>
#include"vec3.hpp"

int main(){
    Vec3<int> a(3);
    Vec3<int> b(1,2,3);
    Vec3<int> c(100,101,102);
    c += a;
    b *= 2;
    std::cout << a << "|" <<b << "|" << c << "\n";
    std::cout << a+b << "\n";
    std::cout << (Vec3<int>(1,3,4)).norm<float>() << "\n";
}
