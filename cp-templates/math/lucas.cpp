struct lucas {
public:
    lucas(Int _p) : p(_p), fac(_p + 1), inv(_p + 1) {
        fac[0] = fac[1] = inv[0] = inv[1] = 1;
        for (int i = 2; i <= p; ++i) {
            fac[i] = fac[i - 1] * i % p;
            inv[i] = (p - p / i) * inv[p % i] % p;
        }
        for (int i = 2; i <= p; ++i)
            inv[i] = inv[i] * inv[i - 1] % p;
    }
    Int c(Int n, Int m) {
        if (n < m)
            return 0;
        else if (n < p)
            return fac[n] * inv[m] % p * inv[n - m] % p;
        else
            return c(n / p, m / p) * c(n % p, m % p) % p;
    }
private:
    Int p;
    std::vector<Int> fac, inv;
};