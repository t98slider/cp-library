---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Aizu Online Judge/ALDS1/ALDS1_14_C.test.cpp
    title: Test/Aizu Online Judge/ALDS1/ALDS1_14_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/yukicoder/yuki0755.test.cpp
    title: Test/yukicoder/yuki0755.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/CumulativeSum2D.hpp\"\ntemplate <class T>\
    \ struct CumulativeSum2D{\n    int h, w;\n    std::vector<std::vector<T>> dat;\n\
    \    CumulativeSum2D(int H, int W) : h(H), w(W), dat(H + 1, std::vector<T>(W +\
    \ 1, 0)) {}\n    CumulativeSum2D(std::vector<std::vector<T>> &A) \n        : h(A.size()),\
    \ w(A[0].size()), dat(h + 1, std::vector<T>(w + 1, 0)) {\n        for(int y =\
    \ 1; y <= h; y++){\n            for(int x = 1; x <= w; x++){\n               \
    \ dat[y][x] = A[y - 1][x - 1] + dat[y][x - 1] + dat[y - 1][x] - dat[y - 1][x -\
    \ 1];\n            }\n        }\n    }\n    void add(int y, int x, T z){\n   \
    \     assert(0 <= y && y < h);\n        assert(0 <= x && x < w);\n        dat[y\
    \ + 1][x + 1] += z;\n    }\n    void build(){\n        for(int y = 1; y <= h;\
    \ y++) {\n            for(int x = 1; x <= w; x++) {\n                dat[y][x]\
    \ += dat[y][x - 1] + dat[y - 1][x] - dat[y - 1][x - 1];\n            }\n     \
    \   }\n    }\n    T query(int ly, int lx, int ry, int rx){\n        assert(0 <=\
    \ ly && ly <= ry && ry <= h);\n        assert(0 <= lx && lx <= rx && rx <= w);\n\
    \        return dat[ry][rx] - dat[ly][rx] - dat[ry][lx] + dat[ly][lx];\n    }\n\
    };\n"
  code: "template <class T> struct CumulativeSum2D{\n    int h, w;\n    std::vector<std::vector<T>>\
    \ dat;\n    CumulativeSum2D(int H, int W) : h(H), w(W), dat(H + 1, std::vector<T>(W\
    \ + 1, 0)) {}\n    CumulativeSum2D(std::vector<std::vector<T>> &A) \n        :\
    \ h(A.size()), w(A[0].size()), dat(h + 1, std::vector<T>(w + 1, 0)) {\n      \
    \  for(int y = 1; y <= h; y++){\n            for(int x = 1; x <= w; x++){\n  \
    \              dat[y][x] = A[y - 1][x - 1] + dat[y][x - 1] + dat[y - 1][x] - dat[y\
    \ - 1][x - 1];\n            }\n        }\n    }\n    void add(int y, int x, T\
    \ z){\n        assert(0 <= y && y < h);\n        assert(0 <= x && x < w);\n  \
    \      dat[y + 1][x + 1] += z;\n    }\n    void build(){\n        for(int y =\
    \ 1; y <= h; y++) {\n            for(int x = 1; x <= w; x++) {\n             \
    \   dat[y][x] += dat[y][x - 1] + dat[y - 1][x] - dat[y - 1][x - 1];\n        \
    \    }\n        }\n    }\n    T query(int ly, int lx, int ry, int rx){\n     \
    \   assert(0 <= ly && ly <= ry && ry <= h);\n        assert(0 <= lx && lx <= rx\
    \ && rx <= w);\n        return dat[ry][rx] - dat[ly][rx] - dat[ry][lx] + dat[ly][lx];\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/CumulativeSum2D.hpp
  requiredBy: []
  timestamp: '2023-06-22 02:51:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Aizu Online Judge/ALDS1/ALDS1_14_C.test.cpp
  - Test/yukicoder/yuki0755.test.cpp
documentation_of: DataStructure/CumulativeSum2D.hpp
layout: document
title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
---

## 概要
平面内にある値の総和を収得できるデータ構造。

|関数名など|機能|計算量|
|---------|----|-----|
|(1) `CumulativeSum2D<T>(int H, int W)` <br> (2) `CumulativeSum2D(std::vector<std::vector<T>> A)`| `+` と `-` が定義されている構造体を載せることができる。<br> (1) $H \times W$ の配列を初期値 $0$ で作成する。 <br> (2) 2次元 vector に基づく値で 2次元累積和を構成する。| $\text{O}(HW)$ |
|`void add(int y, int x, T z)`| `a[y][x] += z` を行う.  $0 \leq y < H$, $0 \leq x < W$ | $\text{O}(1)$|
|`void build()`| 二次元累積和を構築する。コントラクタに2次元vectorを渡した場合は不要。| $\text{O}(HW)$ |
|`T query(int ly, int lx, int ry, int rx)`| ・ $ly \leq y < ry$ <br> ・ $lx \leq x < rx$ <br> を満たす `a[y][x]` の値の総和を収得する。| $\text{O}(1)$ |
