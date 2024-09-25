# String Hash

## 介绍

字符串哈希是使用两个数 $Base$ 和 $Mod$，将一个字符串序列的子串的值都映射到 $[0, Mod)$，虽然会有冲突概率，但也不失是字符串算法中的基础算法，以及解决相关问题的高效算法

操作:

- `query(l, r)`: 查询原字符串 $[l, r]$ 的哈希值
    - 复杂度: $O(1)$

## 代码

### 模数哈希

``` cpp
template <uInt B, uInt P> struct string_hash_mInt {
public:
    string_hash_mInt(const std::string &s, const char offset = 'a')
    : n(s.size()), hash(s.size() + 1), base(s.size() + 1, 1) {
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
```

### 自然溢出哈希

``` cpp
template <uInt B> struct string_hash {
public:
    string_hash(const std::string &s = "", const char offset = 'a')
    : n(s.size()), hash(s.size() + 1, 1), base(s.size() + 1) {
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
```