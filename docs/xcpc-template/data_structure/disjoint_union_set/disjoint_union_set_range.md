---
prev: false
next: false
---

# Disjoint Union Set Range - 区间路径压缩按秩合并并查集

## 使用示例

``` cpp
/*
  注：
    区间合并合并是指
    (u, u + 1, u + 2, u + 3, u + len - 1)
    (v, v + 1, v + 2, v + 3, v + len - 1)
    使得所有的 u + i 和 v + i 合并，i ∈ [0, len)
*/
disjoint_union_set dsu(N);
// 查找从 u 开始，长度为 2^k 所在集合
dsu.find(int k, int u);
// 合并 [u, u + (1 << k)) 和 [v, v + (1 << k))，在合并 u + i 和 v + i 时调用 call(u + i, v + i);
dsu.merge_range(int k, int u, int v, func call);
```

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