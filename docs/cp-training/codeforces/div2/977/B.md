# [Codeforces Round 977 B - Maximize Mex](https://codeforces.com/contest/2021/problem/B)

## Tag: 模拟

## 思路

从小到大去遍历，看最大能构造到多少就不能构造了

## 代码

``` cpp
#include <bits/stdc++.h>

using Int  = int64_t;
using uInt = uint64_t;

auto code() -> void {
    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    
    std::map<int, int> cnt;
    for (int i = 1; i <= n; i++)
        cnt[a[i]]++;

    for (auto &[p, q] : cnt) {
        if (q > 1)
            cnt[p + x] += q - 1;
    }

    int mex = 0;
    while (cnt.count(mex))
        mex++;
    
    std::cout << mex << '\n';
}

auto main(int argc, char *argv[], char *envp[]) -> int {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    for (int i = 1, n = (std::cin >> n, n); i <= n; ++i)
        code();

    return 0;
}
```