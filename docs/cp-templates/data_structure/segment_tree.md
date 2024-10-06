# Segment Tree

## 代码

### 单点修改

``` cpp
template <typename Info> struct segment_tree {
public:
    #define lson (p << 1)
    #define rson (p << 1 | 1)
    segment_tree(int _n)
    : n(_n), f(4 << std::__lg(_n)) {}
    segment_tree(std::vector<Info> info)
    : segment_tree(info.size() - 1) {
        auto build = [&](auto &&self, int p, int l, int r) -> void {
            if (l == r) return (void)(f[p] = info[l]);
            int m = l + r >> 1;
            self(self, lson, l, m);
            self(self, rson, m + 1, r);
            push_up(p);
        };
        build(build, 1, 1, n);
    }
    auto push_up(int p) -> void {
        f[p] = f[lson] + f[rson];
    }
    auto update(int p, int l, int r, int u, Info x) -> void {
        if (u < l || r < u) return;
        if (l == r) return (void)(f[p] = x);
        int m = l + r >> 1;
        update(lson, l, m, u, x);
        update(rson, m + 1, r, u, x);
        push_up(p);
    }
    auto query(int p, int l, int r, int L, int R) -> Info {
        if (R <  l || r <  L) return Info();
        if (L <= l && r <= R) return f[p];
        int m = l + r >> 1;
        return query(lson, l, m, L, R) + query(rson, m + 1, r, L, R);
    }
    auto find_first(int p, int l, int r, int L, int R, auto &check) -> int {
        if (R < l || r > L || !check(f[p])) return -1;
        if (l == r) return l;
        int m = l + r >> 1;
        int res = find_first(lson, l, m, L, R, check);
        if (res == -1)
            return find_first(rson, m + 1, r, L, R, check);
        else
            return res;
    }
    auto find_last(int p, int l, int r, int L, int R, auto &check) -> int {
        if (R < l || r > L || !check(f[p])) return -1;
        if (l == r) return l;
        int m = l + r >> 1;
        int res = find_last(rson, m + 1, r, L, R, check);
        if (res == -1)
            return find_last(lson, l, m, L, R, check);
        else
            return res;
    }
    #undef lson
    #undef rson
private:
    int n;
    std::vector<Info> f;
};
```

### 区间修改

``` cpp
template <typename Info, typename Lazy> struct segment_tree {
public:
    #define lson (p << 1)
    #define rson (p << 1 | 1)
    segment_tree(int _n)
    : n(_n), f(4 << std::__lg(_n)), g(4 << std::__lg(_n)) {}
    segment_tree(std::vector<Info> info)
    : segment_tree(info.size() - 1) {
        auto build = [&](auto &&self, int p, int l, int r) -> void {
            if (l == r) return (void)(f[p] = info[l]);
            int m = l + r >> 1;
            self(self, lson, l, m);
            self(self, rson, m + 1, r);
            push_up(p);
        };
        build(build, 1, 1, n);
    }
    auto push_up(int p) -> void {
        f[p] = f[lson] + f[rson];
    }
    auto push_down(int p) -> void {
        f[lson] += g[p], g[lson] += g[p];
        f[rson] += g[p], g[rson] += g[p];
        g[p] = Lazy();
    }
    auto update(int p, int l, int r, int L, int R, Lazy x) -> void {
        if (R <  l || r <  L) return;
        if (L <= l && r <= R) return (void)(f[p] += x, g[p] += x);
        push_down(p);
        int m = l + r >> 1;
        update(lson, l, m, L, R, x);
        update(rson, m + 1, r, L, R, x);
        push_up(p);
    }
    auto query(int p, int l, int r, int L, int R) -> Info {
        if (R <  l || r <  L) return Info();
        if (L <= l && r <= R) return f[p];
        push_down(p);
        int m = l + r >> 1;
        return query(lson, l, m, L, R) + query(rson, m + 1, r, L, R);
    }
    auto find_first(int p, int l, int r, int L, int R, auto &check) -> int {
        if (R < l || r > L || !check(f[p])) return -1;
        if (l == r) return l;
        int m = l + r >> 1;
        int res = find_first(lson, l, m, L, R, check);
        if (res == -1)
            return find_first(rson, m + 1, r, L, R, check);
        else
            return res;
    }
    auto find_last(int p, int l, int r, int L, int R, auto &check) -> int {
        if (R < l || r > L || !check(f[p])) return -1;
        if (l == r) return l;
        int m = l + r >> 1;
        int res = find_last(rson, m + 1, r, L, R, check);
        if (res == -1)
            return find_last(lson, l, m, L, R, check);
        else
            return res;
    }
    #undef lson
    #undef rson
private:
    int n;
    std::vector<Info> f;
    std::vector<Lazy> g;
};
```

### 扫描线

``` cpp
std::vector<int> all = {-1};

struct info {
    int len, tag;
    info()
    : len(0), tag(0) {}
    info(int _len, int _tag)
    : len(_len), tag(_tag) {}
}

template <typename Info> struct segment_tree {
public:
    #define lson (p << 1)
    #define rson (p << 1 | 1)
    segment_tree(int _n)
    : n(_n), f(4 << std::__lg(_n)) {}
    auto push_up(int p, int l, int r) -> void {
        if (f[p].tag)
            f[p].len = all[r + 1] - all[l];
        else if (l != r)
            f[p].len = f[lson].len + f[rson].len;
        else
            f[p].len = 0;
    }
    auto update(int p, int l, int r, int L, int R, int x) -> void {
        if (R <= all[l] || all[r + 1] <= L) return;
        if (L <= all[l] && all[r + 1] <= R) return (void)(f[p].tag += x, push_up(p, l, r));
        int m = l + r >> 1;
        update(lson, l, m, L, R, x);
        update(rson, m + 1, r, L, R, x);
        push_up(p, l, r);
    }
    auto query(int p, int l, int r, int L, int R) -> int {
        if (R <= all[l] || all[r + 1] <= L) return 0;
        if (L <= all[l] && all[r + 1] <= R) return f[p].len;
        int m = l + r >> 1;
        return query(lson, l, m, L, R) + query(rson, m + 1, r, L, R);
    }
    #undef lson
    #undef rson
private:
    int n;
    std::vector<Info> f;
};
```