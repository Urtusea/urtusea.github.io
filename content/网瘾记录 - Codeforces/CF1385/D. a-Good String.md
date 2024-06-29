---
title: "D. a-Good String"
---

# 前言：

- Links: [D. a-Good String](https://codeforces.com/contest/1385/problem/D)
- Codeforces: {{<katex>}}1500{{</katex>}}
- Clist: {{<katex>}}1527{{</katex>}}
- Tags: 分治，模拟
- 时间复杂度: {{<katex>}}nlogn{{</katex>}}

# 题意：

给你一个长度为 {{<katex>}}n{{</katex>}} 的字符串 {{<katex>}}s{{</katex>}}，定义 {{<katex>}}char(s){{</katex>}} 为 {{<katex>}}s{{</katex>}} 的字符集合大小，并给你一个 {{<katex>}}good(s, c){{</katex>}} 串定义：

{{<katex display>}}
good(s, c) =
    \begin{cases}
    if (|s| = 1 \ and \ s_1 = c)
    \\
    if (char(s_1s_2...s_{n/2}) = 1 \ and \ s_1 = c \ and \ good(s_{n/2+1}...s_n, c + 1))
    \\
    if (char(s_{n/2+1}...s_n) = 1 \ and \ s_n = c \ and \ good(s_1s_2...s_{n/2}, c + 1))
    \end{cases}
{{</katex>}}

# 思路：



# 代码：

``` cpp

```