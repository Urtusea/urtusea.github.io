---
prev: false
next: false
---

# Chtholly Tree - 珂朵莉树

## 代码模板

``` cpp
template <typename T> struct chtholly_tree {
  using iterator = typename std::map<int, T>::iterator;
  std::map<int, T> odt;
  
  void init(int l, int r, const T& _init) {
    odt.clear();
    odt[l] = _init;
    odt[r + 1] = _init;
  }

  iterator split(int p) {
    auto it = std::prev(odt.upper_bound(p));
    if (it->first == p) return it;
    return odt.insert(it, {p, it->second});
  }

  void assign(int l, int r, const T& x) {
    if (l > r) return;
    auto it1 = split(l);
    auto it2 = split(r + 1);
    odt.erase(it1, it2);
    odt[l] = x;
  }

  void perform(int l, int r, auto&& call) {
    if (l > r) return;
    auto L = split(l);
    auto R = split(r + 1);
    while (L != R) {
      auto M = std::next(L);
      call(L, M);
      L = M;
    }
  }
};
```