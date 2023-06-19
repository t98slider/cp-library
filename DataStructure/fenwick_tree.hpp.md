---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Aizu Online Judge/ALDS1/ALDS1_05_D.test.cpp
    title: Test/Aizu Online Judge/ALDS1/ALDS1_05_D.test.cpp
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
  - Test/Aizu Online Judge/ALDS1/ALDS1_05_D.test.cpp
documentation_of: DataStructure/fenwick_tree.hpp
layout: document
redirect_from:
- /library/DataStructure/fenwick_tree.hpp
- /library/DataStructure/fenwick_tree.hpp.html
title: DataStructure/fenwick_tree.hpp
---
