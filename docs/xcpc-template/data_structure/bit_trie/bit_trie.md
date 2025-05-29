---
prev: false
next: false
---

# Bit Trie - Bit字典树

## 代码模板

``` cpp
template <int N, int B> struct bit_trie {
  using T = std::conditional_t<(B < 32), uint, uInt>;
  
  static constexpr int M = []() {
    int res = 0;
    for (int i = 0; i <= B; i++) {
      res += std::min<Int>(1LL << i, N);
    }
    return res;
  }();

  int lst;
  int cnt[M + 1];
  int son[M + 1][2];

  inline int nxt(int& p) {
    return p ? p : p = ++lst;
  }

  void insert(T x, int u = 0) {
    for (int i = B - 1; i >= 0; i--)
      cnt[u = nxt(son[u][x >> i & 1])]++;
  }

  void erase(T x, int u = 0) {
    for (int i = B - 1; i >= 0; i--)
      cnt[u = son[u][x >> i & 1]]--;
  }

  void split(T x, int& u, int& v, int p, int d = B - 1) {
    if (!p) return void(u = v = 0);
    if (d--) {
      if (x >> d & 1) {
        u = p;
        v = ++lst;
        split(x, son[u][1], son[v][1], son[u][1], d);
      } else {
        v = p;
        u = ++lst;
        split(x, son[u][0], son[v][0], son[v][0], d);
      }
      cnt[u] = cnt[son[u][0]] + cnt[son[u][1]];
      cnt[v] = cnt[son[v][0]] + cnt[son[v][1]];
    } else {
      u = p;
      v = 0;
    }
  }

  int merge(int u, int v) {
    if (!u | !v) return u | v;
    son[u][0] = merge(son[u][0], son[v][0]);
    son[u][1] = merge(son[u][1], son[v][1]);
    cnt[u] = cnt[son[u][0]] + cnt[son[u][1]];
  }
};
```