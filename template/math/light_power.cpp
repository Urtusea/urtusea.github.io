template <typename T> struct light_power {
public:
    light_power(int64_t n = 0, T a = T()) : block_size(sqrt(n)),
                                            base1(block_size + 1),
                                            base2(block_size + 1) {
        base1[0] = base2[0] = T(1);
        for (int i = 1; i <= block_size; i++)
            base1[i] = base1[i - 1] * a;
        for (int i = 1; i <= block_size; i++)
            base2[i] = base2[i - 1] * base1[block_size];
    }
    T operator [] (int64_t x) {
        return base1[x % block_size] * base2[x / block_size];
    }
private:
    int block_size;
    vector<T> base1, base2;
};