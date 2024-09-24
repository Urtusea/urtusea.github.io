template <typename T> struct fenwick_tree {
#define lowbit(x) ((x) & (-x))
public:
    fenwick_tree(int n = 0) : size(n),
                              node(n + 1) {}
    fenwick_tree(vector<T> a) : fenwick_tree(a.size() - 1) {
        for (int i = 1; i <= size; i += 1) {
            node[i] += a[i];
            if (i + lowbit(i) <= size)
                node[i + lowbit(i)] += node[i];
        }
    }
    void update(int u, T x) {
        for (; u && u <= size; u += lowbit(u)) node[u] += x;
    }
    T query(int u, T x = T()) {
        for (; u; u -= lowbit(u)) x += node[u]; return x;
    }
    int find_pref_k(Int k) {
        int ans = 0;
        for (int i = __lg(size); i >= 0; i--) {
            int res = ans | (1 << i);
            if (res <= size && node[res] < k)
                k -= node[res], ans = res;
        }
        return ans + 1;
    }
private:
    int size;
    vector<T> node;
#undef lowbit
};