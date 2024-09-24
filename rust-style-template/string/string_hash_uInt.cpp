template <uInt B> struct string_hash {
public:
    string_hash(const std::string &s = "", const char offset = 'a') : n(s.size()), hash(s.size() + 1, 1), base(s.size() + 1) {
        for (int i = 0; i < size; i++) {
            base[i + 1] = base[i] * B;
            hash[i + 1] = hash[i] + (s[i] - offset) * base[i];
        }
    }
    auto query(int l, int r) -> uInt {
        return (hash[r] - hash[l - 1]) * base[n - l + 1];
    }
private:
    int n;
    std::vector<uInt> hash, base;
};