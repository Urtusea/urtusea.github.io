template <typename T>
constexpr T quick_power(T a, uInt b, T res = T(1)) {
    for (; b; a *= a, b >>= 1) if (b & 1) res *= a; return res;
}