# D. 

## Tag: 图论，模拟，分类讨论

## 题意

给你一张无向图 $G(V, E)$，节点的度最多为 $3$，每条边均有颜色 $0/1$，问你有多少个导出子图满足:

- 只看颜色为 $0$ 的边，图连通
- 只看颜色为 $1$ 的边，图连通

## 思路

由于节点的度最多为 $3$，那么节点数为 $n$ 的导出子图，最多有 $\lfloor \frac{3}{2} n \rfloor$ 条边，又由于需要满足连通的条件，那么两种颜色各至少需要 $n - 1$ 条边

那么我们可以建立以下不等式:

$$
    2 · (n - 1) \le \frac{3}{2} n
$$

可以解得 $n \le 4$，所以我们只需要去讨论这个导出子图大小小于等于 $4$ 的情况就可以了

## 代码

``` cpp
#include <bits/stdc++.h>

using Int  = int64_t;
using uInt = uint64_t;

auto code() -> void {
    int n, m;
    std::cin >> n >> m;

    Int ans[5] = {0, n, 0, 0, 0};
    std::vector cnt(2, std::vector(n + 1, std::unordered_set<int>()));
    std::vector e(2, std::vector<std::vector<int>>(n + 1));

    for (int i = 1; i <= m; i++) {
        int u, v, c;
        std::cin >> u >> v >> c;
        e[c][u].emplace_back(v);
        e[c][v].emplace_back(u);
        cnt[c][u].insert(v);
        cnt[c][v].insert(u);
    }

    for (int u = 1; u <= n; u++) {
        for (auto &v : e[0][u]) {
            if (cnt[1][u].count(v)) ans[2]++;
        }
    }
    ans[2] /= 2;

    for (int u = 1; u <= n; u++) {
        for (int i = 0; i < e[0][u].size(); i++) {
            for (int j = i + 1; j < e[0][u].size(); j++) {
                if (e[0][u][i] == e[0][u][j]) continue;
                int &v1 = e[0][u][i];
                int &v2 = e[0][u][j];

                int cnt_degree = 0;
                if (cnt[1][u].count(v1)) cnt_degree++;
                if (cnt[1][u].count(v2)) cnt_degree++;
                if (cnt[1][v1].count(v2)) cnt_degree++;
                if (cnt_degree == 2) ans[3]++;
            }
        }
    }

    auto dfs = [&](auto &&self, int u, std::vector<int> &V) -> void {
        if (V.size() == 4) {
            int cnt_degree = 0;
            for (int i = 0; i < 4; i++) {
                for (int j = i + 1; j < 4; j++) {
                    int &u1 = V[i];
                    int &u2 = V[j];
                    if (cnt[1][u1].count(u2)) cnt_degree++;
                }
            }
            if (cnt_degree == 3) ans[4]++;
        } else {
            for (auto &v : e[0][u]) {
                if (std::count(V.begin(), V.end(), v) == 1) continue;
                V.push_back(v);
                self(self, v, V);
                V.pop_back();
            }
        }
    };

    for (int u = 1; u <= n; u++) {
        std::vector<int> v;
        v.push_back(u);
        dfs(dfs, u, v);
    }
    ans[4] /= 2;

    std::cout << ans[1] + ans[2] + ans[3] + ans[4] << '\n';
}

auto main(int argc, char *argv[], char *envp[]) -> int {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    // for (int i = 1, n = (std::cin >> n, n); i <= n; ++i)
        code();

    return 0;
}
```