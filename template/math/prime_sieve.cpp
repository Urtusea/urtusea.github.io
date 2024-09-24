template <int N> struct prime_sieve : public vector<int> {
    prime_sieve() : vector<int>() {
        bitset<N + 1> is_prime = 0;
        for (int i = 2; i <= N; i++) {
            if (!is_prime[i])
                (*this).push_back(i);
            for (auto &p : (*this)) {
                if (1LL * i * P > N) break;
                is_prime[i * p] = 1;
                if (i % p == 0) break;
            }
        }
    }
};