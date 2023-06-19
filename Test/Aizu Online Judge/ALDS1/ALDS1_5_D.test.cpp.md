---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../DataStructure/fewnick_tree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D\"\
    \n\n#include <bits/stdc++.h>\n#include \"../../../DataStructure/fewnick_tree.hpp\"\
    \n\ntemplate <class T> struct fenwick_tree {\n    using U = T;\n\n    public:\n\
    \    fenwick_tree() : _n(0) {}\n    fenwick_tree(int n) : _n(n), data(n) {}\n\n\
    \    void add(int p, T x) {\n        assert(0 <= p && p < _n);\n        p++;\n\
    \        while (p <= _n) {\n            data[p - 1] += U(x);\n            p +=\
    \ p & -p;\n        }\n    }\n\n    T sum(int l, int r) {\n        assert(0 <=\
    \ l && l <= r && r <= _n);\n        return sum(r) - sum(l);\n    }\n\n    private:\n\
    \    int _n;\n    std::vector<U> data;\n\n    U sum(int r) {\n        U s = 0;\n\
    \        while (r > 0) {\n            s += data[r - 1];\n            r -= r &\
    \ -r;\n        }\n        return s;\n    }\n};\n\nint main(){\n    int n;\n  \
    \  std::cin >> n;\n    std::vector<int> a(n), ca;\n    for(auto &&v : a) cin >>\
    \ v;\n    ca = a;\n    sort(ca.begin(), ca.end());\n    ca.erase(unique(ca.begin(),\
    \ ca.end()), ca.end());\n    int m = ca.size();\n    fewnick_tree<int> fw(m);\n\
    \    long long ans = 0;\n    for(auto &&v : a){\n        v = std::distance(ca.begin(),\
    \ std::lower_bound(ca.begin(), ca.end(), v));\n        ans += fw.sum(v + 1, m);\n\
    \        fw.add(v, 1);\n    }\n    std::cout << ans << '\\n';\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: Test/Aizu Online Judge/ALDS1/ALDS1_5_D.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Test/Aizu Online Judge/ALDS1/ALDS1_5_D.test.cpp
layout: document
redirect_from:
- /verify/Test/Aizu Online Judge/ALDS1/ALDS1_5_D.test.cpp
- /verify/Test/Aizu Online Judge/ALDS1/ALDS1_5_D.test.cpp.html
title: Test/Aizu Online Judge/ALDS1/ALDS1_5_D.test.cpp
---
