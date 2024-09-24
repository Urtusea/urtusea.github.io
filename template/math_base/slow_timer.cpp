template <typename T>
constexpr T slow_timer(T a, uInt b, T res = T(0)) {
    for (; b; a += a, b >>= 1) if (b & 1) res += a; return res;
}