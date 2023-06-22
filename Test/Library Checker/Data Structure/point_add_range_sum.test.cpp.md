---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/fenwick_tree.hpp
    title: "\u30D5\u30A7\u30CB\u30C3\u30AF\u6728 (BIT, Binary Indexed Tree)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"Test/Library Checker/Data Structure/point_add_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include <bits/stdc++.h>\n#line 1 \"DataStructure/fenwick_tree.hpp\"\ntemplate\
    \ <class T> struct fenwick_tree {\n    using U = T;\n\n    public:\n    fenwick_tree()\
    \ : _n(0) {}\n    fenwick_tree(int n) : _n(n), data(n) {}\n\n    void add(int\
    \ p, T x) {\n        assert(0 <= p && p < _n);\n        p++;\n        while (p\
    \ <= _n) {\n            data[p - 1] += U(x);\n            p += p & -p;\n     \
    \   }\n    }\n\n    T sum(int l, int r) {\n        assert(0 <= l && l <= r &&\
    \ r <= _n);\n        return sum(r) - sum(l);\n    }\n\n    private:\n    int _n;\n\
    \    std::vector<U> data;\n\n    U sum(int r) {\n        U s = 0;\n        while\
    \ (r > 0) {\n            s += data[r - 1];\n            r -= r & -r;\n       \
    \ }\n        return s;\n    }\n};\n#line 5 \"Test/Library Checker/Data Structure/point_add_range_sum.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    ios::sync_with_stdio(false);\n   \
    \ cin.tie(0);\n    int N, Q, cmd, l, r, v;\n    cin >> N >> Q;\n    fenwick_tree<long\
    \ long> fw(N);\n    for(int i = 0; i < N; i++){\n        cin >> v;\n        fw.add(i,\
    \ v);\n    }\n    while(Q--){\n        cin >> cmd >> l >> r;\n        if(cmd ==\
    \ 0){\n            fw.add(l, r);\n        }else{\n            cout << fw.sum(l,\
    \ r) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\n#include \"DataStructure/fenwick_tree.hpp\"\nusing\
    \ namespace std;\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(0);\n\
    \    int N, Q, cmd, l, r, v;\n    cin >> N >> Q;\n    fenwick_tree<long long>\
    \ fw(N);\n    for(int i = 0; i < N; i++){\n        cin >> v;\n        fw.add(i,\
    \ v);\n    }\n    while(Q--){\n        cin >> cmd >> l >> r;\n        if(cmd ==\
    \ 0){\n            fw.add(l, r);\n        }else{\n            cout << fw.sum(l,\
    \ r) << '\\n';\n        }\n    }\n}\n"
  dependsOn:
  - DataStructure/fenwick_tree.hpp
  isVerificationFile: true
  path: Test/Library Checker/Data Structure/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2023-06-22 23:27:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Library Checker/Data Structure/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/Test/Library Checker/Data Structure/point_add_range_sum.test.cpp
- /verify/Test/Library Checker/Data Structure/point_add_range_sum.test.cpp.html
title: Test/Library Checker/Data Structure/point_add_range_sum.test.cpp
---
