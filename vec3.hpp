#include<iostream>
#include<cmath>

template <class T>
class Vec3{
    private:
        T x,y,z;
    public:
        // default constructor
        Vec3();
        // constructor to put points on x = y = z
        Vec3(T);
        // 3d constructor
        Vec3(T,T,T);
        Vec3<T> operator+(const Vec3<T> &);
        Vec3<T> operator*(const T &);           /*TODO make multiplication commutative */
        Vec3<T> operator/(const T &);
        Vec3<T> operator+=(const Vec3<T> &);
        Vec3<T> operator*=(const T &);
        Vec3<T> operator-();
        Vec3<T> operator-(const Vec3<T> &);
        Vec3<T> operator-=(const Vec3<T> &);
        T dot(const Vec3<T> &);
        template<class U>
        U norm();
        template<class U>
        friend std::ostream& operator<<(std::ostream& out, const Vec3<U> &v);
};

template<class T>
Vec3<T>::Vec3()
: x(0.0), y(0.0), z(0.0)
{}

template<class T>
Vec3<T>::Vec3(T a)
: x(a), y(a), z(a)
{}

template<class T>
Vec3<T>::Vec3(T a, T b, T c)
: x(a), y(b), z(c)
{}

template<class T>
Vec3<T> Vec3<T>::operator+(const Vec3<T> &a){
    return Vec3(x+a.x, y+a.y, z+a.z);
}

template<class T>
Vec3<T> Vec3<T>::operator*(const T &a){
    return Vec3(a*x, a*y, a*z);
}

template<class T>
Vec3<T> Vec3<T>::operator/(const T &a){
    return (*this)*(1.0/a);
}

template<class T>
Vec3<T> Vec3<T>::operator+=(const Vec3<T> &a){
    x+=a.x;
    y+=a.y;
    z+=a.z;
    return *this;
}

template<class T>
Vec3<T> Vec3<T>::operator*=(const T &a){
    x*=a;
    y*=a;
    z*=a;
    return *this;
}

template<class T>
Vec3<T> Vec3<T>::operator-(){
    (*this)*=-1;
    return *this;
}

template<class T>
Vec3<T> Vec3<T>::operator-(const Vec3<T> &a){
    return (*this) + -1*a;
}

template<class T>
Vec3<T> Vec3<T>::operator-=(const Vec3<T>&a){
    (*this) += -1*a;
    return *this;
}

template<class T>
T Vec3<T>::dot(const Vec3<T> &a){
    return (x*a.x + y*a.y + z*a.z);
}

template<class T>
template<class U>
U Vec3<T>::norm(){
    return sqrt((*this).dot(*this));
}

template<class T>
std::ostream& operator<<(std::ostream& out, const Vec3<T> &v){
    return out << v.x << " " << v.y << " " << v.z;
}
