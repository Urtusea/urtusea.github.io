---
prev: false
next: false
aside: false
---

# 注意事项

本人的所有模板均在 `-std=c++20` 的编译环境下进行编写，如果出现因为编译环境问题导致的 `Compiler Error` 本人概不负责！

# 编译选项

``` bash
g++ -O0 -g0 main.out main.cpp -std=c++20
```

# 初始代码

## 单测

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

## 多测

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