template <typename T>
auto exgcd(T a, T b, T &x, T &y) -> T {
    T z[4] = {1, 0, 0, 1};
    for (T c; b; b && (c = a / b)) {
        std::tie(z[0], z[1], z[2], z[3], a, b) = std::make_tuple(
            z[2], z[3], z[0] - z[2] * c, z[1] - z[3] * c, b, a - b * c
        );
    }
    x = z[0], y = z[1];
    return a;
};