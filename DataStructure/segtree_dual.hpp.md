---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/segtree_dual.hpp
layout: document
redirect_from:
- /library/DataStructure/segtree_dual.hpp
- /library/DataStructure/segtree_dual.hpp.html
title: DataStructure/segtree_dual.hpp
---
