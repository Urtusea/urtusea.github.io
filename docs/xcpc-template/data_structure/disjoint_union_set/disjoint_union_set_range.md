---
prev: false
next: false
---

# Disjoint Union Set Range - 倍增并查集

## 代码模板

``` cpp
struct disjoint_union_set {
  std::vector<std::vector<int>> set;

  disjoint_union_set(int n) : set(std::__lg(n) + 1, std::vector<int>(n + 1, -1)) {}

  int find(int k, int u) {
    return set[k][u] < 0 ? u : set[k][u] = find(k, set[k][u]);
  }

  void merge(int k, int u, int v) {
    if (u = find(k, u), v = find(k, v); u == v) return;
     set[k][u] <  set[k][v] ?
    (set[k][u] += set[k][v], set[k][v] = u):
    (set[k][v] += set[k][u], set[k][u] = v);
  }

  void merge_range(int k, int u, int v, auto&& call) {
    if (find(k, u) == find(k, v)) return;
    if (k == 0) {
      call(find(0, u), find(0, v));
    } else {
      merge_range(k - 1, u, v, call);
      merge_range(k - 1, u + (1 << (k - 1)), v + (1 << (k - 1)), call);
    }
    merge(k, u, v);
  }
};
```