---
prev: false
next: false
---

# Fenwick Tree - 树状数组

## 代码模板

``` cpp
template <typename T> struct fenwick_tree {
  int size;
  std::vector<T> info;

  fenwick_tree(int n) : size(n), info(n + 1) {}

  void build(int n) {
    size = n;
    std::fill(info.begin(), info.begin() + n + 1, T());
  }

  void update(int u, const T& x) {
    for (int i = u; i <= size; i += i & -i)
      info[i] += x;
  }

  T query(int u, T res = T()) {
    for (int i = u; i; i &= i - 1)
      res += info[i];
    return res;
  }
};
```