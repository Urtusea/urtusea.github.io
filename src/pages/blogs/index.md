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

## 对齐格式

对于声明变量，类型与类型名开头对齐，变量名与变量名开头对齐

<p></p>

``` cpp
// 声明变量
type        variable_name;
long_type   variable_name;
short_type  variable_name;
```

<p></p>

对于 `if / else if / else`，语句与语句互相对齐，仅允许 `if () break;`，`if () continue;` 存在

<p></p>

``` cpp
if (expression) {

}
else if (expression) {

}
else {

}

if (expression)
    variable += 1;
else if (expression)
    variable += 1;
else {

}

if (expression) continue;
if (expression) break;
```

<p></p>

对于传递的参数，一行以内最多容纳四个参数，对于同一列的参数，开头均需对齐

<p></p>

``` cpp
type function(p_1, p_2, p_3, p_4
              p_5, p_6, p_7, p_8,
              p_9);
```

<p></p>

## 命名格式

对于变量以及函数的命名，均采用 动词_形容词_名称 的格式进行命名，如有重复的，则最多允许存在一对重复的名字，并以 `_` 来进行区分

<p></p>

``` cpp
// 函数格式
type check_min_val() {}
type query_min() {}
type query_max() {}

// 变量格式
type a;
type b;
type pref_a;
type suff_a;

// 重复格式
type a;
type _a;
```

<p></p>

对于模板的参数类型，均以大写字母开头，如非必要，尽量采用一个大写字母概括

<p></p>

``` cpp
template <typename T>
T function() {}

template <typename T, typename Func>
T function(Func func) {}
```

<p></p>

## 特殊符号格式

`:: / . / ->` 必须与左右两侧紧贴

<p></p>

``` cpp
std::cin.tie(nullptr)->sync_with_stdio(false);
```

<p></p>

`:` 必须与左右两侧间距一个空格

<p></p>

``` cpp
for (auto x : a)
    std::cout << x << '\n';
```

<p></p>

`& / && / *` 必须与右侧紧贴

<p></p>

``` cpp
auto function(auto &val1, auto &&val2, auto *val3) {}
```

<p></p>

## 代码块格式

对于变量声明以及变量初始化，需紧贴其后或者另起一行初始化

<p></p>

``` cpp
// 声明变量
type variable = init_val;

type variable;
variable = init_val;
```

<p></p>

对于声明变量，一行以内最多容纳四个变量

<p></p>

``` cpp
type variable1, variable2, variable3, variable4;
type variable5;
```

<p></p>

## 注：当然，也有可能瞎写（bushi），只是起到一个给自己规范的作用