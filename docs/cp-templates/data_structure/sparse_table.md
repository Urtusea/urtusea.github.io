# Sparse Table

## 介绍

ST表是一种离线的维护区间信息的数据结构，该信息需要满足结合律

- 结合律: 设 $L$ 为左半部分信息，$R$ 为右半部分信息，那么需要满足 $L \ opt \ R = R \ opt \ L$

操作: 

- `query(l, r)`: 查询 $[l, r]$ 的信息
    - 复杂度: $O(1)$

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