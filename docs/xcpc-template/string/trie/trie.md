---
prev: false
next: false
---

# Trie - 字典树

## 代码模板

``` cpp
struct trie {
  int idx;
  std::vector<int> cnt;
  std::vector<std::array<int, 26>> son;

  trie(int n) : idx(0), cnt(n + 1), son(n + 1) {}

  inline int nxt(int& p) {
    return p ? p : p = ++idx;
  }

  void insert(std::string_view s, int u = 0) {
    for (auto c : s) cnt[u = nxt(son[u][c - 'a'])]++;
  }

  void erase(std::string_view s, int u = 0) {
    for (auto c : s) cnt[u = son[u][c - 'a']]--;
  }

  int merge(int u, int v) {
    if (!u || !v) return u | v;
    for (int i = 0; i < 26; i++) son[u][i] = merge(son[u][i], son[v][i]);
    cnt[u] = 0;
    for (int i = 0; i < 26; i++) cnt[u] += cnt[son[u][i]];
  }
};
```