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
        Vec3<T> operator+(const Vec3<T> &) const;
        Vec3<T> operator*(const T &) const; 
        Vec3<T> operator/(const T &) const;
        Vec3<T> operator+=(const Vec3<T> &);
        Vec3<T> operator*=(const T &);
        Vec3<T> operator-() const;
        Vec3<T> operator-(const Vec3<T> &) const;
        Vec3<T> operator-=(const Vec3<T> &);
        T dot(const Vec3<T> &) const;

        template<class U>
        U norm() const;

        template<class U>
        friend std::ostream& operator<<(std::ostream& out, const Vec3<U> &v);

        template<class U>
        friend std::istream& operator>>(std::istream& in, Vec3<U> &v);
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
Vec3<T> Vec3<T>::operator+(const Vec3<T> &a) const{
    return Vec3(x+a.x, y+a.y, z+a.z);
}

template<class T>
Vec3<T> Vec3<T>::operator*(const T &a) const{
    return Vec3(a*x, a*y, a*z);
}

template<class T>
Vec3<T> operator*(const T &k, const Vec3<T> &vec){
    return vec.operator*(k);
}

template<class T>
Vec3<T> Vec3<T>::operator/(const T &a) const{
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
Vec3<T> Vec3<T>::operator-() const{
    (*this)*=-1;
    return *this;
}

template<class T>
Vec3<T> Vec3<T>::operator-(const Vec3<T> &a) const{
    return (*this) + -1*a;
}

template<class T>
Vec3<T> Vec3<T>::operator-=(const Vec3<T>&a){
    (*this) += -1*a;
    return *this;
}

template<class T>
T Vec3<T>::dot(const Vec3<T> &a) const{
    return (x*a.x + y*a.y + z*a.z);
}

template<class T>
template<class U>
U Vec3<T>::norm() const{
    return sqrt((*this).dot(*this));
}

template<class T>
std::ostream& operator<<(std::ostream& out, const Vec3<T> &v){
    return out << v.x << " " << v.y << " " << v.z;
}

template<class T>
std::istream& operator>>(std::istream& in, Vec3<T> &v){
    return in >> v.x >> v.y >> v.z;
}
