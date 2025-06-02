---
prev: false
next: false
---

# Cartesian Tree - 笛卡尔树

## 代码模板

``` cpp
template <auto Comp> struct cartesian_tree {
  std::vector<int> l;
  std::vector<int> r;

  cartesian_tree(int n) : l(n + 1), r(n + 1) {}

  void build(int n, const auto& init) {
    std::vector<int> stk = {0};
    for (int i = 1; i <= n; i++) {
      while (stk.size() > 1 && Comp(init[i], init[stk.back()])) {
        l[i] = stk.back();
        stk.pop_back();
      }
      r[stk.back()] = i;
      stk.push_back(i);
    }
  }
};

static constexpr auto Min = [](const auto& l, const auto& r) { return l < r; };
static constexpr auto Max = [](const auto& l, const auto& r) { return l > r; };
using min_tree = cartesian_tree<Min>;
using max_tree = cartesian_tree<Max>;
```