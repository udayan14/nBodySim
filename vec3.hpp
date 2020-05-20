#include<iostream>


template <class T>
class Vec3{
    private:
        T x,y,z;
    public:
        Vec3();
        Vec3(T);
        Vec3(T,T,T);
        void add(Vec3<T>);
        void s_mult(T);
        Vec3<T> operator*(const T &a);
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
void Vec3<T>::add(Vec3<T> b){
    x += b.x;
    y += b.y;
    x += b.z;
}

template<class T>
void Vec3<T>::s_mult(T a){
    x *= a;
    y *= a;
    z *= a;
}

template<class T>
Vec3<T> Vec3<T>::operator*(const T &a){
    return *this.s_mult(a);
}

template<class T>
std::ostream& operator<<(std::ostream& out, const Vec3<T> &v){
    return out << v.x << " " << v.y << " " << v.z;
}

