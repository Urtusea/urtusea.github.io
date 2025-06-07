---
prev: false
next: false
---

# Sparse Table - ST表

## 代码模板

``` cpp
template <typename T, auto Comp> struct sparse_table {
  std::vector<T> info[20];

  sparse_table(int n) {
    for (int i = 0; i <= std::__lg(n); i++)
      info[i].assign(n - (1 << i) + 2, T());
  }

  void build(int n, auto&& init) {
    for (int i = 1; i <= n; i++)
      info[0][i] = init(i);
    for (int k = 1; k <= std::__lg(n); k++)
      for (int i = 1; i + (1 << k) - 1 <= n; i++)
        info[k][i] = Comp(info[k - 1][i], info[k - 1][i + (1 << (k - 1))]);
  }

  T query(int l, int r) {
    int k = std::__lg(r - l + 1);
    return Comp(info[k][l], info[k][r - (1 << k) + 1]);
  }
};

static constexpr auto Min = [](const auto& l, const auto& r) { return std::min(l, r); };
static constexpr auto Max = [](const auto& l, const auto& r) { return std::max(l, r); };
template <typename T> using min_st = sparse_table<T, Min>;
template <typename T> using max_st = sparse_table<T, Max>;
```