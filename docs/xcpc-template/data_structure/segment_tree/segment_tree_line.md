---
prev: false
next: false
---

# Segment Tree Line - 李超树

## 代码模板

``` cpp
template <typename T> struct line {
  using U = T;
  T k, b;
  line(T _k = 0, T _b = 0) : k(_k), b(_b) {}
  constexpr T operator () (const int& x) const {
    return k * x + b;
  }
};

template <typename T, auto Comp> struct segment_tree {
  using U = typename T::U;
  std::vector<T> info;

  segment_tree(int n) : info(n << 2) {}

  #define lson(p) (p << 1)
  #define rson(p) (p << 1 | 1)

  void build(int p, int l, int r) {
    info[p] = T();
    if (l + 1 == r) return;
    int m = (l + r) >> 1;
    build(lson(p), l, m);
    build(rson(p), m, r);
  }

  void push_down(int p, int l, int r, T line) {
    int m = (l + r) >> 1;
    if (Comp(info[p], line, m)) std::swap(info[p], line);
    if (l + 1 == r) return;
    if (Comp(info[p], line, l - 0)) push_down(lson(p), l, m, line);
    if (Comp(info[p], line, r - 1)) push_down(rson(p), m, r, line);
  }

  void update(int p, int l, int r, int L, int R, const T& line) {
    if (L <= l && r <= R) return push_down(p, l, r, line);
    int m = (l + r) >> 1;
    if (L < m) update(lson(p), l, m, L, R, line);
    if (R > m) update(rson(p), m, r, L, R, line);
  }

  U query_min(int p, int l, int r, int x) {
    if (l + 1 == r) return info[p](x);
    int m = (l + r) >> 1;
    U res = info[p](x);
    if (x <  m) res = std::min(res, query_min(lson(p), l, m, x));
    if (x >= m) res = std::min(res, query_min(rson(p), m, r, x));
    return res;
  }

  U query_max(int p, int l, int r, int x) {
    if (l + 1 == r) return info[p](x);
    int m = (l + r) >> 1;
    U res = info[p](x);
    if (x <  m) res = std::max(res, query_max(lson(p), l, m, x));
    if (x >= m) res = std::max(res, query_max(rson(p), m, r, x));
    return res;
  }
};
```