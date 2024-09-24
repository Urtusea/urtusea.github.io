template <typename Edge> struct lowest_common_ancestor {
public:
    lowest_common_ancestor(int n = 0) : timestamp(0),
                                        dfn(n + 1),
                                        node(__lg(n) + 1, vector<int>(n + 1)) {}
    lowest_common_ancestor(int n, int root, vector<vector<Edge>> &G) : lowest_common_ancestor(n) {
        auto dfs = [&](auto &&self, int u, int p)->void {
            node[0][dfn[u] = ++timestamp] = p;
            for (auto &edge : G[u]) {
                if (edge.v == p) continue;
                self(self, edge.v, u);
            }
        };
        dfs(dfs, root, 0);
        for (int k = 1; k <= __lg(n); k++)
            for (int i = 1; i + (1 << k) - 1 <= n; i++)
                node[k][i] = check(node[k - 1][i], node[k - 1][i + (1 << k - 1)]);
    }
    int check(int x, int y) {
        return dfn[x] < dfn[y] ? x : y;
    }
    int query(int x, int y) {
        if (x == y)
            return x;
        if ((x = dfn[x]) > (y = dfn[y]))
            swap(x, y);
        int k = __lg(y - x);
        return check(node[k][x + 1], node[k][y - (1 << k) + 1]);
    }
private:
    int timestamp;
    vector<int> dfn;
    vector<vector<int>> node;
};