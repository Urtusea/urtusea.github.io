# Fenwick Tree

## 代码

``` cpp
template <typename T> struct fenwick_tree {
public:
    #define lowbit(x) (x & -x)
    fenwick_tree(int _n)
    : n(_n), f(_n + 1) {}
    fenwick_tree(std::vector<T> Init)
    : fenwick_tree(Init.size() - 1) {
        for (int i = 1; i <= n; i++) {
            f[i] += Init[i];
            if (i + lowbit(i) <= n) {
                f[i + lowbit(i)] += f[i];
            }
        }
    }
    auto update(int u, T x) -> void {
        for (; 1 <= u && u <= n; f[u] += x, u += lowbit(u));
    }
    auto query(int u, T x = T()) -> T {
        for (; u; x += f[u], u -= lowbit(u)); return x;
    }
    auto find_first(T x) -> int {
        int res = 0;
        for (int i = 1 << std::__lg(n); i; i >>= 1) {
            if ((res | i) <= n && f[res | i] < x)
                x -= f[res | i];
        }
        return res + 1;
    }
    #undef lowbit
private:
    int n;
    std::vector<T> f;
};
```