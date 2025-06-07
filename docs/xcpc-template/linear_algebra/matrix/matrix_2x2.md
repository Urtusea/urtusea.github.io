---
prev: false
next: false
---

# Matrix 2x2 - 2x2矩阵类

## 代码模板

``` cpp
template <typename T> struct matrix {
  T a[2][2];
  
  matrix() {
    a[0][0] = a[0][1] = a[1][0] = a[1][1] = T();
  }

  matrix operator * (const matrix& r) const {
    matrix res;
    res.a[0][0] = a[0][0] * r.a[0][0] + a[0][1] * r.a[1][0];
    res.a[0][1] = a[0][0] * r.a[0][1] + a[0][1] * r.a[1][1];
    res.a[1][0] = a[1][0] * r.a[0][0] + a[1][1] * r.a[1][0];
    res.a[1][1] = a[1][0] * r.a[0][1] + a[1][1] * r.a[1][1];
    return std::move(res);
  }

  matrix operator + (const matrix& r) const {
    matrix res;
    res.a[0][0] = a[0][0] + r.a[0][0];
    res.a[0][1] = a[0][1] + r.a[0][1];
    res.a[1][0] = a[1][0] + r.a[1][0];
    res.a[1][1] = a[1][1] + r.a[1][1];
    return std::move(res);
  }

  matrix operator - (const matrix& r) const {
    matrix res;
    res.a[0][0] = a[0][0] - r.a[0][0];
    res.a[0][1] = a[0][1] - r.a[0][1];
    res.a[1][0] = a[1][0] - r.a[1][0];
    res.a[1][1] = a[1][1] - r.a[1][1];
    return std::move(res);
  }
};
```