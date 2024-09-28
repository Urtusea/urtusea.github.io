# Tarjan VBCC

## 介绍

点双连通分量是指该连通分量里，去掉任意一个点都不会使得该连通分量不连通

## 代码

``` cpp
struct edge {
    int v;
    edge() : v(0) {}
    edge(int _v) : v(_v) {}
};

auto tarjan_vbcc(int n, std::vector<std::vector<edge>> &G) -> std::tuple<int, std::vector<std::vector<int>>> {
    static std::vector<int> dfn, low;
    static std::vector<std::vector<int>> bcc;
    dfn.assign(n + 1, 0);
    low.assign(n + 1, 0);

    int timer = 0, bcc_n = 0;
    auto tarjan = [&](auto &&self, int u) -> void {
        dfn[u] = low[u] = ++timer;
        
        static std::vector<int> stack;
        if (G[u].empty() && ++bcc_n)
            return (void)(bcc.push_back(std::vector<int>(1, u)));
        else
            stack.push_back(u);

        for (auto &[v] : G[u]) {
            if (!dfn[v]) {
                self(self, v);
                low[u] = std::min(low[u], low[v]);
                if (low[v] >= dfn[u] && ++bcc_n) {
                    bcc.push_back(std::vector<int>());
                    while (!stack.empty()) {
                        auto p = stack.back(); stack.pop_back();
                        bcc[bcc_n - 1].push_back(p);
                        if (p == v) break;
                    }
                    bcc[bcc_n - 1].push_back(u);
                }
            } else {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
    };

    for (int u = 1; u <= n; ++u)
        if (!dfn[u]) tarjan(tarjan, u);

    return {bcc_n, bcc};
}
```