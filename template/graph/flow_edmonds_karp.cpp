template <typename T> struct edmonds_karp {
public:
    static T INF;
    edmonds_karp(int n = 0) : size(n),
                              G(n + 1, vector<T>(n + 1)) {}
    void add(int u, int v, T w) {
        G[u][v] += w;
    }
    T bfs(int s, int t, vector<int> &p) {
        queue<tuple<int, T>> q;
        q.emplace(s, INF);
        p[s] = -1;
        while (!q.empty()) {
            auto [u, d] = q.front(); q.pop();
            if (u == t) return d;
            for (int v = 1; v <= size; v++) {
                if (p[v] != 0 || G[u][v] == T()) continue;
                p[v] = u;
                q.emplace(v, min(d, G[u][v]));
            }
        }
        return T();
    }
    void init(int s, int t) {
        vector<int> p(size + 1);
        max_flow = now_flow = 0;
        while ((now_flow = bfs(s, t, p)) != T()) {
            max_flow += now_flow;
            int u = t, fa;
            while (u != s) {
                fa = p[u];
                G[fa][u] -= now_flow;
                G[u][fa] += now_flow;
                u = fa;
            }
            fill(p.begin(), p.end(), 0);
        }
    }
    T val() {
        return max_flow;
    }
private:
    int size;
    T max_flow, now_flow;
    vector<vector<T>> G;
};