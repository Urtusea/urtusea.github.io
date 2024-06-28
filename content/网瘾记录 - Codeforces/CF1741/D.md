---
title: "D"
---

# 前言：

- Links: [D. Masha and a Beautiful Tree](https://codeforces.com/contest/1741/problem/D)
- Codeforces: {{<katex>}}1300{{</katex>}}
- Clist: {{<katex>}}1286{{</katex>}}
- Tags: 分治，DFS
- 时间复杂度: {{<katex>}}O(n \space log \space n){{</katex>}}

# 题意：

有一颗深度为 {{<katex>}}n{{</katex>}} 的满二叉树，现给你其 {{<katex>}}2^n{{</katex>}} 个叶子节点，叶子节点的权值构成一个长度为 {{<katex>}}2^n{{</katex>}} 的排列 {{<katex>}}p{{</katex>}}，从左到右依次为 {{<katex>}}p_1, p_2, p_3, ..., p_{2^n}{{</katex>}}

对于每一次操作你只能操作非叶子节点，并交换该节点的两颗子树，问你是否有可能将叶子节点的排列 $p$ 变为单调递增的排列

即满足 {{<katex>}}\forall 1 \le i \le 2^n - 1, p[i] < p[i + 1]{{</katex>}}

# 思路：

不妨首先来看小部分操作是如何满足条件的：

- 当 {{<katex>}}n = 1{{</katex>}} 时，设 {{<katex>}}p = [2, 1]{{</katex>}}，显然交换 {{<katex>}}p_1{{</katex>}} 与 {{<katex>}}p_2{{</katex>}} 即可，交换后 {{<katex>}}p' = [1, 2]{{</katex>}} 满足条件
- 当 {{<katex>}}n = 2{{</katex>}} 时，设 {{<katex>}}p = [3, 4, 2, 1]{{</katex>}}，将其分割为 {{<katex>}}p = [3, 4, | 2, 1]{{</katex>}}，对于右边我们则转换为了 {{<katex>}}n = 1{{</katex>}} 时的小问题，直接交换即可，问题变成了 {{<katex>}}p = [3, 4, | 1, 2]{{</katex>}}，我们也只能交换这一个相邻的区间，则 {{<katex>}}p' = [1, 2, | 3, 4]{{</katex>}} 满足条件

容易发现的，只需要从小的叶子区间维护到大的叶子区间即可

# 代码：

``` cpp
#include <bits/stdc++.h>
using namespace std;

void code( /* Copyright by Urtusea */ )
{
    int n, ans = 0;
    cin >> n;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];

    function<int(int, int)> dfs = [&](int u, int len)
    {
        // 如果当前区间长度为 1 则直接返回 p[u] 即可
        if (len == 1) return p[u];

        // 记录左右子树最大值
        int lMax = dfs(u,           len / 2);
        int rMax = dfs(u + len / 2, len / 2);

        // 如果左子树最大值大于右子树最大值，则两颗子树需要进行一次交换
        if (rMax < lMax && ++ans) for (int i = u; i < u + len / 2; i++)
                swap(p[i], p[i + len / 2]);

        // 返回两颗子树的最大值
        return max(lMax, rMax);
    };
    dfs(1, n);

    // 判断交换完毕后答案是否符合条件
    for (int i = 1; i < n; i++) if (p[i] > p[i + 1]) 
    {
        return void(cout << -1 << '\n');
    }

    cout << ans << '\n';
}

int main()
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