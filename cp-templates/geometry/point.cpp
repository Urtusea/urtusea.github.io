template <typename T> struct point {
public:
    point() : x(T()), y(T()) {}
    point(T _x, T _y) : x(_x), y(_y) {}
    
private:
    T x, y;
};