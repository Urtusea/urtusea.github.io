---
prev: false
next: false
---

# Tarjan Cut Edge - 割边

## 代码模板

``` cpp
std::vector<int> tarjan_cut_edge(int n, int m, const auto& G) {
  std::vector<int> dfn(n + 1);
  std::vector<int> low(n + 1);
  std::vector<int> cut(2 * m + 2);

  int timer = 0;
  const auto tarjan = [&](auto&& self, int u, int pid) -> void {
    dfn[u] = low[u] = ++timer;

    for (auto to : G[u]) {
      if (to.id == (pid ^ 1)) continue;
      
      if (!dfn[to.v]) {
        self(self, to.v, to.id);
        low[u] = std::min(low[u], low[to.v]);
        if (low[to.v] > dfn[u])
          cut[to.id] = cut[to.id ^ 1] = 1;
      } else {
        low[u] = std::min(low[u], dfn[to.v]);
      }
    }
  };
  
  for (int u = 1; u <= n; u++)
    if (!dfn[u]) tarjan(tarjan, u, 0);
    
  return cut;
}
```