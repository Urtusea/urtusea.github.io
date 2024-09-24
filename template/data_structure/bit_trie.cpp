template <int B> struct bit_trie {
using bit = bitset<B + 1>;
public:
    bit_trie(int n = 0, int m = 0) : last(0),
                                     root(m + 1),
                                     next(n * (B + 1) + 1) {}
    int to_next(int &p) {
        return p ? p : p = ++last;
    }
    void insert(int p, bit x) {
        int u = to_next(root[p]);
        for (int i = B; i >= 0; i--) {
            u = to_next(next[u][x[i]]);
        }
    }
    void merge(int u, int v) {
        auto opt = [&](auto &&self, int &u, int v)->void {
            if (!u || !v) return (void)(u |= v);
            merge(next[u][0], next[v][0]);
            merge(next[u][1], next[v][1]);
        };
        opt(opt, root[u], root[v]);
    }
    uInt query_max(int p, bit x, uInt res = 0) {
        int u = root[p];
        for (int i = B; i >= 0; i--) {
            if (next[u][!x[i]]) {
                res |= 1ULL << i;
                u = next[u][!x[i]];
            } else {
                u = next[u][x[i]];
            }
        }
        return res;
    }
    uInt query_min(int p, bit x, uInt res = 0) {
        int u = root[p];
        for (int i = B; i >= 0; i--) {
            if (next[u][x[i]]) {
                u = next[u][x[i]];
            } else {
                res |= 1ULL << i;
                u = next[u][!x[i]];
            }
        }
        return res;
    }
private:
    int last;
    vector<int> root;
    vector<int [2]> next;
};