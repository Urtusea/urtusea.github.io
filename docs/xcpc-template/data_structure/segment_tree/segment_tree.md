---
prev: false
next: false
---

# Segment Tree - 单点修改线段树

## 代码模板

``` cpp
template <typename T> struct segment_tree {
  std::vector<T> info;

  segment_tree(int n) : info(n << 2) {}

  #define lson(p)     (p << 1)
  #define rson(p)     (p << 1 | 1)
  #define push_up(p)  (info[p] = info[lson(p)] + info[rson(p)])

  void build(int p, int l, int r, auto&& call) {
    if (l + 1 == r) return void(info[p] = call(l));
    int m = (l + r) >> 1;
    build(lson(p), l, m, call);
    build(rson(p), m, r, call);
    push_up(p);
  }

  void update(int p, int l, int r, int u, const T& x) {
    if (l + 1 == r) return info[p].update(x);
    int m = (l + r) >> 1;
    if (u < m) update(lson(p), l, m, u, x);
    else       update(rson(p), m, r, u, x);
    push_up(p);
  }

  T query(int p, int l, int r, int L, int R) {
    if (L <= l && r <= R) return info[p];
    int m = (l + r) >> 1;
    T res = T();
    if (L < m) res = res + query(lson(p), l, m, L, R);
    if (R > m) res = res + query(rson(p), m, r, L, R);
    return res;
  }

  int find_pref (int p, int l, int r, int L, int R, T pref, auto&& check) {
    if (R <= l || r <= L || !check(pref + info[p])) return -1;
    if (l + 1 == r) return l;
    int m = (l + r) >> 1;
    int res = find_pref(lson(p), l, m, L, R, pref, check);
    if (res == -1)
      return find_pref(rson(p), m, r, L, R, pref + info[lson(p)], check);
    else
      return res;
  }

  int find_suff(int p, int l, int r, int L, int R, T suff, auto&& check) {
    if (R <= l || r <= L || !check(info[p] + suff)) return -1;
    if (l + 1 == r) return l;
    int m = (l + r) >> 1;
    int res = find_suff(rson(p), m, r, L, R, suff, check);
    if (res == -1)
      return find_suff(lson(p), l, m, L, R, info[rson(p)] + suff, check);
    else
      return res;
  }
};
```