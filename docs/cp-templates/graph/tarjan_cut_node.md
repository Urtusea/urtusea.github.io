# Tarjan Cut Node

## 介绍

割边是指去掉一个点之后，图中的连通分量增加，那么该边为割点

## 代码

``` cpp
struct edge {
    int v;
    edge() : v(0) {}
    edge(int _v) : v(_v) {}
};

auto tarjan_cut_node(int n, std::vector<std::vector<edge>> &G) -> std::vector<int> {
    static std::vector<int> dfn, low, cut;
    dfn.assign(n + 1, 0);
    low.assign(n + 1, 0);
    cut.assign(n + 1, 0);

    int timer = 0, root;
    auto tarjan = [&](auto &&self, int u) -> void {
        dfn[u] = low[u] = ++timer;
        
        int cnt = 0;
        for (auto &[v] : G[u]) {
            if (!dfn[v]) {
                ++cnt;
                self(self, v);
                low[u] = std::min(low[u], low[v]);
                if (low[v] >= dfn[u] && u != root)
                    cut[u] = 1;
            } else {
                low[u] = std::min(low[u], dfn[v]);
            }
        }

        if (cnt >= 2 && u == root) cut[u] = 1;
    };

    for (int u = 1; u <= n; ++u)
        if (!dfn[u]) tarjan(tarjan, root = u);

    return cut;
}
```