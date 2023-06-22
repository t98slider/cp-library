---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Aizu Online Judge/DSL/DSL_2_D.test.cpp
    title: Test/Aizu Online Judge/DSL/DSL_2_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/segtree_dual.hpp\"\ntemplate <class S, S (*mapping)(S,\
    \ S), S (*id)()> struct dual_segtree {\n    public:\n    dual_segtree() : dual_segtree(0)\
    \ {}\n    dual_segtree(int n) : dual_segtree(std::vector<S>(n, id())) {}\n   \
    \ dual_segtree(const std::vector<S>& v) : _n(int(v.size())) {\n        log = ceil_pow2(_n);\n\
    \        size = 1 << log;\n        d = std::vector<S>(2 * size, id());\n     \
    \   for (int i = 0; i < _n; i++) d[size + i] = v[i];\n    }\n    const S& operator[](int\
    \ p) const {\n        assert(0 <= p && p < _n);\n        p += size;\n        for\
    \ (int i = log; i >= 1; i--) push(p >> i);\n        return d[p];\n    }\n    S&\
    \ operator[](int p) { \n        assert(0 <= p && p < _n);\n        p += size;\n\
    \        for (int i = log; i >= 1; i--) push(p >> i);\n        return d[p];\n\
    \    }\n    void apply(int p, S f) {\n        assert(0 <= p && p < _n);\n    \
    \    p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n      \
    \  d[p] = mapping(f, d[p]);\n    }\n    void apply(int l, int r, S f) {\n    \
    \    assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return;\n     \
    \   l += size;\n        r += size;\n        for (int i = log; i >= 1; i--) {\n\
    \            if (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i)\
    \ << i) != r) push((r - 1) >> i);\n        }\n        while (l < r) {\n      \
    \      if (l & 1) all_apply(l++, f);\n            if (r & 1) all_apply(--r, f);\n\
    \            l >>= 1;\n            r >>= 1;\n        }\n    }\n    private:\n\
    \    int _n, size, log;\n    std::vector<S> d;\n    void all_apply(int k, S f)\
    \ {\n        d[k] = mapping(f, d[k]);\n    }\n    void push(int k) {\n       \
    \ all_apply(2 * k, d[k]);\n        all_apply(2 * k + 1, d[k]);\n        d[k] =\
    \ id();\n    }\n    int ceil_pow2(int n) {\n        int x = 0;\n        while\
    \ ((1U << x) < (unsigned int)(n)) x++;\n        return x;\n    }\n};\n"
  code: "template <class S, S (*mapping)(S, S), S (*id)()> struct dual_segtree {\n\
    \    public:\n    dual_segtree() : dual_segtree(0) {}\n    dual_segtree(int n)\
    \ : dual_segtree(std::vector<S>(n, id())) {}\n    dual_segtree(const std::vector<S>&\
    \ v) : _n(int(v.size())) {\n        log = ceil_pow2(_n);\n        size = 1 <<\
    \ log;\n        d = std::vector<S>(2 * size, id());\n        for (int i = 0; i\
    \ < _n; i++) d[size + i] = v[i];\n    }\n    const S& operator[](int p) const\
    \ {\n        assert(0 <= p && p < _n);\n        p += size;\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\n        return d[p];\n    }\n    S& operator[](int\
    \ p) { \n        assert(0 <= p && p < _n);\n        p += size;\n        for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n        return d[p];\n    }\n    void apply(int\
    \ p, S f) {\n        assert(0 <= p && p < _n);\n        p += size;\n        for\
    \ (int i = log; i >= 1; i--) push(p >> i);\n        d[p] = mapping(f, d[p]);\n\
    \    }\n    void apply(int l, int r, S f) {\n        assert(0 <= l && l <= r &&\
    \ r <= _n);\n        if (l == r) return;\n        l += size;\n        r += size;\n\
    \        for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) !=\
    \ l) push(l >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n\
    \        }\n        while (l < r) {\n            if (l & 1) all_apply(l++, f);\n\
    \            if (r & 1) all_apply(--r, f);\n            l >>= 1;\n           \
    \ r >>= 1;\n        }\n    }\n    private:\n    int _n, size, log;\n    std::vector<S>\
    \ d;\n    void all_apply(int k, S f) {\n        d[k] = mapping(f, d[k]);\n   \
    \ }\n    void push(int k) {\n        all_apply(2 * k, d[k]);\n        all_apply(2\
    \ * k + 1, d[k]);\n        d[k] = id();\n    }\n    int ceil_pow2(int n) {\n \
    \       int x = 0;\n        while ((1U << x) < (unsigned int)(n)) x++;\n     \
    \   return x;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/segtree_dual.hpp
  requiredBy: []
  timestamp: '2023-06-21 18:18:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Aizu Online Judge/DSL/DSL_2_D.test.cpp
documentation_of: DataStructure/segtree_dual.hpp
layout: document
title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---

## 概要
双対セグメント木は区間更新、1点収得を $\text{O}(\log N)$ で求めることができるデータ構造である．<br>
遅延評価セグメント木と比較すると区間収得のための更新を行わないため、定数倍が良い。<br>
実装は AtCoder Library の遅延セグ木から遅延評価のための配列 `lazy` だけを残したようなものになっている。<br><br>
宣言を簡易的にするために、`mapping` と `composition` 、モノイドの型 `S` と写像の型 `F` を同じものとなるように設計しているため、異なるものが欲しい場合は遅延セグ木を使う。<br><br>
以下の3つを宣言する必要がある。
- `S` : 写像の型 </li>
- `S mapping(S after, S before)` : `before` に `after` を作用させる関数。(合成写像と兼用) </li>
- `S id()` : 恒等写像。 `mapping(id(), f) = mapping(f, id()) = f` が満たされるようにする</li>

|関数名など|機能|計算量|
|---------|----|-----|
|(1) `dual_segtree<S, mapping, id>(int n)` <br> (2) `dual_segtree<S, mapping, id>(std::vector<S> vec)` | (1) $n$ 個の要素を持つ配列を作る。初期値は `id()` <br> (2) 双対セグ木の要素を `vec` で初期化する。| $\text{O}(n)$ |
|`S a[p]`|`a[p]` を収得する。  | $\text{O}(\log n)$|
|(1)`void apply(int p, S f)` <br> (2)`void apply(int l, int r, S f)`|(1) `a[p] = mapping(f, a[p])` を行う。<br>(2) $l \leq i < r$ について`a[i] = mapping(f, a[i])` を行う。 | $\text{O}(\log n)$ |
