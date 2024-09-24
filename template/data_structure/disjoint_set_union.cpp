struct disjoint_set_union {
public:
    disjoint_set_union(int n = 0) : node(n + 1),
                                    size(n + 1) {
        iota(node.begin(), node.end(), 0);
        fill(size.begin(), size.end(), 1);
    }
    int find(int x) {
        return x == node[x] ? x : node[x] = find(node[x]);
    }
    void merge(int x, int y) {
        if ((x = find(x)) == (y = find(y)))
            return;
        if (size[x] >= size[y])
            node[y] = x, size[x] += size[y];
        else
            node[x] = y, size[y] += size[x];
    }
private:
    vector<int> node, size;
};