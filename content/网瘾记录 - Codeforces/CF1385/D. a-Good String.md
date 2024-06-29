---
title: "D. a-Good String"
---

# 前言：

- Links: [D. a-Good String](https://codeforces.com/contest/1385/problem/D)
- Codeforces: {{<katex>}}1500{{</katex>}}
- Clist: {{<katex>}}1527{{</katex>}}
- Tags: 分治，模拟，DFS
- 时间复杂度: {{<katex>}}nlogn{{</katex>}}

# 题意：

给你一个长度为 {{<katex>}}n{{</katex>}} 的字符串 {{<katex>}}s{{</katex>}}，定义 {{<katex>}}char(s){{</katex>}} 为 {{<katex>}}s{{</katex>}} 的字符集合大小，并给你一个 {{<katex>}}good(s, c){{</katex>}} 串定义：

{{<katex display>}}
good(s, c) =
    \begin{cases}
    if \ \ |s| = 1 \ and \ s_1 = c
    \\
    if \ \ char(s_1s_2...s_{n/2}) = 1 \ and \ s_1 = c \ and \ good(s_{n/2+1}...s_n, c + 1)
    \\
    if \ \ char(s_{n/2+1}...s_n) = 1 \ and \ s_n = c \ and \ good(s_1s_2...s_{n/2}, c + 1)
    \end{cases}
{{</katex>}}

现在你可以进行任意次操作，将 {{<katex>}}s{{</katex>}} 中的一个字符修改成另一个字符，请问将 {{<katex>}}s{{</katex>}} 修改成 {{<katex>}}good(s, a){{</katex>}} 串的最小操作数

# 思路：

模拟操作，不难得出将一个 {{<katex>}}s{{</katex>}} 修改成 {{<katex>}}good(s, c){{</katex>}} 的操作数 {{<katex>}}f(s,c){{</katex>}} 为：

{{<katex display>}}
f(s,c) = min(\sum_{i = 1}^{l} + f(r,c+1), \ \sum_{i = 1}^{r} + f(l,c+1))
{{</katex>}}

只需模拟操作即可

# 代码：

``` cpp
#include <bits/stdc++.h>
using namespace std;

void code(/* Copyright by Urtusea */)
{
    int n;
    string s;
    cin >> n >> s;

    // 个人习惯
    s = '#' + s;

    function<int(int, int, char)> dfs = [&](int u, int len, char c)->int
    {
        if (len == 1) return s[u] != c;

        // 递归左右区间
        int l = dfs(u,           len / 2, c + 1);
        int r = dfs(u + len / 2, len / 2, c + 1);

        // 统计剩余部分是否全为 c
        int cntL = len / 2 - count(s.begin() + u, s.begin() + u + len / 2, c);
        int cntR = len / 2 - count(s.begin() + u + len / 2, s.begin() + u + len, c);

        return min(l + cntR, r + cntL);
    };

    cout << dfs(1, n, 'a') << '\n';
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