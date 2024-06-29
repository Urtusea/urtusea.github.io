---
title: "B. Substring and Subsequence"
---

# 前言：

- Links: [B. Substring and Subsequence](https://codeforces.com/contest/1989/problem/B)
- Codeforces: {{<katex>}}1200{{</katex>}}
- Clist: {{<katex>}}1142{{</katex>}}
- Tags: 最长递增子序列，双指针
- 时间复杂度: {{<katex>}}O(|a|·|b|){{</katex>}}

# 题意：

对于一个字符串 {{<katex>}}s{{</katex>}}，给你其一子串 {{<katex>}}a{{</katex>}} 和一子序列 {{<katex>}}b{{</katex>}}，询问你满足条件的 {{<katex>}}|s|{{</katex>}} 的最小值

# 思路：

考虑 DP，令 {{<katex>}}f(i){{</katex>}} 为 以 {{<katex>}}b_i{{</katex>}} 开头，与 {{<katex>}}a{{</katex>}} 匹配的最长公共子序列，不难得到答案为：{{<katex>}}|s| = a + b - min(f(i)){{</katex>}}

# 代码：

``` cpp
#include <bits/stdc++.h>
using namespace std;

void code(/* Copyright by Urtusea */)
{
    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();
    
    // 将字符串变为 "#a"，使得其下标从 1 开始，个人习惯罢了
    a = '#' + a;
    b = '#' + b;

    vector f(m + 1, 0LL);
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
    {
        if (f[i] + i > m) break;
        if (a[j] == b[f[i] + i]) f[i]++;
    }

    cout << n + m - *max_element(f.begin(), f.end()) << '\n';
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