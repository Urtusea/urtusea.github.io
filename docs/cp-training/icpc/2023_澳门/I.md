# I. Refresher into Midas

## Tag: 贪心，数学

## 题意

每次可隔 $a$ 秒获得 $160$ 的贡献，在冷却的时候可以使用一次刷新，使得贡献操作刷新，但刷新操作也自身进入 $b$ 秒的冷却，问 $m$ 秒内，最优操作可以获得多少贡献

## 思路

考虑刷新操作肯定是每次使用最佳

那么考虑 $b$ 秒冷却时，中间可以进行 $\lfloor \frac{b}{a} \rfloor$ 次 贡献操作，再加上刷新后又可以立即使用一次，就是 $\lfloor \frac{b}{a} \rfloor + 1$ 次操作

如果我们最后再等待一下，使得还可以再多使用一次贡献操作的话，就是可以进行 $\lceil \frac{b}{a} \rceil + 1$ 次操作

那么直接 $O(m)$ 转移即可

## 代码

``` cpp
#include <bits/stdc++.h>

using Int  = int64_t;
using uInt = uint64_t;

auto code() -> void {
    int a, b, m;
    std::cin >> a >> b >> m;

    std::vector<int> f(m + 1);
    f[0] = 2;

    int res = 0;
    for (int i = 0; i <= m; i++) {
        if (!f[i]) continue;
        res = std::max(res, f[i] + (m - i) / a);
        if (i + b <= m)
            f[i + b] = std::max(f[i + b], f[i] + (1 + b / a));
        if (i + (b + a - 1) / a * a <= m)
            f[i + (b + a - 1) / a * a] = std::max(f[i + (b + a - 1) / a * a], f[i] + (1 + (b + a - 1) / a));
    }

    std::cout << res * 160 << '\n';
}

auto main(int argc, char *argv[], char *envp[]) -> int {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    for (int i = 1, n = (std::cin >> n, n); i <= n; ++i)
        code();

    return 0;
}
```