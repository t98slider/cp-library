---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/scc.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3 (SCC, Strongly Connected Component)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"Test/Library Checker/Graph/scc.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/scc\"\n\n#include <bits/stdc++.h>\n#line 1\
    \ \"Graph/scc.hpp\"\nstruct SCC {\n    int n, group_num;\n    std::vector<std::vector<int>>\
    \ &g;\n    std::vector<int> ids;\n    SCC(std::vector<std::vector<int>> &_g) :\
    \ n(_g.size()), g(_g), ids(n), group_num(0) {\n        int now_ord = 0;\n    \
    \    std::vector<int> visited, low(n), ord(n, -1);\n        visited.reserve(n);\n\
    \        auto dfs = [&](auto self, int v) -> void {\n            low[v] = ord[v]\
    \ = now_ord++;\n            visited.emplace_back(v);\n            for(auto to\
    \ : g[v]) {\n                if (ord[to] == -1) {\n                    self(self,\
    \ to);\n                    low[v] = std::min(low[v], low[to]);\n            \
    \    } else {\n                    low[v] = std::min(low[v], ord[to]);\n     \
    \           }\n            }\n            if (low[v] == ord[v]) {\n          \
    \      while (true) {\n                    int u = visited.back();\n         \
    \           visited.pop_back();\n                    ord[u] = n;\n           \
    \         ids[u] = group_num;\n                    if (u == v) break;\n      \
    \          }\n                group_num++;\n            }\n        };\n      \
    \  for (int i = 0; i < n; i++) {\n            if (ord[i] == -1) dfs(dfs, i);\n\
    \        }\n        for (auto& x : ids) {\n            x = group_num - 1 - x;\n\
    \        }\n    }\n    const int operator[](int p) const {\n        assert(0 <=\
    \ p && p < n);\n        return ids[p];\n    }\n    int operator[](int p) { \n\
    \        assert(0 <= p && p < n);\n        return ids[p];\n    }\n    std::vector<std::vector<int>>\
    \ groups(){\n        std::vector<int> counts(group_num);\n        for (auto x\
    \ : ids) counts[x]++;\n        std::vector<std::vector<int>> groups(group_num);\n\
    \        for (int i = 0; i < group_num; i++) {\n            groups[i].reserve(counts[i]);\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            groups[ids[i]].emplace_back(i);\n\
    \        }\n        return groups;\n    }\n};\n#line 5 \"Test/Library Checker/Graph/scc.test.cpp\"\
    \n\nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int n, m, u, v;\n    std::cin >> n >> m;\n    std::vector<std::vector<int>>\
    \ g(n);\n    for(int i = 0; i < m; i++){\n        std::cin >> u >> v;\n      \
    \  g[u].emplace_back(v);\n    }\n    SCC scc(g);\n    auto G = scc.groups();\n\
    \    std::cout << G.size() << '\\n';\n    for(auto &&vec : scc.groups()){\n  \
    \      std::cout << vec.size();\n        for(auto &&v : vec) std::cout << ' '\
    \ << v;\n        std::cout << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <bits/stdc++.h>\n\
    #include \"Graph/scc.hpp\"\n\nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int n, m, u, v;\n    std::cin >> n >> m;\n    std::vector<std::vector<int>>\
    \ g(n);\n    for(int i = 0; i < m; i++){\n        std::cin >> u >> v;\n      \
    \  g[u].emplace_back(v);\n    }\n    SCC scc(g);\n    auto G = scc.groups();\n\
    \    std::cout << G.size() << '\\n';\n    for(auto &&vec : scc.groups()){\n  \
    \      std::cout << vec.size();\n        for(auto &&v : vec) std::cout << ' '\
    \ << v;\n        std::cout << '\\n';\n    }\n}\n"
  dependsOn:
  - Graph/scc.hpp
  isVerificationFile: true
  path: Test/Library Checker/Graph/scc.test.cpp
  requiredBy: []
  timestamp: '2023-06-22 23:16:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Library Checker/Graph/scc.test.cpp
layout: document
redirect_from:
- /verify/Test/Library Checker/Graph/scc.test.cpp
- /verify/Test/Library Checker/Graph/scc.test.cpp.html
title: Test/Library Checker/Graph/scc.test.cpp
---
