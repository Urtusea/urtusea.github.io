---
title: "A. Catch the Coin"
---

# 前言：

- Links: [A. Catch the Coin](https://codeforces.com/contest/1989/problem/A)
- Codeforces: 待更新
- Clist: {{<katex>}}784{{</katex>}}
- Tags: 模拟
- 时间复杂度: {{<katex>}}O(1){{</katex>}}

# 题意：

给你一个硬币的坐标 {{<katex>}}(x, y){{</katex>}}，你初始位置在 {{<katex>}}(0, 0){{</katex>}}，对于每一时刻均可以向满足 {{<katex>}}|x'-x| + |y'-y| \le 2{{</katex>}} 的点 {{<katex>}}(x', y'){{</katex>}} 移动，硬币在你移动后坐标变为 {{<katex>}}(x, y - 1){{</katex>}}，问你是否有一时刻可以接到硬币

# 思路：

观察可以发现，只有当 {{<katex>}}y \geq -1{{</katex>}} 时才满足条件

# 代码：

``` cpp
#include <bits/stdc++.h>
using namespace std;

void code(/* Copyright by Urtusea */)
{
    int x, y;
    cin >> x >> y;

    // 只需判断 y >= -1 即可
    if (y >= -1)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main(int argc, char *argv[], char *envp[])
{
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef Urtusea
    freopen("main.in",  "r", stdin );
    freopen("main.out", "w", stdout);
#endif

    for (int i = 1, n = (cin >> n, n); i <= n; i++)
    {
        code();
    }

    return 0;
}
```