# Mod Int

## 介绍

模数类是一种对值自动取模的类，在一类组合计数的题中不用担心自己哪里没有取模到位，十分方便

## 代码

``` cpp
template <typename T>
constexpr auto quick_power(T a, uInt b, T res = T(1)) -> T {
    for (; b; a *= a, b >>= 1) if (b & 1) res *= a; return res;
}

template <Int P> struct mod_int {
public:
    static Int M;
    constexpr static Int get_mod() {
        return P ? P : M;
    }
    constexpr static void set_mod(Int _M) {
        M = _M;
    }
    constexpr mod_int(Int _x = 0)
    : x(check(_x % get_mod())) {}
    constexpr Int check(Int val) const {
        if (val < 0)
            val += get_mod();
        if (val >= get_mod())
            val -= get_mod();
        return val;
    }
    constexpr mod_int inv() const {
        return quick_power(*this, get_mod() - 2);
    }
    constexpr mod_int operator - () const {
        return mod_int(check(get_mod() - *this));
    }
    constexpr mod_int &operator += (mod_int other) & { this->x = check(this->x + other.x); return *this; }
    constexpr mod_int &operator -= (mod_int other) & { this->x = check(this->x - other.x); return *this; }
    constexpr mod_int &operator *= (mod_int other) & { this->x = check(this->x * other.x % get_mod()); return *this; }
    constexpr mod_int &operator /= (mod_int other) & { this->x = check(this->x * other.inv() % get_mod()); return *this; }
    friend constexpr mod_int operator + (mod_int l, mod_int r) { return l += r; }
    friend constexpr mod_int operator - (mod_int l, mod_int r) { return l -= r; }
    friend constexpr mod_int operator * (mod_int l, mod_int r) { return l *= r; }
    friend constexpr mod_int operator / (mod_int l, mod_int r) { return l /= r; }
    friend constexpr bool operator == (mod_int l, mod_int r) { return l.x == r.x; }
    friend constexpr bool operator != (mod_int l, mod_int r) { return l.x != r.x; }
    friend constexpr std::istream &operator >> (std::istream &is, mod_int &val) {
        return is >> val.x, val = mod_int(val.x), is;
    }
    friend constexpr std::ostream &operator << (std::ostream &os, const mod_int &val) {
        return os << val.x;
    }
private:
    Int x;
};
```