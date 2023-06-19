---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Aizu Online Judge/ALDS1/ALDS1_05_D.test.cpp
    title: Test/Aizu Online Judge/ALDS1/ALDS1_05_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Library Checker/Data Structure/point_add_range_sum.test.cpp
    title: Test/Library Checker/Data Structure/point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/fenwick_tree.hpp\"\ntemplate <class T> struct\
    \ fenwick_tree {\n    using U = T;\n\n    public:\n    fenwick_tree() : _n(0)\
    \ {}\n    fenwick_tree(int n) : _n(n), data(n) {}\n\n    void add(int p, T x)\
    \ {\n        assert(0 <= p && p < _n);\n        p++;\n        while (p <= _n)\
    \ {\n            data[p - 1] += U(x);\n            p += p & -p;\n        }\n \
    \   }\n\n    T sum(int l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n\
    \        return sum(r) - sum(l);\n    }\n\n    private:\n    int _n;\n    std::vector<U>\
    \ data;\n\n    U sum(int r) {\n        U s = 0;\n        while (r > 0) {\n   \
    \         s += data[r - 1];\n            r -= r & -r;\n        }\n        return\
    \ s;\n    }\n};\n"
  code: "template <class T> struct fenwick_tree {\n    using U = T;\n\n    public:\n\
    \    fenwick_tree() : _n(0) {}\n    fenwick_tree(int n) : _n(n), data(n) {}\n\n\
    \    void add(int p, T x) {\n        assert(0 <= p && p < _n);\n        p++;\n\
    \        while (p <= _n) {\n            data[p - 1] += U(x);\n            p +=\
    \ p & -p;\n        }\n    }\n\n    T sum(int l, int r) {\n        assert(0 <=\
    \ l && l <= r && r <= _n);\n        return sum(r) - sum(l);\n    }\n\n    private:\n\
    \    int _n;\n    std::vector<U> data;\n\n    U sum(int r) {\n        U s = 0;\n\
    \        while (r > 0) {\n            s += data[r - 1];\n            r -= r &\
    \ -r;\n        }\n        return s;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/fenwick_tree.hpp
  requiredBy: []
  timestamp: '2023-06-19 14:35:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Library Checker/Data Structure/point_add_range_sum.test.cpp
  - Test/Aizu Online Judge/ALDS1/ALDS1_05_D.test.cpp
documentation_of: DataStructure/fenwick_tree.hpp
layout: document
title: "\u30D5\u30A7\u30CB\u30C3\u30AF\u6728 (BIT, Binary Indexed Tree)"
---

## 概要
Fenwick Tree は区間の要素の総和を $\text{O}(\log N)$ で求めることができるデータ構造である．<br>
実装は AtCoder Library のパクリ。

|関数名など|機能|計算量|
|---------|----|-----|
|`fenwick_tree<T>(int n)`| 宣言.  $n$ 個の要素をもつ配列を作る．初期値は0．<br> `T` は `+` と `-` が定義されている構造体を載せることができる。| $\text{O}(n)$ |
|`void add(int p, T x)`| $a[p] += x$ を行う.  $0 \leq p < n$ | $\text{O}(\log n)$|
|`T sum(int l, int r)`| $a[l] + a[l - 1] + \cdots + a[r - 1]$  を返す。 $0 \leq l \leq r < n$ | $\text{O}(\log n)$ |
