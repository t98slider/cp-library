---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/segtree_dual.hpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D
  bundledCode: "#line 1 \"Test/Aizu Online Judge/DSL/DSL_2_D.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D\"\n\n#include <bits/stdc++.h>\n\
    #line 1 \"DataStructure/segtree_dual.hpp\"\ntemplate <class S, S (*mapping)(S,\
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
    \ ((1U << x) < (unsigned int)(n)) x++;\n        return x;\n    }\n};\n#line 5\
    \ \"Test/Aizu Online Judge/DSL/DSL_2_D.test.cpp\"\n\nusing namespace std;\nint\
    \ op(int af, int bf){ return af == -1 ? bf : af; }\nint id(){ return -1; }\n\n\
    int main() {\n    ios::sync_with_stdio(false);\n    cin.tie(0);\n    int n, q;\n\
    \    cin >> n >> q;\n    dual_segtree<int, op, id> seg(vector<int>(n, numeric_limits<int>::max()));\n\
    \    while(q--){\n        int cmd;\n        cin >> cmd;\n        if(cmd == 0){\n\
    \            int l, r, x;\n            cin >> l >> r >> x;\n            seg.apply(l,\
    \ r + 1, x);\n        }else{\n            int p;\n            cin >> p;\n    \
    \        cout << seg[p] << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D\"\n\n\
    #include <bits/stdc++.h>\n#include \"../../../DataStructure/segtree_dual.hpp\"\
    \n\nusing namespace std;\nint op(int af, int bf){ return af == -1 ? bf : af; }\n\
    int id(){ return -1; }\n\nint main() {\n    ios::sync_with_stdio(false);\n   \
    \ cin.tie(0);\n    int n, q;\n    cin >> n >> q;\n    dual_segtree<int, op, id>\
    \ seg(vector<int>(n, numeric_limits<int>::max()));\n    while(q--){\n        int\
    \ cmd;\n        cin >> cmd;\n        if(cmd == 0){\n            int l, r, x;\n\
    \            cin >> l >> r >> x;\n            seg.apply(l, r + 1, x);\n      \
    \  }else{\n            int p;\n            cin >> p;\n            cout << seg[p]\
    \ << '\\n';\n        }\n    }\n}\n"
  dependsOn:
  - DataStructure/segtree_dual.hpp
  isVerificationFile: true
  path: Test/Aizu Online Judge/DSL/DSL_2_D.test.cpp
  requiredBy: []
  timestamp: '2023-06-22 14:48:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Aizu Online Judge/DSL/DSL_2_D.test.cpp
layout: document
redirect_from:
- /verify/Test/Aizu Online Judge/DSL/DSL_2_D.test.cpp
- /verify/Test/Aizu Online Judge/DSL/DSL_2_D.test.cpp.html
title: Test/Aizu Online Judge/DSL/DSL_2_D.test.cpp
---
