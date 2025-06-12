---
prev: false
next: false
---

# ExKMP

## 代码模板

``` cpp
std::vector<int> exkmp(const std::string& s) {
  std::vector<int> p(s.size());
  for (int i = 1, l = 0, r = 0; i < s.size(); i++) {
    if (i <= r && p[i - l] < r - i + 1) {
      p[i] = p[i - l];
    } else {
      p[i] = std::max(0, r - i + 1);
      while (i + p[i] < s.size() && s[p[i]] == s[i + p[i]]) p[i]++;
    }
    if (i + p[i] - 1 > r) {
      l = i;
      r = i + p[i] - 1;
    }
  }
  return std::move(p);
}
```