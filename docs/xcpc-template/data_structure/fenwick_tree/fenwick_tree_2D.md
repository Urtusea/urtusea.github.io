---
prev: false
next: false
---

# Fenwick Tree 2D - 二维树状数组

## 代码模板
``` cpp
template <typename T> struct fenwick_tree {
  int size_n;
  int size_m;
  std::vector<T> info;

  fenwick_tree(int n, int m) : size_n(n), size_m(m), info(n * m + 1) {}

  inline int pos(int i, int j) { return (i - 1) * size_m + j; }

  void build(int n, int m) {
    size_n = n;
    size_m = m;
    std::fill(info.begin(), info.begin() + n * m + 1, T());
  }

  void update(int x, int y, const T& t) {
    for (int i = x; i <= size_n; i += i & -i)
      for (int j = y; j <= size_m; j += j & -j)
        info[pos(i, j)] += t;
  }

  T query(int x, int y, T res = T()) {
    for (int i = x; i; i &= i - 1)
      for (int j = y; j; j &= j - 1)
        res += info[pos(i, j)];
    return res;
  }
};
```