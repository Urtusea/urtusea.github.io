template <typename Edge> struct SCC {
public:
    SCC(int _n = 0) : n(_n),
                      timer(0),
                      group(0),
                      dfn(_n + 1),
                      low(_n + 1),
                      scc(_n + 1),
                      G(_n + 1) {}
    int get(int u) {
        return scc[u];
    }
    int size() {
        return group;
    }
    void add(int u, Edge edge) {
        G[u].push_back(edge);
    }
    void init() {
        auto dfs = [&](auto &&self, int u)->void {
            static vector<int> stk;
            stk.push_back(u);
            dfn[u] = low[u] = ++timer;
            for (auto &edge : G[u]) {
                int &v = edge.v;
                if (!dfn[v]) {
                    self(self, v);
                    low[u] = min(low[u], low[v]);
                } else if (!scc[v]) {
                    low[u] = min(low[u], low[v]);
                }
            }
            if (dfn[u] == low[u]) {
                scc[u] = ++group;
                while (!stk.empty()) {
                    auto v = stk.back(); stk.pop_back();
                    scc[v] = scc[u];
                    if (u == v) break;
                }
            }
        };
        for (int i = 1; i <= n; i++)
            if (!dfn[i]) dfs(dfs, i);
    }
private:
    int n, timer, group;
    vector<int> dfn, low, scc;
    vector<vector<Edge>> G;
};