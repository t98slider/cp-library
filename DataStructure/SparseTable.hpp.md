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
  bundledCode: "#line 1 \"DataStructure/SparseTable.hpp\"\ntemplate <class T, T (*op)(T,\
    \ T), T (*e)()> struct SparseTable {\n    const int n, LOGV;\n    std::vector<std::vector<T>>\
    \ table;\n    std::vector<int> log_table;\n    SparseTable(const std::vector<T>\
    \ &v) : n(v.size()), LOGV(std::__lg(std::max(n, 1)) + 1), \n                 \
    \                          log_table(n + 1), table(LOGV, std::vector<T>(n)) {\n\
    \        std::copy(v.begin(), v.end(), table[0].begin());\n        for(int i =\
    \ 1; i < LOGV; i++) {\n            for(int j = 0; j + (1 << i) <= n; j++) {\n\
    \                table[i][j] = op(table[i - 1][j], table[i - 1][j + (1 << (i -\
    \ 1))]);\n            }\n        }\n        for(int i = 2; i <= n; i++) {\n  \
    \          log_table[i] = log_table[i >> 1] + 1;\n        }\n    }\n    T prod(int\
    \ l, int r){\n        assert(0 <= l && l <= r && r <= n);\n        if(l == r)\
    \ return e();\n        int b = log_table[r - l];\n        return op(table[b][l],\
    \ table[b][r - (1 << b)]);\n    }\n};\n"
  code: "template <class T, T (*op)(T, T), T (*e)()> struct SparseTable {\n    const\
    \ int n, LOGV;\n    std::vector<std::vector<T>> table;\n    std::vector<int> log_table;\n\
    \    SparseTable(const std::vector<T> &v) : n(v.size()), LOGV(std::__lg(std::max(n,\
    \ 1)) + 1), \n                                           log_table(n + 1), table(LOGV,\
    \ std::vector<T>(n)) {\n        std::copy(v.begin(), v.end(), table[0].begin());\n\
    \        for(int i = 1; i < LOGV; i++) {\n            for(int j = 0; j + (1 <<\
    \ i) <= n; j++) {\n                table[i][j] = op(table[i - 1][j], table[i -\
    \ 1][j + (1 << (i - 1))]);\n            }\n        }\n        for(int i = 2; i\
    \ <= n; i++) {\n            log_table[i] = log_table[i >> 1] + 1;\n        }\n\
    \    }\n    T prod(int l, int r){\n        assert(0 <= l && l <= r && r <= n);\n\
    \        if(l == r) return e();\n        int b = log_table[r - l];\n        return\
    \ op(table[b][l], table[b][r - (1 << b)]);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SparseTable.hpp
  requiredBy: []
  timestamp: '2023-06-28 23:38:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/SparseTable.hpp
layout: document
redirect_from:
- /library/DataStructure/SparseTable.hpp
- /library/DataStructure/SparseTable.hpp.html
title: DataStructure/SparseTable.hpp
---
