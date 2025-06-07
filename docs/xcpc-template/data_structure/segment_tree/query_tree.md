---
prev: false
next: false
---

# Query Tree - 询问树

## 代码模板

``` cpp
template <typename T> struct query_tree {
  std::vector<std::vector<T>> info;

  query_tree(int n) : info(n << 2) {}

  #define lson(p) (p << 1)
  #define rson(p) (p << 1 | 1)

  void build(int p, int l, int r) {
    info[p].clear();
    if (l + 1 == r) return;
    int m = (l + r) >> 1;
    build(lson(p), l, m);
    build(rson(p), m, r);
  }

  void add_query(int p, int l, int r, int L, int R, const T& q) {
    if (L <= l && r <= R) return info[p].push_back(q);
    int m = (l + r) >> 1;
    if (L < m) add_query(lson(p), l, m, L, R, q);
    if (R > m) add_query(rson(p), m, r, L, R, q);
  }

  void query(int p, int l, int r, auto&& add, auto&& del, auto&& call) {
    add(info[p]);
    if (l + 1 == r) {
      call(l);
    } else {
      int m = (l + r) >> 1;
      query(lson(p), l, m, add, del, call);
      query(rson(p), m, r, add, del, call);
    }
    del(info[p]);
  }
};
```