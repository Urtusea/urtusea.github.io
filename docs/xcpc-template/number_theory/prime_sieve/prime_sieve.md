---
prev: false
next: false
---

# Prime Sieve - 素数筛

## 代码模板

``` cpp
const auto prime = []() -> std::vector<int> {
  static constexpr int N = 1000000;
  static constexpr int M = 1000;
  std::vector<int> res = {2};
  std::bitset<N + 1> is_prime;
  for (int i = 2; i <= M; i++) {
    if (is_prime[i]) continue;
    for (int j = i << 1; j <= N; j += i)
      is_prime[j] = 1;
  }
  for (int i = 3; i <= N; i += 2)
    if (!is_prime[i]) res.push_back(i);
  return res;
}();
```