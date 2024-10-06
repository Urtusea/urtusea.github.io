# [Codeforces Round 977 A - Meaning Mean](https://codeforces.com/contest/2021/problem/A)

## Tag: 贪心，模拟

## 思路

考虑要让最大的数进行更少次数的 $÷2$ 操作，每次贪心的选最小的两个即可

## 代码

``` cpp
#include <bits/stdc++.h>

using Int  = int64_t;
using uInt = uint64_t;

auto code() -> void {
    int n;
    std::cin >> n;

    std::vector<Int> p(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> p[i];

    std::priority_queue<Int, std::vector<Int>, std::greater<Int>> pq;
    for (int i = 1; i <= n; i++)
        pq.push(p[i]);
    
    while (pq.size() > 1) {
        Int a = pq.top(); pq.pop();
        Int b = pq.top(); pq.pop();
        pq.push(a + b >> 1);
    }

    std::cout << pq.top() << '\n';
}

auto main(int argc, char *argv[], char *envp[]) -> int {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    for (int i = 1, n = (std::cin >> n, n); i <= n; ++i)
        code();

    return 0;
}
```