---
prev: false
next: false
---

# KMP

## 代码模板

``` cpp
std::vector<int> kmp(const std::string& a, const std::string& b) {
  const std::string s = a + "#" + b;
  std::vector<int> p(s.size());
  for (int i = 1; i < s.size(); i++) {
    int j = p[i - 1];
    while (j && s[i] != s[j])
      j = p[j - 1];
    p[i] = j + (s[i] == s[j]);
  }
  return std::move(p);
}
```