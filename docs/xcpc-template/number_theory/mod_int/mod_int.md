---
prev: false
next: false
---

# Mod Int - 模数类

## 代码模板

``` cpp
template <typename modint, typename int_t> struct modint_base {
  using B = int_t;
  using T = std::conditional_t<(sizeof(B) << 3) <= 32, Int, __int128_t>;
  using U = std::make_unsigned_t<T>;
  U x;
  constexpr modint_base() : x(0) {}
  constexpr modint_base(T _x) : x(maintain(_x % mod())) {}

  modint& to_modint() { return static_cast<modint&>(*this); }
  const modint& to_modint() const { return static_cast<const modint&>(*this); }

  static constexpr T mod() {
    return modint::mod();
  }
  constexpr U maintain(U x) const {
    return std::min(x, x + mod());
  }

  constexpr modint pow(T b) const {
    modint res = modint(1);
    for (modint a = to_modint(); b; a *= a, b >>= 1)
      if (b & 1) res *= a;
    return res;
  }
  constexpr modint inv() const {
    return pow(mod() - 2);
  }

  modint operator - () const {
    modint res; res.x = mod() - x;
    return res;
  }
  modint& operator += (const modint& r) {
    x += r.x; x = std::min(x, x - mod());
    return to_modint();
  }
  modint& operator -= (const modint& r) {
    x -= r.x; x = std::min(x, x + mod());
    return to_modint();
  }
  modint& operator *= (const modint& r) {
    x = x * r.x % mod();
    return to_modint();
  }
  modint& operator /= (const modint&r) {
    return to_modint() *= r;
  }
  modint operator + (const modint& r) const { return modint(to_modint()) += r; }
  modint operator - (const modint& r) const { return modint(to_modint()) -= r; }
  modint operator * (const modint& r) const { return modint(to_modint()) *= r; }
  modint operator / (const modint& r) const { return modint(to_modint()) /= r; }
  bool operator == (const modint& r) const { return x == r.x; }
  bool operator != (const modint& r) const { return x != r.x; }
};

template <typename modint>
concept m_type = std::is_base_of_v<modint_base<modint, typename modint::B>, modint>;
template <m_type modint>
std::istream& operator >> (std::istream& is, modint& x) { return is >> x.x; }
template <m_type modint>
std::ostream& operator << (std::ostream& os, const modint& x) { return os << x.x; }

template <auto P> struct modint : modint_base<modint<P>, decltype(P)> {
  using base = modint_base<modint<P>, decltype(P)>;
  using base::base;
  static constexpr typename base::T mod() { return P; }
};

template <auto Tp> struct dynamic_modint : modint_base<dynamic_modint<Tp>, decltype(Tp)> {
  using base = modint_base<dynamic_modint<Tp>, decltype(Tp)>;
  using base::base;
  static thread_local typename base::T P;
  static typename base::T mod() { return P; }
};

template <auto Tp>
typename dynamic_modint<Tp>::base::T thread_local dynamic_modint<Tp>::P = 1;
```