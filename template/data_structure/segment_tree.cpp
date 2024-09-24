template <typename Info> struct segment_tree {
#define lson (p << 1)
#define rson (p << 1 | 1)
public:
    segment_tree(int n = 0) : size(n),
                              node(4 << __lg(n)) {}
    segment_tree(vector<Info> a) : segment_tree(a.size() - 1) {
        auto build = [&](auto &&self, int p, int l, int r) {
            if (l == r)
                return (void)(node[p] = a[l]);
            int m = l + r >> 1;
            self(self, lson, l,     m);
            self(self, rson, m + 1, r);
            push_up(p);
        };
        build(build, 1, 1, size);
    }
    void push_up(int p) {
        node[p] = node[lson] + node[rson];
    }
    void update(int x, Info val) {
        return update(1, 1, size, x, val);
    }
    void update(int p, int l, int r, int x, Info val) {
        if (x < l || r < x)
            return;
        if (l == r)
            return (void)(node[p] = val);
        int m = l + r >> 1;
        update(lson, l,     m, x, val);
        update(rson, m + 1, r, x, val);
        push_up(p);
    }
    Info query(int l, int r) {
        return query(1, 1, size, l, r);
    }
    Info query(int p, int l, int r, int x, int y) {
        if (y <  l || r <  x)
            return Info();
        if (x <= l && r <= y)
            return node[p];
        int m = l + r >> 1;
        return query(lson, l, m, x, y) + query(rson, m + 1, r, x, y);
    }
    int search_left(int l, int r, auto &&check) {
        return search_left(1, 1, size, l, r, check);
    }
    int search_left(int p, int l, int r, int x, int y, auto &&check) {
        if (y < l || r < x || !check(node[p]))
            return -1;
        if (l == r)
            return l;
        int m = l + r >> 1;
        int res = search_left(lson, l, m, x, y, check);
        if (res == -1)
            return search_left(rson, m + 1, r, x, y, check);
        else
            return res;
    }
    int search_right(int l, int r, auto &&check) {
        return search_right(1, 1, size, l, r, check);
    }
    int search_right(int p, int l, int r, int x, int y, auto &&check) {
        if (y < l || r < x || !check(node[p]))
            return -1;
        if (l == r)
            return l;
        int m = l + r >> 1;
        int res = search_right(rson, m + 1, r, x, y, check);
        if (res == -1)
            return search_right(lson, l, m, x, y, check);
        else
            return res;
    }
private:
    int size;
    vector<Info> node;
#undef lson
#undef rson
};

struct info {
    info() {}
};

info operator + (info l, info r) {
    
}