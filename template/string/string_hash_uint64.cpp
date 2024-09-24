template <uInt B> struct string_hash {
public:
    string_hash(const string &s = "", const char offset = 'a') : size(s.size()),
                                                                 base(s.size() + 1),
                                                                 hash(s.size() + 1) {
        base[0] = 1;
        for (int i = 0; i < size; i++) {
            base[i + 1] = base[i] * B;
            hash[i + 1] = hash[i] + (s[i] - offset) * base[i];
        }
    }
    uInt query(int l, int r) {
        return (hash[r] - hash[l - 1]) * base[size - l + 1];
    }
private:
    int size;
    vector<uInt> base, hash;
};