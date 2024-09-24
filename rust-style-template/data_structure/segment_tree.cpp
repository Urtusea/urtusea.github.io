#include <bits/stdc++.h>

template <typename Info> struct segment_tree {
public:
    #define lson (p << 1)
    #define rson (p << 1 | 1)
    #define mson (l + r >> 1)
    segment_tree(int _n) : n(_n), f(4 << std::__lg(_n)) {}
    segment_tree(std::vector<Info> info) : segment_tree(info.size() - 1) {
        auto build = [&](auto &&self, int p, int l, int r) -> void {
            if (l == r) return (void)(f[p] = info[l]);
            self(self, lson, l, mson);
            self(self, rson, mson + 1, r);
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
        update(lson, l, mson, u, x);
        update(rson, mson + 1, r, u, x);
        push_up(p);
    }
    auto query(int p, int l, int r, int x, int y) -> Info {
        if (r < x || y < l) return Info();
        if (x <= l && r <= y) return f[p];
        return query(lson, l, mson, x, y) + query(rson, mson + 1, r, x, y);
    }
    #undef lson
    #undef rson
    #undef mson
private:
    int n;
    std::vector<Info> f;
};