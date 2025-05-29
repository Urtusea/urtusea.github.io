---
prev: false
next: false
---

# Segment Tree Lazy - 懒标记线段树

## 代码模板

``` cpp
template <typename T, typename U> struct segment_tree {
  std::vector<T> info;
  std::vector<U> lazy;

  segment_tree(int n) : info(n << 2), lazy(n << 2) {}

  #define lson(p)     (p << 1)
  #define rson(p)     (p << 1 | 1)
  #define push_up(p)  (info[p] = info[lson(p)] + info[rson(p)])

  void build(int p, int l, int r, auto&& call) {
    lazy[p].clear();
    if (l + 1 == r) return void(info[p] = call(l));
    int m = (l + r) >> 1;
    build(lson(p), l, m, call);
    build(rson(p), m, r, call);
    push_up(p);
  }

  void push_down(int p, int l, int r) {
    int m = (l + r) >> 1;
    info[lson(p)].update(lazy[p], m - l);
    lazy[lson(p)].update(lazy[p]);
    info[rson(p)].update(lazy[p], r - m);
    lazy[rson(p)].update(lazy[p]);
    lazy[p].clear();
  }

  void update(int p, int l, int r, int L, int R, const U& x) {
    if (L <= l && r <= R) return info[p].update(x, r - l), lazy[p].update(x);
    push_down(p, l, r);
    int m = (l + r) >> 1;
    if (L < m) update(lson(p), l, m, L, R, x);
    if (R > m) update(rson(p), m, r, L, R, x);
    push_up(p);
  }

  T query(int p, int l, int r, int L, int R) {
    if (L <= l && r <= R) return info[p];
    push_down(p, l, r);
    int m = (l + r) >> 1;
    T res = T();
    if (L < m) res = res + query(lson(p), l, m, L, R);
    if (R > m) res = res + query(rson(p), m, r, L, R);
    return res;
  }

  int find_pref(int p, int l, int r, int L, int R, T pref, auto&& check) {
    if (R <= l || r <= L || !check(pref + info[p])) return -1;
    if (l + 1 == r) return l;
    push_down(p, l, r);
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
    push_down(p, l, r);
    int m = (l + r) >> 1;
    int res = find_suff(rson(p), m, r, L, R, suff, check);
    if (res == -1)
      return find_suff(lson(p), l, m, L, R, info[rson(p)] + suff, check);
    else
      return res;
  }
};
```