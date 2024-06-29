---
title: C. Two Movies
---

# 前言：

- Links: [C. Two Movies](https://codeforces.com/contest/1989/problem/C)
- Codeforces: {{<katex>}}1400{{</katex>}}
- Clist: {{<katex>}}1309{{</katex>}}
- Tags: 贪心，模拟
- 时间复杂度: {{<katex>}}O(1){{</katex>}}

# 题意：

给你两个长度为 {{<katex>}}n{{</katex>}} 的序列 {{<katex>}}a, b{{</katex>}}，其中只包含 {{<katex>}}0, 1, -1{{</katex>}}，你可以规划一个长度为 {{<katex>}}n{{</katex>}} 的 {{<katex>}}01{{</katex>}} 序列 {{<katex>}}s{{</katex>}}，使得：

{{<katex display>}}
X = \sum_{i = 1}^{n} [s_i = 0]·a_i
\\
Y = \sum_{i = 1}^{n} [s_i = 1]·b_i
{{</katex>}}

问你 {{<katex>}}min(X, Y){{</katex>}} 的最大值

# 思路：

考虑 {{<katex>}}(a_i, b_i){{</katex>}} 的可能性，只有 {{<katex>}}9{{</katex>}} 种

- 对于 {{<katex>}}(0, 0){{</katex>}} 则对最终结果都没有影响
- 对于 {{<katex>}}(1, 0), (1, -1), (0, 1), (-1, 1){{</katex>}} 都是将 {{<katex>}}1{{</katex>}} 加到对应 {{<katex>}}X,Y{{</katex>}} 身上即可
- 对于 {{<katex>}}(1, 1), (-1, -1){{</katex>}} 考虑去将两数差值最小化即可

# 代码：

``` cpp
#include <bits/stdc++.h>
using namespace std;

void code(/* Copyright by Urtusea */)
{
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector f(3, vector(3, 0));
    for (int i = 1; i <= n; i++) f[a[i] + 1][b[i] + 1]++;

    // 先将一定最优的操作加上
    int X = f[2][0] + f[2][1];
    int Y = f[0][2] + f[1][2];

    // 先交换，方便后续操作
    if (X > Y) swap(X, Y);
    
    // (1, 1)
    int tmp = min(f[2][2], Y - X);
    X       += tmp;
    f[2][2] -= tmp;

    X += f[2][2] / 2;
    Y += (f[2][2] + 1) / 2;

    // (-1, -1)
    tmp = min(f[0][0], Y - X);
    Y       -= tmp;
    f[0][0] -= tmp;

    X -= f[0][0] / 2;
    Y -= (f[0][0] + 1) / 2;

    cout << min(X, Y) << '\n';
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