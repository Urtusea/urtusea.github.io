---
prev: false
next: false
---

# Tarjan VBCC - 点双连通分量

## 代码模板

``` cpp
std::vector<std::vector<int>> tarjan_vbcc(int n, const auto& G) {
  std::vector<int> dfn(n + 1);
  std::vector<int> low(n + 1);
  std::vector<std::vector<int>> vbcc;
  
  int timer = 0;
  const auto tarjan = [&](auto&& self, int u) -> void {
    static std::vector<int> stk;
    dfn[u] = low[u] = ++timer;
    
    if (G[u].empty())
      return vbcc.push_back({u});
    else
      stk.push_back(u);
    
    for (auto to : G[u]) {
      if (!dfn[to.v]) {
        self(self, to.v);
        low[u] = std::min(low[u], low[to.v]);
        if (low[to.v] >= dfn[u]) {
          vbcc.push_back({});
          while (!stk.empty()) {
            auto p = stk.back();
            stk.pop_back();
            vbcc.back().push_back(p);
            if (p == to.v) break;
          }
          vbcc.back().push_back(u);
        }
      } else {
        low[u] = std::min(low[u], dfn[to.v]);
      }
    }
  };
  
  for (int u = 1; u <= n; u++)
    if (!dfn[u]) tarjan(tarjan, u);
  
  return std::move(vbcc);
}
```