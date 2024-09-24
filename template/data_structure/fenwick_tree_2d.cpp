template <typename T> struct fenwick_tree_2d {
#define lowbit(x) ((x) & (-x))
public:
    fenwick_tree_2d(int n = 0, int m = 0) : n_size(n),
                                            m_size(m),
                                            node(n + 1, vector<T>(m + 1)) {}
    fenwick_tree_2d(vector<vector<T>> a) : fenwick_tree_2d(a.size() - 1, a[1].size() - 1) {
        for (int i = 1; i <= n_size; i++)
            for (int j = 1; j <= m_size; j++)
                update(i, j, a[i][j]);
    }
    void update(int x, int y, T v) {
        for (int i = x; i && i <= n_size; i += lowbit(i))
            for (int j = y; j && j <= m_size; j += lowbit(j))
                node[i][j] += v;
    }
    void update(int x, int y, int a, int b, T v) {
        ++a, ++b;
        update(x, y, v), update(x, b, -v);
        update(a, y, -v), update(a, b, v);
    }
    T query(int x, int y, T v = T()) {
        for (int i = x; i; i -= lowbit(i))
            for (int j = y; j; j -= lowbit(j))
                v += node[i][j];
        return v;
    }
    T query(int x, int y, int a, int b, T v = T()) {
        --x, --y;
        return v + query(a, b) - query(a, y) - query(x, b) + query(x, y);
    }
private:
    int n_size, m_size;
    vector<vector<T>> node;
#undef lowbit
};