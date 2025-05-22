---
prev: false
next: false
---

# Disjoint Union Set - 路径压缩按秩合并并查集

## 使用示例

``` cpp
disjoint_union_set dsu(N);
dsu.find(int u);            // 查找 u 所在集合
dsu.merge(int u, int v);    // 合并 u, v 所在集合
```

## 代码模板

``` cpp
struct disjoint_union_set {
  std::vector<int> set;

  disjoint_union_set(int n) : set(n + 1, -1) {}

  int find(int u) {
    return set[u] < 0 ? u : set[u] = find(set[u]);
  }

  void merge(int u, int v) {
    if (u = find(u), v = find(v); u == v) return;
    set[u] <  set[v] ?
    set[u] += set[v], set[v] = u:
    set[v] += set[u], set[u] = v;
  }
};
```