#include <bits/stdc++.h>

struct edge {
    int v, id;
    edge() : v(0), id(0) {}
    edge(int _v, int _id) : v(_v), id(_id) {}
};

auto tarjan_ebcc(int n, std::vector<std::vector<edge>> &G) -> std::tuple<int, std::vector<int>, std::vector<std::vector<edge>>> {
    static std::vector<int> dfn, low, bcc;
    dfn.assign(n + 1, 0);
    low.assign(n + 1, 0);
    bcc.assign(n + 1, 0);

    int timer = 0, bcc_n = 0;
    auto tarjan = [&](auto &&self, int u, int pre_id) -> void {
        dfn[u] = low[u] = ++timer;
        
        static std::vector<int> stack;
        stack.push_back(u);

        for (auto &[v, id] : G[u]) {
            if (id == (pre_id ^ 1))
                continue;
            if (!dfn[v]) {
                self(self, v, id);
                low[u] = std::min(low[u], low[v]);
            } else if (!bcc[v]) {
                low[u] = std::min(low[u], dfn[v]);
            }
        }

        if (dfn[u] == low[u] && ++bcc_n) {
            while (!stack.empty()) {
                auto v = stack.back(); stack.pop_back();
                bcc[v] = bcc_n;
                if (v == u) break;
            }
        }
    };

    for (int u = 1; u <= n; ++u) if (!dfn[u]) tarjan(tarjan, u, 0);

    std::vector<std::vector<edge>> bcc_G(bcc_n + 1);
    for (int u = 1; u <= n; ++u) {
        for (auto &[v, id] : G[u]) {
            if (bcc[u] == bcc[v]) continue;
            bcc_G[bcc[u]].emplace_back(bcc[v], 0);
        }
    }

    return {bcc_n, bcc, bcc_G};
}