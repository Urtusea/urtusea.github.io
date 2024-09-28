# J. Teleportation

## Tag: 图论，分层图

## 题意

你初始点在 $0$，需要到达 $x$，对于每秒你均可以进行以下两种操作之一:

- 到达 $(i + a_i) \ mod \ n$ 处
- $a_i = a_i + 1$

问到达 $x$ 最少需要几秒

## 思路

考虑建图，一种是已经使用过一次传送的 $i + n$，一种是暂未使用传送的 $i$

只需要将 $(i, n + (i + a_i) \ mod \n)，(n + i, n + (i + 1) \ mod \ n)，(n + i, i)$ 进行连边即可

跑 $01$ $BFS$ 即可

## 代码

``` cpp
#include <bits/stdc++.h>

using Int  = int64_t;
using uInt = uint64_t;

struct edge {
    int v, w;
    edge()
    : v(0), w(0) {}
    edge(int _v, int _w)
    : v(_v), w(_w) {}
};

auto code() -> void {
    int n, x;
    std::cin >> n >> x;

    std::vector<std::vector<edge>> e(2 * n);
    for (int u = 0, v; u < n; u++) {
        std::cin >> v;
        e[u].emplace_back(n + (u + v) % n, 1);
        e[u + n].emplace_back(n + (u + 1) % n, 1);
        e[u + n].emplace_back(u, 0);
    }

    std::vector<int> dis(2 * n, 1e6);
    dis[0] = 0;

    std::queue<int> q;
    q.push(0);

    while (!q.empty()) {
        auto u = q.front(); q.pop();
        for (auto &[v, w] : e[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push(v);
            }
        }
    }

    std::cout << dis[x] << '\n';
}

auto main(int argc, char *argv[], char *envp[]) -> int {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    // for (int i = 1, n = (std::cin >> n, n); i <= n; ++i)
        code();

    return 0;
}
```