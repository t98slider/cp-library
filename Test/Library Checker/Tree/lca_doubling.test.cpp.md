---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Tree/lca_doubling.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 (LCA, Lowest Common Ancestor) (\u30BF\
      \u30D6\u30EA\u30F3\u30B0)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"Test/Library Checker/Tree/lca_doubling.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <bits/stdc++.h>\n\
    #line 1 \"Tree/lca_doubling.hpp\"\nstruct LCA_tree {\n    int n, LOGV, root;\n\
    \    std::vector<std::vector<int>> &g, parent;\n    std::vector<int> depth, id;\n\
    \    LCA_tree(std::vector<std::vector<int>> &_g) : LCA_tree(_g, 0){}\n    LCA_tree(std::vector<std::vector<int>>\
    \ &_g, int r) : n(_g.size()), g(_g), root(r), depth(n), id(n, -1) {\n        LOGV\
    \ = std::__lg(std::max(1, n - 1));\n        parent.resize(LOGV + 1, std::vector<int>(n,\
    \ -1));\n        std::vector<int> stk;\n        stk.reserve(n);\n        stk.emplace_back(root);\n\
    \        depth[root] = 0;\n        int cnt = 0;\n        while(!stk.empty()){\n\
    \            int v = stk.back();\n            stk.pop_back();\n            id[v]\
    \ = cnt++;\n            for(int i = 1; (1 << i) <= depth[v]; i++){\n         \
    \       parent[i][v] = parent[i - 1][parent[i - 1][v]];\n            }\n     \
    \       for(auto &&u : g[v]){\n                if(id[u] != -1) continue;\n   \
    \             parent[0][u] = v;\n                depth[u] = depth[v] + 1;\n  \
    \              stk.emplace_back(u);\n            }\n        }\n    }\n    int\
    \ lca(int u, int v){\n        if(depth[u] > depth[v]) std::swap(u, v);\n     \
    \   int d = depth[v] - depth[u];\n        while(d){\n            v = parent[std::__lg(d\
    \ & -d)][v];\n            d -= d & -d;\n        }\n        if(u == v) return u;\n\
    \        for(int i = std::__lg(depth[v]); i >= 0; i--){\n            if(parent[i][u]\
    \ != parent[i][v]){\n                u = parent[i][u];\n                v = parent[i][v];\n\
    \            }\n        }\n        return parent[0][u];\n    }\n    int la(int\
    \ v, int d){\n        if(d > depth[v]) return -1;\n        while(d){\n       \
    \     v = parent[std::__lg(d & -d)][v];\n            d -= d & -d;\n        }\n\
    \        return v;\n    }\n    int dist(int u, int v){\n        assert(0 <= u\
    \ && u < n);\n        assert(0 <= v && v < n);\n        int lcav = lca(u, v);\n\
    \        return depth[u] + depth[v] - 2 * depth[lcav];\n    }\n    bool on_path(int\
    \ u, int v, int w){\n        return dist(u, w) + dist(w, v) == dist(u, v);\n \
    \   }\n    int min_edge(std::vector<int> &ver){\n        int ret = 0, m = ver.size();\n\
    \        std::sort(ver.begin(), ver.end(), [&](int va, int vb) {return id[va]\
    \ < id[vb];});\n        for(int i = 0; i < m; i++){\n            ret += depth[ver[i]];\n\
    \            ret -= depth[lca(ver[i], ver[i + 1 == m ? 0 : i + 1])];\n       \
    \ }\n        return ret;\n    }\n};\n#line 5 \"Test/Library Checker/Tree/lca_doubling.test.cpp\"\
    \n\nusing namespace std;\n\nint main(){\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(0);\n    int N, Q, v, u;\n    cin >> N >> Q;\n    vector<vector<int>>\
    \ G(N);\n    for(int i = 1; i < N; i++){\n        cin >> v;\n        G[v].emplace_back(i);\n\
    \        G[i].emplace_back(v);\n    }\n    LCA_tree g(G);\n    while(Q--){\n \
    \       cin >> u >> v;\n        cout << g.lca(u, v) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <bits/stdc++.h>\n\
    #include \"Tree/lca_doubling.hpp\"\n\nusing namespace std;\n\nint main(){\n  \
    \  ios::sync_with_stdio(false);\n    cin.tie(0);\n    int N, Q, v, u;\n    cin\
    \ >> N >> Q;\n    vector<vector<int>> G(N);\n    for(int i = 1; i < N; i++){\n\
    \        cin >> v;\n        G[v].emplace_back(i);\n        G[i].emplace_back(v);\n\
    \    }\n    LCA_tree g(G);\n    while(Q--){\n        cin >> u >> v;\n        cout\
    \ << g.lca(u, v) << '\\n';\n    }\n}\n"
  dependsOn:
  - Tree/lca_doubling.hpp
  isVerificationFile: true
  path: Test/Library Checker/Tree/lca_doubling.test.cpp
  requiredBy: []
  timestamp: '2023-06-24 15:29:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Library Checker/Tree/lca_doubling.test.cpp
layout: document
redirect_from:
- /verify/Test/Library Checker/Tree/lca_doubling.test.cpp
- /verify/Test/Library Checker/Tree/lca_doubling.test.cpp.html
title: Test/Library Checker/Tree/lca_doubling.test.cpp
---
