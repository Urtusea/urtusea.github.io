# Mod Int

## 介绍

快速幂是一种可以在 $O(logb)$ 的时间内计算出 $a^b$ 的算法

## 代码

``` cpp
template <typename T>
constexpr auto quick_power(T a, uInt b, T res = T(1)) -> T {
    for (; b; a *= a, b >>= 1) if (b & 1) res *= a; return res;
}
```