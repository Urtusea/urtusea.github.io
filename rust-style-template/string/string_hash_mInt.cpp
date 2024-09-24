template <uInt B, uInt P> struct string_hash_mInt {
public:
    string_hash_mInt(const std::string &s, const char offset = 'a') : n(s.size()), hash(s.size() + 1), base(s.size() + 1, 1) {
        for (int i = 0; i < n; ++i) {
            base[i + 1] = base[i] * B % P;
            hash[i + 1] = (hash[i] + (s[i] - offset) * base[i] % P) % P;
        }
    }
    auto query(int l, int r) -> uInt {
        return (hash[r] - hash[l - 1] + P) % P * base[n - l + 1] % P; 
    }
private:
    int n;
    std::vector<uInt> hash, base;
};