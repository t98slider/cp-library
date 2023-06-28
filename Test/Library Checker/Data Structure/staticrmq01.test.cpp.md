---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SparseTable.hpp
    title: DataStructure/SparseTable.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"Test/Library Checker/Data Structure/staticrmq01.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include <bits/stdc++.h>\n\
    #line 1 \"DataStructure/SparseTable.hpp\"\ntemplate <class T, T (*op)(T, T), T\
    \ (*e)()> struct SparseTable {\n    const int n, LOGV;\n    std::vector<std::vector<T>>\
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
    \ table[b][r - (1 << b)]);\n    }\n};\n#line 5 \"Test/Library Checker/Data Structure/staticrmq01.test.cpp\"\
    \n\nusing namespace std;\n\nint op(int a, int b){ return min(a, b); }\nint e(){\
    \ return 1 << 30; }\n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(0);\n\
    \    int N, Q, l, r;\n    cin >> N >> Q;\n    vector<int> a(N);\n    for(auto\
    \ &&v : a) cin >> v;\n    SparseTable<int, op, e> st(a);\n    \n    while(Q--){\n\
    \        cin >> l >> r;\n        cout << st.prod(l, r) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <bits/stdc++.h>\n#include \"DataStructure/SparseTable.hpp\"\n\nusing namespace\
    \ std;\n\nint op(int a, int b){ return min(a, b); }\nint e(){ return 1 << 30;\
    \ }\n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(0);\n    int\
    \ N, Q, l, r;\n    cin >> N >> Q;\n    vector<int> a(N);\n    for(auto &&v : a)\
    \ cin >> v;\n    SparseTable<int, op, e> st(a);\n    \n    while(Q--){\n     \
    \   cin >> l >> r;\n        cout << st.prod(l, r) << '\\n';\n    }\n}\n"
  dependsOn:
  - DataStructure/SparseTable.hpp
  isVerificationFile: true
  path: Test/Library Checker/Data Structure/staticrmq01.test.cpp
  requiredBy: []
  timestamp: '2023-06-28 23:41:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Library Checker/Data Structure/staticrmq01.test.cpp
layout: document
redirect_from:
- /verify/Test/Library Checker/Data Structure/staticrmq01.test.cpp
- /verify/Test/Library Checker/Data Structure/staticrmq01.test.cpp.html
title: Test/Library Checker/Data Structure/staticrmq01.test.cpp
---
