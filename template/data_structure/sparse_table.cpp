template <typename T> struct sparse_table {
public:
    sparse_table(int n = 0) : size(n),
                              node(__lg(n) + 1, vector<T>(n + 1)) {}
    sparse_table(vector<T> &a, auto &&check) : sparse_table(a.size() - 1) {
        node[0] = a;
        for (int k = 1; k <= __lg(size); k++)
            for (int i = 1; i + (1 << k) - 1 <= size; i++)
                node[k][i] = check(node[k - 1][i], node[k - 1][i + (1 << k - 1)]);
    }
    T query(int l, int r, auto &&check) {
        int k = __lg(r - l + 1);
        return check(node[k][l], node[k][r - (1 << k) + 1]);
    }
private:
    int size;
    vector<vector<T>> node;
};