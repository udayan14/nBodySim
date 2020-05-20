template <class T>
class Vec3{
    private:
        T x,y,z;
    public:
        Vec3(T);
        Vec3(T,T,T);
};

template<class T>
Vec3<T>::Vec3(T a)
: x(a), y(a), z(a)
{}

template<class T>
Vec3<T>::Vec3(T a, T b, T c)
: x(a), y(b), z(c)
{}
