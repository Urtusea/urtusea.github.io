---
prev: false
next: false
---

# Lowest Common Ancestor - DFN序最近公共祖先

## 代码模板

``` cpp
struct lowest_common_ancestor {
  int size;
  std::vector<int> dfn;
  std::vector<std::vector<int>> st;

  int comp(int l, int r) const {
    return dfn[l] < dfn[r] ? l : r;
  }

  void build(int n, int root, const auto& G) {
    size = n;
    dfn.assign(n + 1, 0);
    st.assign(std::__lg(n) + 1, std::vector<int>(n + 1, 0));

    int timer = 0;
    const auto dfs = [&](auto&& self, int u, int p) -> void {
      st[0][dfn[u] = ++timer] = p;
      for (auto to : G[u]) {
        if (to.v == p) continue;
        self(self, to.v, u);
      }
    };
    dfs(dfs, root, 0);

    for (int k = 1; k <= std::__lg(n); k++)
      for (int i = 1; i + (1 << k) - 1 <= n; i++)
        st[k][i] = comp(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
  }

  int query(int u, int v) {
    if (u == v) return u;
    if (u = dfn[u], v = dfn[v]; u <= v) std::swap(u, v);
    int k = std::__lg(u - v++);
    return comp(st[k][v], st[k][u - (1 << k) + 1]);
  }
};
```