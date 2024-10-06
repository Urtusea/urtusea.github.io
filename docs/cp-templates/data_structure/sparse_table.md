# Sparse Table

## 代码

``` cpp
template <typename T> struct sparse_table {
public:
    sparse_table(int _n)
    : n(_n), f(std::__lg(n) + 1, std::vector<T>(_n + 1)) {}
    sparse_table(std::vector<T> info, auto &check)
    : sparse_table(info.size() - 1) {
        f[0] = info;
        for (int k = 1; k <= std::__lg(n); ++k)
            for (int i = 1; i + (1 << k) - 1 <= n; ++i)
                f[k][i] = check(f[k - 1][i], f[k - 1][i + (1 << k - 1)]);
    }
    auto query(int l, int r, auto &check) -> T {
        int k = std::__lg(r - l + 1);
        return check(f[k][l], f[k][r - (1 << k) + 1]);
    }
private:
    int n;
    std::vector<std::vector<T>> f;
};
```