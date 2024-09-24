template <typename T> struct line {
    pointer<T> a, b;
    constexpr line(pointer<T> _a = pointer<T>(), pointer<T> _b = pointer<T>()) :
        a(_a), b(_b) {}
    
    template <typename _T> operator line<_T>() {
        return line<_T>(pointer<_T>(a), pointer<_T>(b));
    }

    friend istream &operator >> (istream &is, line &l) {
        return is >> l.a >> l.b;
    }
    friend ostream &operator << (ostream &os, line &l) {
        return os << '<' << l.a << ", " << l.b << '>';
    }
};