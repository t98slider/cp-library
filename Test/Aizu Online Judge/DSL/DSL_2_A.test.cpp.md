---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/segtree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_2_A
  bundledCode: "#line 1 \"Test/Aizu Online Judge/DSL/DSL_2_A.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_2_A\"\n\n#include\
    \ <bits/stdc++.h>\n#line 2 \"DataStructure/segtree.hpp\"\n\ntemplate <class S,\
    \ S (*op)(S, S), S (*e)()> struct segtree {\n    public:\n    segtree() : segtree(0)\
    \ {}\n    segtree(int n) : segtree(std::vector<S>(n, e())) {}\n    segtree(const\
    \ std::vector<S>& v) : _n(int(v.size())) {\n        log = ceil_pow2(_n);\n   \
    \     size = 1 << log;\n        d = std::vector<S>(2 * size, e());\n        for\
    \ (int i = 0; i < _n; i++) d[size + i] = v[i];\n        for (int i = size - 1;\
    \ i >= 1; i--) {\n            update(i);\n        }\n    }\n\n    void set(int\
    \ p, S x) {\n        assert(0 <= p && p < _n);\n        p += size;\n        d[p]\
    \ = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S\
    \ get(int p) {\n        assert(0 <= p && p < _n);\n        return d[p + size];\n\
    \    }\n    const S operator[](int p) const { return get(p); }\n    S operator[](int\
    \ p) { return get(p); }\n\n    S prod(int l, int r) {\n        assert(0 <= l &&\
    \ l <= r && r <= _n);\n        S sml = e(), smr = e();\n        l += size;\n \
    \       r += size;\n\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S\
    \ all_prod() { return d[1]; }\n\n    template <bool (*f)(S)> int max_right(int\
    \ l) {\n        return max_right(l, [](S x) { return f(x); });\n    }\n    template\
    \ <class F> int max_right(int l, F f) {\n        assert(0 <= l && l <= _n);\n\
    \        assert(f(e()));\n        if (l == _n) return _n;\n        l += size;\n\
    \        S sm = e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n\
    \            if (!f(op(sm, d[l]))) {\n                while (l < size) {\n   \
    \                 l = (2 * l);\n                    if (f(op(sm, d[l]))) {\n \
    \                       sm = op(sm, d[l]);\n                        l++;\n   \
    \                 }\n                }\n                return l - size;\n   \
    \         }\n            sm = op(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool (*f)(S)> int\
    \ min_left(int r) {\n        return min_left(r, [](S x) { return f(x); });\n \
    \   }\n    template <class F> int min_left(int r, F f) {\n        assert(0 <=\
    \ r && r <= _n);\n        assert(f(e()));\n        if (r == 0) return 0;\n   \
    \     r += size;\n        S sm = e();\n        do {\n            r--;\n      \
    \      while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm))) {\n\
    \                while (r < size) {\n                    r = (2 * r + 1);\n  \
    \                  if (f(op(d[r], sm))) {\n                        sm = op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = op(d[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\n    private:\n\
    \    int _n, size, log;\n    std::vector<S> d;\n    int ceil_pow2(int n) {\n \
    \       int x = 0;\n        while ((1U << x) < (unsigned int)(n)) x++;\n     \
    \   return x;\n    }\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]);\
    \ }\n};\n#line 5 \"Test/Aizu Online Judge/DSL/DSL_2_A.test.cpp\"\n\nint op(int\
    \ lhs, int rhs) {\n    return std::min(lhs, rhs);\n}\n\nint e(){\n    return std::numeric_limits<int>::max();\n\
    }\n\nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int n, q;\n    std::cin >> n >> q;\n    segtree<int, op, e> seg(n);\n   \
    \ while(q--){\n        int cmd, x, y;\n        std::cin >> cmd >> x >> y;\n  \
    \      if(cmd == 0) {\n            seg.set(x, y);\n        } else {\n        \
    \    std::cout << seg.prod(x, ++y) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_2_A\"\
    \n\n#include <bits/stdc++.h>\n#include \"../../../DataStructure/segtree.hpp\"\n\
    \nint op(int lhs, int rhs) {\n    return std::min(lhs, rhs);\n}\n\nint e(){\n\
    \    return std::numeric_limits<int>::max();\n}\n\nint main() {\n    std::cin.tie(0);\n\
    \    std::ios::sync_with_stdio(false);\n    int n, q;\n    std::cin >> n >> q;\n\
    \    segtree<int, op, e> seg(n);\n    while(q--){\n        int cmd, x, y;\n  \
    \      std::cin >> cmd >> x >> y;\n        if(cmd == 0) {\n            seg.set(x,\
    \ y);\n        } else {\n            std::cout << seg.prod(x, ++y) << '\\n';\n\
    \        }\n    }\n}\n"
  dependsOn:
  - DataStructure/segtree.hpp
  isVerificationFile: true
  path: Test/Aizu Online Judge/DSL/DSL_2_A.test.cpp
  requiredBy: []
  timestamp: '2023-06-18 16:34:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Aizu Online Judge/DSL/DSL_2_A.test.cpp
layout: document
redirect_from:
- /verify/Test/Aizu Online Judge/DSL/DSL_2_A.test.cpp
- /verify/Test/Aizu Online Judge/DSL/DSL_2_A.test.cpp.html
title: Test/Aizu Online Judge/DSL/DSL_2_A.test.cpp
---
