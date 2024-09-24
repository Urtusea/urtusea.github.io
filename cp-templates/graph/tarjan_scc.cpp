#include <bits/stdc++.h>

struct edge {
    int v;
    edge() : v(0) {}
    edge(int _v) : v(_v) {}
};

auto tarjan_scc(int n, std::vector<std::vector<edge>> &G) -> std::tuple<int, std::vector<int>, std::vector<std::vector<edge>>> {
    static std::vector<int> dfn, low, scc;
    dfn.assign(n + 1, 0);
    low.assign(n + 1, 0);
    scc.assign(n + 1, 0);

    int timer = 0, scc_n = 0;
    auto tarjan = [&](auto &&self, int u) -> void {
        dfn[u] = low[u] = ++timer;

        static std::vector<int> stack;
        stack.push_back(u);

        for (auto &[v] : G[u]) {
            if (!dfn[v]) {
                self(self, v);
                low[u] = std::min(low[u], low[v]);
            } else if (!scc[v]) {
                low[u] = std::min(low[u], dfn[v]);
            }
        }

        if (dfn[u] == low[u] && ++scc_n) {
            while (!stack.empty()) {
                auto v = stack.back(); stack.pop_back();
                scc[v] = scc_n;
                if (v == u) break;
            }
        }
    };

    for (int u = 1; u <= n; ++u) if (!dfn[u]) tarjan(tarjan, u);

    std::vector<std::vector<edge>> scc_G(scc_n + 1);
    for (int u = 1; u <= n; ++u) {
        for (auto &[v] : G[u]) {
            if (scc[u] == scc[v]) continue;
            scc_G[scc[u]].push_back(scc[v]);
        }
    }

    return {scc_n, scc, scc_G};
}