---
prev: false
next: false
---

# Sparse Table 2D - 二维ST表

## 代码模板

``` cpp
template <typename T, auto Comp> struct sparse_table {
  int size_n;
  int size_m;
  std::vector<T> info[20][20];

  sparse_table(int n, int m) {
    for (int x = 0; x <= std::__lg(n); x++)
      for (int y = 0; y <= std::__lg(m); y++)
        info[x][y].assign((n - (1 << x) + 1) * m + 1, T());
  }

  inline int pos(int i, int j) { return (i - 1) * size_m + j; }

  void build(int n, int m, auto&& init) {
    size_n = n;
    size_m = m;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        info[0][0][pos(i, j)] = init(i, j);
    for (int x = 0; x <= std::__lg(n); x++) {
      for (int y = 0; y <= std::__lg(m); y++) {
        if (x == 0 && y == 0) [[unlikely]] continue;
        for (int i = 1; i + (1 << x) - 1 <= n; i++) {
          for (int j = 1; j + (1 << y) - 1 <= m; j++) {
            if (y == 0)
              info[x][y][pos(i, j)] = Comp(info[x - 1][y][pos(i, j)], info[x - 1][y][pos(i + (1 << (x - 1)), j)]);
            else
              info[x][y][pos(i, j)] = Comp(info[x][y - 1][pos(i, j)], info[x][y - 1][pos(i, j + (1 << (y - 1)))]);;
          }
        }
      }
    }
  }

  T query(int l1, int r1, int l2, int r2) {
    const int k1 = std::__lg(l2 - l1 + 1);
    const int k2 = std::__lg(r2 - r1 + 1);
    return Comp(
      Comp(info[k1][k2][pos(l1, r1)], info[k1][k2][pos(l2 - (1 << k1) + 1, r2 - (1 << k2) + 1)]),
      Comp(info[k1][k2][pos(l1, r2 - (1 << k2) + 1)], info[k1][k2][pos(l2 - (1 << k1) + 1, r1)])
    );
  }
};

static constexpr auto Min = [](const auto& l, const auto& r) { return std::min(l, r); };
static constexpr auto Max = [](const auto& l, const auto& r) { return std::max(l, r); };
template <typename T> using min_st = sparse_table<T, Min>;
template <typename T> using max_st = sparse_table<T, Max>;
```