# 前言

由于本人已经加入 rust 神教，所以可能包含较严重的 rust-style

## 初始代码

``` cpp
#include <bits/stdc++.h>

using Int  = int64_t;
using uInt = uint64_t;

auto code() -> void {
    
}

auto main(int argc, char *argv[], char *envp[]) -> int {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    for (int i = 1, n = (std::cin >> n, n); i <= n; ++i)
        code();

    return 0;
}
```