template <typename T> struct pointer {
    T x, y;
    constexpr pointer(T _x = 0, T _y = 0) : x(_x), y(_y) {}
    
    template <typename _T> operator pointer<_T>() {
        return pointer<_T>(_T(x), _T(y));
    }
    
    pointer &operator += (pointer p) & { return x += p.x, y += p.y, *this; }
    pointer &operator -= (pointer p) & { return x -= p.x, y -= p.y, *this; }
    pointer &operator *= (pointer p) & { return x *= p.x, y *= p.y, *this; }
    pointer &operator /= (pointer p) & { return x /= p.x, y /= p.y, *this; }
    pointer &operator += (T offset) & { return x += offset, y += offset, *this; }
    pointer &operator -= (T offset) & { return x -= offset, y += offset, *this; }
    pointer &operator *= (T offset) & { return x *= offset, y *= offset, *this; }
    pointer &operator /= (T offset) & { return x /= offset, y /= offset, *this; }
    pointer operator - () const { return pointer(-x, -y); }
    friend pointer operator + (pointer a, pointer b) { return a += b; }
    friend pointer operator - (pointer a, pointer b) { return a -= b; }
    friend pointer operator * (pointer a, pointer b) { return a *= b; }
    friend pointer operator / (pointer a, pointer b) { return a /= b; }
    friend pointer operator + (pointer a, T b) { return a += b; }
    friend pointer operator - (pointer a, T b) { return a -= b; }
    friend pointer operator * (pointer a, T b) { return a *= b; }
    friend pointer operator / (pointer a, T b) { return a /= b; }
    friend bool operator < (pointer a, pointer b) {
        return equal(a.x, b.x) ? a.y < b.y - EPS : a.x < b.x - EPS;
    }
    friend bool operator > (pointer a, pointer b) {
        return equal(b.x, a.x) ? b.y < a.y - EPS : b.x < a.x - EPS;
    }
    friend bool operator == (pointer a, pointer b) { return !(a < b) && !(a > b); }
    friend bool operator != (pointer a, pointer b) { return a < b || a > b; }
    friend istream &operator >> (istream &is, pointer &p) {
        return is >> p.x >> p.y;
    }
    friend ostream &operator << (ostream &os, pointer &p) {
        return os << '(' << p.x << ", " << p.y << ')';
    }
};