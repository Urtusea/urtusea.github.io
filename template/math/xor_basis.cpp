template <int B> struct xor_basis {
public:
    xor_basis() : flag(false) { memset(node, 0, sizeof(node)); }
    void insert(uInt x) {
        for (int i = B; i >= 0; i--) {
            if (x >> i & 1) {
                if (!node[i]) {
                    node[i] = x;
                    break;
                } else {
                    x ^= node[i];
                }
            }
        }
        flag = true;
    }
    bool check(uInt x) {
        for (int i = B; i >= 0; i--) {
            if (x >> i & 1) {
                if (!node[i])
                    return false;
                else
                    x ^= node[i];
            }
        }
        return true;
    }
    uInt query_max() {
        uInt res = 0;
        for (int i = B; i >= 0; i--)
            res ^= node[i];
        return res;
    }
    uInt query_min() {
        uInt res = 0;
        for (int i = 0; !flag && i <= B; i++)
            if (node[i]) return node[i];
        return res;
    }
    uInt query_kth(uInt k) {
        static vector<uInt> tmp; tmp.clear();
        for (int i = 0; i <= B; i++) {
            for (int j = i - 1; j >= 0; j--)
                if (node[i] >> j & 1)
                    node[i] ^= node[j];
            if (node[i])
                tmp.emplace_back(node[i]);
        }
        if (!tmp.empty())
            k -= 1;
        if (k >= (1ULL << tmp.size() + 1))
            return -1;
        uInt res = 0;
        for (int i = 0; i < tmp.size(); i++)
            if (k >> i & 1) res ^= tmp[i];
        return res;
    }
    uInt query_xor_max(uInt x) {
        for (int i = B; i >= 0; i--)
            if ((x ^ node[i]) > x) x ^= node[i];
        return x;
    }
    uInt query_xor_min(uInt x) {
        for (int i = B; i >= 0; i--)
            if ((x ^ node[i]) < x) x ^= node[i];
        return x;
    }
private:
    bool flag;
    uInt node[B + 1];
};