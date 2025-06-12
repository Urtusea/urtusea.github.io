---
prev: false
next: false
---

# String Hash - 字符串哈希

## 代码模板

``` cpp
template <typename T, auto B> struct string_hash {
  static std::vector<T> base;
  std::vector<T> hash;

  string_hash(const std::string& s, int offset = 0) : hash(s.size() - offset + 1) {
    const std::string_view t(s.begin() + offset, s.end());
    for (int i = 0; i < t.size(); i++)
      hash[i + 1] = hash[i] * B + s[i];
  }

  T query(int l, int r) {
    return hash[r] - hash[l - 1] * base[r - l + 1];
  }
};
```