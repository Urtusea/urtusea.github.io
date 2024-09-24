#include <bits/stdc++.h>

struct edge {
    int v, id;
    edge() : v(0), id(0) {}
    edge(int _v, int _id) : v(_v), id(_id) {}
};

auto tarjan_cut_edge(int n, int m, std::vector<std::vector<edge>> &G) -> std::vector<int> {
    static std::vector<int> dfn, low, cut;
    dfn.assign(n + 1, 0);
    low.assign(n + 1, 0);
    cut.assign(m * 2 + 2, 0);

    int timer = 0;
    auto tarjan = [&](auto &&self, int u, int pre_id) -> void {
        dfn[u] = low[u] = ++timer;

        for (auto &[v, id] : G[u]) {
            if (id == (pre_id ^ 1))
                continue;
            if (!dfn[v]) {
                self(self, v, id);
                low[u] = std::min(low[u], low[v]);
                if (low[v] > dfn[u])
                    cut[id] = cut[id ^ 1] = 1;
            } else {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
    };

    for (int u = 1; u <= n; ++u) if (!dfn[u]) tarjan(tarjan, u, 0);

    return cut;
}