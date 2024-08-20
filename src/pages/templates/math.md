---
title: 'Math'
layout: '../../layouts/Templates.astro'
---

# 数学相关

## Quick Power - 快速幂

顾名思义，能够在 log(b) 的时间内快速的求出 a^b 的值的算法

<p></p>

``` cpp
// 模板
template <typename T>
constexpr T quick_power(T a, uint64_t b, T res = T(1)) {
    assert(b >= 0);
    for (; b; a *= a, b >>= 1)
        if (b & 1)
            res *= a;
    return res;
}

// 使用方法
struct T {
    type val;
    T &operator *= (T other) & {
        do somthing;
    }
};
quick_power(T(a), b); // a ^ b
```

<p></p>

## Slow Timer - 龟速乘

对于一些乘法会爆精度的情况下，龟速乘是比较实用的方法，但顾名思义“龟速”，但对于一些高精度乘法，还是有奇效

<p></p>

``` cpp
// 模板
template <typename T>
constexpr T slow_timer(T a, uint64_t b, T res = T(0)) {
    assert(b >= 0);
    for (; b; a += a, b >>= 1)
        if (b & 1)
            res += a;
    return res;
}

// 使用方法
struct T {
    type val;
    T &operator += (T other) & {
        do somthing;
    }
};
slow_timer(T(a), b); // a * b
```

<p></p>

## Prime Sieve - 素数筛

对于需要筛出一定范围内质数的需求时，素数筛就派上了用场，这里只给出欧拉筛

<p></p>

``` cpp
// 模板
template <int N>
struct prime_sieve : public std::vector<int> {
    constexpr prime_sieve() :
        std::vector<int>() {
        assert(N >= 0);
        std::bitset<N + 1> is_prime;
        for (int i = 2; i <= N; i += 1) {
            if (!is_prime[i])
                (*this).emplace_back(i);
            for (auto &p : (*this)) {
                if (i * p > N) break;
                is_prime[i * p] = 1;
                if (i % p == 0) break;
            }
        }
    }
};
```

<p></p>

## Euler Phi - 欧拉函数

欧拉函数的定义是：对于 n，[1, n] 范围内与 n 互质的个数，这对解决积性函数非常重要

√n 求欧拉函数：

<p></p>

``` cpp
template <typename T>
constexpr T euler_phi(T x) {
    T res = x;
    for (int i = 2; i * i <= x; i += 1) {
        if (x % i != 0) continue;
        res = res / i * (i - 1);
        while (x % i == 0)
            x /= i;
    }
    if (x > 1)
        res = res / x * (x - 1);
    return res;
}
```

<p></p>