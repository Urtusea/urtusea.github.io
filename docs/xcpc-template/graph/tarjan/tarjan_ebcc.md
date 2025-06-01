---
prev: false
next: false
---

# Tarjan EBCC - 边双连通分量

## 代码模板

``` cpp
std::vector<int> tarjan_ebcc(int n, const auto& G) {
  std::vector<int> dfn(n + 1);
  std::vector<int> low(n + 1);
  std::vector<int> ebcc(n + 1);

  int timer = 0, ebcc_cnt = 0;
  const auto tarjan = [&](auto&& self, int u, int pid) -> void {
    static std::vector<int> stk;
    dfn[u] = low[u] = ++timer;
    stk.push_back(u);

    for (auto to : G[u]) {
      if (to.id == (pid ^ 1)) continue;

      if (!dfn[to.v]) {
        self(self, to.v, to.id);
        low[u] = std::min(low[u], low[to.v]);
      } else if (!ebcc[to.v]) {
        low[u] = std::min(low[u], dfn[to.v]);
      }
    }

    if (dfn[u] == low[u] && ++ebcc_cnt) {
      while (!stk.empty()) {
        auto v = stk.back();
        stk.pop_back();
        ebcc[v] = ebcc_cnt;
        if (v == u) break;
      }
    }
  };

  for (int u = 1; u <= n; u++)
    if (!dfn[u]) tarjan(tarjan, u, 0);
  
  return ebcc;
}
```