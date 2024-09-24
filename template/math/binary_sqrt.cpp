uInt binary_sqrt(uInt n) {
    uInt x = 0;
    for (int i = 31; i >= 0; i--) {
        uInt y = x | (1ULL << i);
        if (y * y == n)
            return y;
        if (y * y <= n)
            x = y;
    }
    return x;
}