uInt euler_phi(uInt x) {
    uInt res = x;
    for (int i = 2; 1LL * i * i <= x; i++) {
        if (x % i != 0) continue;
        res = res / i * (i - 1);
        while (x % i == 0)
            x /= i;
    }
    if (x > 1)
        res = res / x * (x - 1);
    return res;
}