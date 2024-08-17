---
title: 'Index Page'
layout: '../../layouts/Blogs.astro'
---

# Urtusea Code Style

## 概览

这是本人关于代码格式规范，对于自己所攥写的代码所作的一系列要求

## 缩进格式

对于缩进格式，均需采用 4 字符长度的 Tab Size/Space 进行缩进

<p></p>

``` cpp
// 缩进格式如下
for (...)
    for (...)
        for (...)
```

<p></p>

## 括号格式

对于大括号 `{}` 格式，采用以下两类：

- 作为函数代码块：正常书写
- 作为其余代码块：如代码有一行，则省去大括号，如果有多行，则不省去

<p></p>

``` cpp
// 作为函数代码块
type function(type variable) {
    // do somthing...
}

// 作为其余代码块
if (expression)
    variable += 1;

if (expression) {
    variable += 1;
    variable -= 1;
}
```

<p></p>

对于中括号 `[]` 格式，采用以下两类：

- 无嵌套：正常书写
- 有嵌套：在括号内左右两侧各添加一个空格

<p></p>

``` cpp
// 无语句嵌套
a[0] = 1;

// 有语句嵌套
a[ a[0] ] = 1;
a[ min(a[0], a[1]) ] = 1;
```

<p></p>

对于小括号 `()` 格式，一行以内最多容纳四个元素，对于同一列的元素，开头均需对齐

<p></p>

``` cpp
min(a[1], a[2], a[3], a[4]);

min(a[1], a[2], a[3], a[4]
    a[5], a[6], a[7]);

min(abc[1], a[2], a[3], a[4]
    a[5],   a[6]);
```

<p></p>

对于尖括号 `<>` 格式，除去 `template <>` 特定，其余均跟在前面类型后面

<p></p>

``` cpp
// template <>
template <typename T>
template <
    char A,
    int  N,
>

// 其余情况
std::vector<T> a;
std::array<T, 10> b;
```

<p></p>

