---
prev: false
next: false
---

# 前言

## 注意事项

本人的所有模板均在 `-std=c++20` 的编译环境下进行编写，如果出现 `Compiler Error` 请检查编译环境

## 编译选项

``` bash
g++ -O0 -g0 main.out main.cpp -std=c++20
```

## 初始代码

### 单测

``` cpp
#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  

  return 0;
}
```

### 多测

``` cpp
#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

void code() {
  
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 1, n = (std::cin >> n, n); i <= n; i++)
    code();

  return 0;
}
```

## 压测代码

``` cpp
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

/*
  Atcoder(C++23 Clang): 680ms
  Atcoder(C++23 GCC): 478ms
  Codeforces(G++20): 2203ms
  Codeforces(G++23): 2374ms
  Nowcoder(Clang): 1490ms
  Nowcoder(GCC): 1804ms
*/

std::mt19937 rnd(time(0));

constexpr int N = 100000;
constexpr int M = 5;
std::bitset<N + 1> cnt;
std::bitset<N + 1> pos[26];

std::vector<int> init_S() {
  std::vector<int> res(N + 1);
  for (int i = 1; i <= N; i++)
    res[i] = rnd() % 26;
  return std::move(res);
}

std::vector<int> init_T() {
  std::vector<int> res(M + 1);
  for (int i = 1; i <= M; i++)
    res[i] = rnd() % 26;
  return std::move(res);
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  auto S = init_S();
  for (int i = 1; i <= N; i++)
    pos[S[i]][i] = 1;

  for (int i = 1; i <= N; i++) {
    int l = rnd() % N + 1;
    int r = rnd() % N + 1;
    auto T = init_T();
    if (l > r) std::swap(l, r);

    if (M > r - l + 1) {
      std::cout << 0 << '\n';
      continue;
    }
    
    cnt.set();
    for (int i = 1; i <= M; i++)
      cnt &= pos[T[i]] >> (i - 1);

    std::cout << (cnt >> (l - 1)).count() - (cnt >> (r - M + 1)).count() << '\n';
  }

  return 0;
}
```

## 随机模数

``` cpp
904289383
905575579
928175011
956297539
963958031
982697713
984639529
989641421
994702567
996987743
```