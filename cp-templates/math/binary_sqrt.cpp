auto binary_sqrt(uInt n) -> uInt {
    uInt x = 0, y;
    for (int i = 31; i >= 0; --i) {
        y = x | (1LL << i);
        if (y * y <= n)
            x = y;
        if (y * y == n)
            return y;
    }
    return x;
}