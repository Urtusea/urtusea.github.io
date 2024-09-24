# Disjoint Set Union

## 介绍

并查集是一种管理元素所属集合的数据结构，其用一个森林实现，一棵树维护个集合

操作:

- `find(u)` : 查询元素 `u` 的所属集合
    - 复杂度 : $O(1)$

- `merge(u, v)` : 将元素 `u`, `v` 的所属集合合并
    - 复杂度 : $O(1)$

## 代码

``` cpp
struct disjoint_set_union {
public:
    disjoint_set_union(int n) : f(n + 1), g(n + 1) {
        for (int i = 1; i <= n; ++i) f[i] = i, g[i] = 1;
    }
    auto find(int x) -> int {
        return x == f[x] ? x : f[x] = find(f[x]);
    }
    auto check(int x, int y) -> bool {
        return find(x) == find(y);
    }
    auto merge(int x, int y) -> void {
        if ((x = find(x)) == (y = find(y)))
            return;
        if (g[x] >= g[y])
            g[x] += g[y], f[y] = x;
        else    
            g[y] += g[x], f[x] = y;
    }
private:
    std::vector<int> f, g;
};
```