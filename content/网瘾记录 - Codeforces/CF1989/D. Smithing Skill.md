---
title: D. Smithing Skill
---

# 前言：

- Links: [D. Smithing Skill](https://codeforces.com/contest/1989/problem/D)
- Codeforces: {{<katex>}}1900{{</katex>}}
- Clist: {{<katex>}}1914{{</katex>}}
- Tags: DP，贪心
- 时间复杂度: {{<katex>}}O(N){{</katex>}}

# 题意：

给你两个大小为 {{<katex>}}n{{</katex>}} 的序列 {{<katex>}}a, b{{</katex>}}，和一个大小为 {{<katex>}}m{{</katex>}} 的序列 {{<katex>}}c{{</katex>}}，对于每一个 {{<katex>}}c_i{{</katex>}} 你都可以花费 {{<katex>}}a_j{{</katex>}} 并获得 {{<katex>}}b_j{{</katex>}} 的返还，最终获得 {{<katex>}}2{{</katex>}} 点贡献，可以进行多次这样的操作，直到无法进行为止，问你最大能获得的贡献为多少

# 思路：

对于每个相同的 {{<katex>}}a_i, a_j{{</katex>}} 只需要考虑对应的 {{<katex>}}max(b_i, b_j){{</katex>}} 即可，很简单的贪心，然后会发现，小范围以内的数我们可以直接通过 DP 将答案递推出来，而超过这个范围的我们也只需要贪心的降到小范围里面加上其值即可

# 代码：

``` cpp
#include <bits/stdc++.h>
using namespace std;

void code(/* Copyright by Urtusea */)
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1), b(n + 1), c(m + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= m; i++) cin >> c[i];

    const int N = 1000000, INF = 1000000000;
    
    // 预处理
    vector<int> p(N + 1, INF), f(N + 1), g(N + 1);
    for (int i = 1; i <= n; i++) p[a[i]] = min(p[a[i]], a[i] - b[i]);
    iota(f.begin(), f.end(), 0);

    // DP 预处理 [1, 1e6] 的答案
    for (int i = 1; i <= N; i++)
    {
        if (p[f[i - 1]] <= p[f[i]]) f[i] = f[i - 1];
        if (p[f[i]] == INF) continue;

        int tmp = (i - f[i]) / p[f[i]] + 1;

        g[i] = tmp + g[i - tmp * p[f[i]]];
    }

    // 贪心求解
    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int mId = min(c[i], N);

        if (p[f[mId]] == INF) continue;

        int tmp = (c[i] - f[mId]) / p[f[mId]] + 1;

        ans += tmp + g[c[i] - tmp * p[f[mId]]];
    }

    cout << ans * 2 << '\n';
}

int main(int argc, char *argv[], char *envp[])
{
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef Urtusea
    freopen("main.in",  "r", stdin );
    freopen("main.out", "w", stdout);
#endif

    // for (int i = 1, n = (cin >> n, n); i <= n; i++)
    {
        code();
    }

    return 0;
}
```