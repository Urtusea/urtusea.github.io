---
prev: false
next: false
---

# Range Graph - 线段树优化建图

## 代码模板

``` cpp
template <typename T> struct range_graph {
  using Edge = std::pair<int, T>;
  const int offset;
  std::vector<int> leaf;
  std::vector<std::vector<Edge>> edge;

  range_graph(int n) : offset(n << 2), leaf(n + 1), edge(n << 3) {}

  #define lson(p) (p << 1)
  #define rson(p) (p << 1 | 1)

  void build(int p, int l, int r) {
    if (l + 1 == r) return void(leaf[l] = p);
    int m = (l + r) >> 1;
    edge[p].push_back({lson(p), T()});
    edge[p].push_back({rson(p), T()});
    edge[lson(p) + offset].push_back({p + offset, T()});
    edge[rson(p) + offset].push_back({p + offset, T()});
    build(lson(p), l, m);
    build(rson(p), m, r);
    if (p == 1) {
      for (int i = 1; i < leaf.size(); i++) {
        edge[leaf[i]].push_back({leaf[i] + offset, T()});
        edge[leaf[i] + offset].push_back({leaf[i], T()});
      }
    }
  }

  void in_connect(int p, int l, int r, int L, int R, int v, const T& w = 0) {
    if (L <= l && r <= R) return edge[p + offset].push_back({leaf[v], w});
    int m = (l + r) >> 1;
    if (L < m) in_connect(lson(p), l, m, L, R, v, w);
    if (R > m) in_connect(rson(p), m, r, L, R, v, w);
  }

  void out_connect(int p, int l, int r, int L, int R, int u, const T& w = 0) {
    if (L <= l && r <= R) return edge[leaf[u] + offset].push_back({p, w});
    int m = (l + r) >> 1;
    if (L < m) out_connect(lson(p), l, m, L, R, u, w);
    if (R > m) out_connect(rson(p), m, r, L, R, u, w);
  }

  void dot_connect(int u, int v, const T& w = 0) {
    edge[leaf[u]].push_back({leaf[v], w});
  }
};
```