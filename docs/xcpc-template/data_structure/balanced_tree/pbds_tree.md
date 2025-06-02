---
prev: false
next: false
---

# pbds Tree - pbds库树

## 代码模板

``` cpp
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define int  int32_t
#define Int  int64_t
#define uint uint32_t
#define uInt uint64_t

template <typename T>
using pbds_tree = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
```