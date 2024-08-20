---
title: 'Data Structure'
layout: '../../layouts/Templates.astro'
---

# 数据结构

## Vertical Heap - 对顶堆

简易的维护 第 k 大/小 的数据结构，对于更新 k 的位置复杂度较高，所以只适用于 k 固定，或者均摊复杂度较低的情况

<p></p>

``` cpp
// 第 k 小对顶堆模板
template <typename T>
struct min_vertical_heap {
    using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
    using max_heap = std::priority_queue<T, std::vector<T>, std::less<T>>;

    int vertical_place;
    max_heap left_heap;
    min_heap right_heap;

    constexpr min_vertical_heap(int k = 0) :
        vertical_place(k) {
        assert(k >= 0);
    }
    
    constexpr void push(T x) & {
        if (!vertical_place) {
            right_heap.emplace(x);
            return;
        }

        if (left_heap.size() < vertical_place)
            left_heap.emplace(x);
        else if (x >= left_heap.top())
            right_heap.emplace(x);
        else {
            T tmp = left_heap.top();
            left_heap.pop();
            left_heap.emplace(x);
            right_heap.emplace(tmp);
        }
    }

    constexpr T top() const {
        if (!left_heap.empty())
            return left_heap.top();
        else if (!right_heap.empty())
            return right_heap.top();
        else
            return T();
    }

    constexpr int size() const {
        return left_heap.size() + right_heap.size();
    }

    constexpr void update_add() & {
        if (!right_heap.empty()) {
            left_heap.emplace(right_heap.top());
            right_heap.pop();
        }
        vertical_place += 1;
    }

    constexpr void update_sub() & {
        assert(vertical_place >= 1);
        if (!left_heap.empty()) {
            right_heap.emplace(left_heap.top());
            left_heap.pop();
        }
        vertical_place -= 1;
    }
};

// 第 k 大最顶堆模板
template <typename T>
struct max_vertical_heap {
    using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
    using max_heap = std::priority_queue<T, std::vector<T>, std::less<T>>;

    int vertical_place;
    min_heap left_heap;
    max_heap right_heap;

    constexpr max_vertical_heap(int k = 0) :
        vertical_place(k) {
        assert(k >= 0);
    }
    
    constexpr void push(T x) & {
        if (!vertical_place) {
            right_heap.emplace(x);
            return;
        }

        if (left_heap.size() < vertical_place)
            left_heap.emplace(x);
        else if (x <= left_heap.top())
            right_heap.emplace(x);
        else {
            T tmp = left_heap.top();
            left_heap.pop();
            left_heap.emplace(x);
            right_heap.emplace(tmp);
        }
    }

    constexpr T top() const {
        if (!left_heap.empty())
            return left_heap.top();
        else if (!right_heap.empty())
            return right_heap.top();
        else
            return T();
    }

    constexpr int size() const {
        return left_heap.size() + right_heap.size();
    }

    constexpr void update_add() & {
        if (!right_heap.empty()) {
            left_heap.emplace(right_heap.top());
            right_heap.pop();
        }
        vertical_place += 1;
    }

    constexpr void update_sub() & {
        assert(vertical_place >= 1);
        if (!left_heap.empty()) {
            right_heap.emplace(left_heap.top());
            left_heap.pop();
        }
        vertical_place -= 1;
    }
};

// 使用方法
vertical_heap heap;

// 将 x 放入堆中
heap.push(x);

// 将堆中最大/最小 pop 删除
heap.pop();

// 查询第 k 大/小
heap.top();

// 更新 k 位置
heap.update_add();
heap.update_sub();
```

<p></p>

## Disjoint Set Union - 并查集

并查集小而精巧，利用路径压缩和启发式合并可以做到 `O(α(n))` 的平均操作复杂度，通常用来维护一个集合之间的联通关系，或者使用带权并查集，维护点与点之间的关系

<p></p>

``` cpp
// 模板
template <int N = 1>
struct disjoint_set_union : public std::vector<std::array<int, 2>> {
    constexpr disjoint_set_union(int n = 0) :
        std::vector<std::array<int, 2>>(n * N + 1, {0, 1}) {
        for (int i = 1; i <= n * N; i += 1) {
            (*this)[i][0] = (i - 1) % n + 1;
        }
    }

    constexpr int find(int x) & {
        assert(1 <= x && x < (*this).size());
        return x == (*this)[0] ? x : (*this)[0] = find((*this)[0]);
    }

    constexpr void merge(int x, int y) & {
        assert(1 <= std::min(x, y) && std::max(x, y) < (*this).size())
        x = find(x), y = find(y);
        if (x == y)
            return;
        else if ((*this)[x][1] < (*this)[y][1])
            (*this)[y][1] += (*this)[x][1], (*this)[x][0] = y;
        else
            (*this)[x][1] += (*this)[y][1], (*this)[y][0] = x;
    }
};

// 使用方法

// 1. find root
root = find(u);

// 2. merge [u, v]
merge(u, v);
```

<p></p>

## Sparse Table - ST 表

采用 `O(nlogn)` 预处理，达到 `O(1)/O(log)` 查询一次 `[l, r]` 区间最值，区间GCD 等问题

<p></p>

``` cpp
// 模板
template <typename T>
struct sparse_table : public std::vector<std::vector<T>> {
    constexpr sparse_table(int n = 0) :
        std::vector<std::vector<T>>(std::__lg(n) + 1, std::vector<T>(n + 1)) {}

    constexpr void init_table(const auto &check) & {
        for (int k = 1; k < (*this).size(); k += 1)
            for (int i = 1; i + (1 << k) <= (*this)[0].size(); i += 1)
                (*this)[k][i] = check((*this)[k - 1][i], (*this)[k - 1][i + (1 << k - 1)]);
    }

    constexpr T query(int l, int r, const auto &check) const {
        assert(r >= l);
        int k = std::__lg(r - l + 1);
        return check((*this)[k][l], (*this)[k][r - (1 << k) + 1]);
    }
};

// 使用方法

// 1. check
auto check = [&](T &l, T &r)->T {
    return opt(l, r);
};

// 2. init table
table[0] = init_value;
table.init_table(check);

// 3. range query
table.query(l, r, check);
```

<p></p>

## Fenwick Tree - 树状数组

树状数组巧妙的利用了二进制，以及树中子树的性质，将一次查询 `[1, u]` 变成了查询 `log(u)` 颗子树，而子树根则已经包含了子树的所有节点，故而能做到 `log(n)` 进行一次操作，而对一个点进行单点修改，则只需要一路往上修改父亲节点即可

<p></p>

``` cpp
// 模板
template <typename T>
struct fenwick_tree : public std::vector<T> {
    constexpr fenwick_tree(int n = 0) :
        std::vector<T>(n + 1) {}
    
    constexpr void update(int u, T x) & {
        assert(1 <= u && u < (*this)->size());
        for (; u < this->size(); u += u & -u)
            (*this)[u] += x;
    }

    constexpr T query(int u, T x = T()) const {
        assert(0 <= u && u < (*this)->size());
        for (; u; u -= u & -u)
            x += (*this)[u];
        return x;
    }
};

// 使用方法

// 1. index u add x
fenwick.update(u, x);

// 2. get [1, u] range opt
fenwick.query(u);
```

<p></p>

## Segment Tree - 线段树