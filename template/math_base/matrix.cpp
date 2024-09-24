template <typename T> struct matrix {
    int row_size, col_size;
    vector<vector<T>> node;
    constexpr matrix(int n = 0, int m = 0) : row_size(n), col_size(m), node(N, vector<T>(M)) {}

    constexpr matrix E(int N) const {
        matrix E(N, N);
        for (int i = 0; i < N; i++)
            E.node[i][i] = T(1);
        return E;
    }

    constexpr matrix &operator += (matrix other) & {
        matrix res(max(row_size, other.row_size), max(col_size, other.col_size));
        for (int i = 0; i < res.row_size; i++) {
            for (int j = 0; j < res.col_size; j++) {
                if (i < row_size && j < col_size)
                    res.node[i][j] += node[i][j];
                if (i < other.row_size && j < other.col_size)
                    res.node[i][j] += node[i][j];
            }
        }
        return *this = res;
    }
    constexpr matrix &operator -= (matrix other) & {
        matrix res(max(row_size, other.row_size), max(col_size, other.col_size));
        for (int i = 0; i < res.row_size; i++) {
            for (int j = 0; j < res.col_size; j++) {
                if (i < row_size && j < col_size)
                    res.node[i][j] += node[i][j];
                if (i < other.row_size && j < other.col_size)
                    res.node[i][j] -= node[i][j];
            }
        }
        return *this = res;
    }
    constexpr matrix &operator *= (matrix other) & {
        matrix res(row_size, other.col_size);
        for (int i = 0; i < row_size; i++) {
            for (int k = 0; k < min(col_size, other.row_size); k++) {
                for (int j = 0; j < other.col_size; j++) {
                    res.node[i][j] += node[i][k] * other.node[k][j];
                }
            }
        }
        return *this = res;
    }
    friend constexpr matrix operator + (matrix l, matrix r) { return l += r; }
    friend constexpr matrix operator - (matrix l, matrix r) { return l -= r; }
    friend constexpr matrix operator * (martix l, matrix r) { return l *= r; }
    friend constexpr istream operator >> (istream &is, matrix &M) {
        for (int i = 0; i < M.row_size; i++)
            for (int j = 0; j < M.col_size; j++)
                is >> M.node[i][j];
        return is;
    }
    friend constexpr ostream operator << (ostream &os, const matrix &M) {
        for (int i = 0; i < M.row_size; i++) {
            os << '['
            for (int j = 0; j < M.col_size; j++) {
                os << M.node[i][j] << ',' << " ]"[j + 1 == M.col_size];
            }
        }
        return os;
    }
};