# A. (-1,1)-Sumplete

## Tag: 构造，模拟

## 题意

构造一个满足条件的 $01$ 矩阵

## 思路

注意力惊人题，神秘构造

考虑先将所有的 $+$ 均填上 $1$，那么横轴和/纵轴和只会存在大于 $0$ 的情况，如果还有小于 $0$ 的，那么直接输出 $No$

接下来再考虑如何填 $-$ 和缩减 $+$ 使得所有限制均满足条件

考虑填一个 $-$ 会使得横轴和/纵轴和 $-1$，缩减一个 $+$ 同理

那么不妨每次填纵轴和最小的 $x$ 个即可，暴力排序模拟

## 代码

``` cpp
#include <bits/stdc++.h>

using Int  = int64_t;
using uInt = uint64_t;

auto code() -> void {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> c(n + 1, std::vector<int>(n + 1));
    std::vector<std::vector<int>> s(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        std::string s; std::cin >> s;
        for (int j = 1; j <= n; j++) {
            c[i][j] = (s[j - 1] == '+' ? 1 : -1);
        }
    }

    std::vector<int> x(n + 1), y(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> x[i];
    for (int i = 1; i <= n; i++) std::cin >> y[i];

    auto select = [&](int i, int j) -> void {
        s[i][j] ^= 1, x[i] -= c[i][j], y[j] -= c[i][j], c[i][j] = -c[i][j];
    };

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (c[i][j] > 0) select(i, j);
    
    for (int i = 1; i <= n; i++)
        if (x[i] > 0 || y[i] > 0) return (void)(std::cout << "No\n");
    
    std::vector<int> xid(n + 2), yid(n + 2);
    for (int i = 1; i <= n; i++) xid[i] = yid[i] = i;
    
    std::sort(xid.begin() + 1, xid.begin() + n + 1, [&](int l, int r) { return x[l] < x[r]; });
    for (int i = 1, ii = xid[i]; i <= n; ii = xid[++i]) {
        std::sort(yid.begin() + 1, yid.begin() + n + 1, [&](int l, int r) { return y[l] < y[r]; });
        for (int j = 1, jj = yid[j]; j <= n; jj = yid[++j]) {
            if (x[ii] == 0 || y[jj] == 0) continue;
            select(ii, jj);
        }
    }

    for (int i = 1; i <= n; i++)
        if (x[i] || y[i]) return (void)(std::cout << "No\n");
    
    std::cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            std::cout << s[i][j];
        std::cout << '\n';
    }
}

auto main(int argc, char *argv[], char *envp[]) -> int {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    // for (int i = 1, n = (std::cin >> n, n); i <= n; ++i)
        code();

    return 0;
}
```