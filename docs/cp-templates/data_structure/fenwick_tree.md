# Fenwick Tree

## 介绍

树状数组是一种维护序列前缀信息的数据结构，该信息需要满足结合律

- 结合律: 设 $L$ 为左半部分信息，$R$ 为右半部分信息，那么需要满足 $L \ opt \ R = R \ opt \ L$

操作:

- `update(u, x)` : 将原序列的 `u` 位置依据 `x` 去更新
    - 复杂度 : $O(logn)$

- `query(u, x)` : 以 `x` 为初始值查询原序列 $[1, u]$ 的前缀信息
    - 复杂度 : $O(logn)$

## 代码

``` cpp
template <typename T> struct fenwick_tree {
public:
    #define lowbit(x) (x & -x)
    fenwick_tree(int _n) : n(_n), f(_n + 1) {}
    fenwick_tree(std::vector<T> Init) : fenwick_tree(Init.size() - 1) {
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