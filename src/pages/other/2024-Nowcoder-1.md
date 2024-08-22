---
title: '2024-牛客多校-1'
layout: '../../layouts/Other.astro'
---

# 2024 牛客多校 1

## A. A Bit Common

<p></p>

``` cpp
#include <bits/stdc++.h>

template <typename T = long long>
constexpr T quick_power(T a, uint64_t b, T mod, T res = T(1)) {
    assert(b >= 0);
    for (; b; a = a * a % mod, b >>= 1)
        if (b & 1)
            res = res * a % mod;
    return res;
}

void code( /* Copyright By Urtusea */ )
{
    int n, m, mod;
    std::cin >> n >> m >> mod;

    std::vector c(n + 1, std::vector<int>(n + 1));
    for (int i = 0; i <= n; i += 1)
        c[i][0] = 1 % mod;
    for (int i = 1; i <= n; i += 1)
        for (int j = 1; j <= i; j += 1)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;

    long long ans = 0;
    for (int i = 1; i <= n; i += 1) {
        long long tmp1 = quick_power<long long>(2, (n - i) * (m - 1), mod);
        long long tmp2 = (quick_power<long long>(2, i, mod) - 1 + mod) % mod;

        ans += c[n][i] * tmp1 % mod * quick_power<long long>(tmp2, m - 1, mod) % mod;
        ans %= mod;
    }

    std::cout << ans << '\n';
}

int main(int argc, char *argv[], char *envp[])
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    // for (int i = 1, n = (std::cin >> n, n); i <= n; i += 1)
        code();

    return 0;
}
```

<p></p>