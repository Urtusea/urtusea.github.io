---
prev: false
next: false
---

# Segment Tree - 单点修改线段树

## 使用示例

``` cpp
struct info {
  ...;
  info() : /* value init */ {}
  void update(const info& tag) { ... }            // 更新当前节点值
  info operator + (const info& r) const { ... }   // 重载区间合并运算符
};

/* 注：一定要先进行 build(...)，再进行别的操作 */
segment_tree<info, lazy> seg(N);
seg.build(int n, func call)     // 初始化线段树
seg.update(int u, info x);      // 更新 u
seg.query(int l, int r);        // 查询 [l, r]

// 线段树上二分，找到区间 [l, r] 最小符合 check(...) = 1 的下标 i，如不符合返回 -1
seg.search_pref(int l, int r, func check);
// 线段树上二分，找到区间 [l, r] 最大符合 check(...) = 1 的下标 i，如不符合返回 -1
seg.search_suff(int l, int r, func check);
```

## 代码模板

``` cpp
template <typename T> struct segment_tree {
  int size;
  std::vector<T> info;

  segment_tree(int n) : size(n + 1), info(n << 2) {}

  inline int  lson(int p)    { return p << 1; }
  inline int  rson(int p)    { return p << 1 | 1; }
  inline void push_up(int p) { info[p] = info[lson(p)] + info[rson(p)]; }

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

  int search_pref (int p, int l, int r, int L, int R, T pref, auto&& check) {
    if (R <= l || r <= L || !check(pref + info[p])) return -1;
    if (l + 1 == r) return l;
    int m = (l + r) >> 1;
    int res = search_pref(lson(p), l, m, L, R, pref, check);
    if (res == -1)
      return search_pref(rson(p), m, r, L, R, pref + info[lson(p)], check);
    else
      return res;
  }

  int search_suff(int p, int l, int r, int L, int R, T suff, auto&& check) {
    if (R <= l || r <= L || !check(info[p] + suff)) return -1;
    if (l + 1 == r) return l;
    int m = (l + r) >> 1;
    int res = search_suff(rson(p), m, r, L, R, suff, check);
    if (res == -1)
      return search_suff(lson(p), l, m, L, R, info[rson(p)] + suff, check);
    else
      return res;
  }
};
```