---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Library Checker/lca01.test.cpp
    title: Test/Library Checker/lca01.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Tree/lca_doubling.hpp\"\nstruct LCA_tree {\n    int n, LOGV,\
    \ root;\n    std::vector<std::vector<int>> &g, parent;\n    std::vector<int> depth,\
    \ id;\n    LCA_tree(std::vector<std::vector<int>> &_g) : LCA_tree(_g, 0){}\n \
    \   LCA_tree(std::vector<std::vector<int>> &_g, int r) : n(_g.size()), g(_g),\
    \ root(r), depth(n, -1), id(n, -1) {\n        LOGV = std::__lg(std::max(1, n -\
    \ 1));\n        parent.resize(LOGV + 1, std::vector<int>(n, -1));\n        std::vector<int>\
    \ stk;\n        stk.reserve(n);\n        stk.emplace_back(root);\n        depth[root]\
    \ = 0;\n        int cnt = 0;\n        while(!stk.empty()){\n            int v\
    \ = stk.back();\n            if(id[v] == -1){\n                id[v] = cnt++;\n\
    \                for(int i = 1; (1 << i) <= depth[v]; i++){\n                \
    \    parent[i][v] = parent[i - 1][parent[i - 1][v]];\n                }\n    \
    \            for(auto &&u : g[v]){\n                    if(u == parent[0][v])\
    \ continue;\n                    parent[0][u] = v;\n                    depth[u]\
    \ = depth[v] + 1;\n                    stk.emplace_back(u);\n                }\n\
    \            }else stk.pop_back();\n        }\n    }\n    int lca(int u, int v){\n\
    \        if(depth[u] > depth[v]) std::swap(u, v);\n        int d = depth[v] -\
    \ depth[u];\n        while(d){\n            v = parent[std::__lg(d & -d)][v];\n\
    \            d -= d & -d;\n        }\n        if(u == v) return u;\n        for(int\
    \ i = std::__lg(depth[v]); i >= 0; i--){\n            if(parent[i][u] != parent[i][v]){\n\
    \                u = parent[i][u];\n                v = parent[i][v];\n      \
    \      }\n        }\n        return parent[0][u];\n    }\n    int la(int v, int\
    \ d){\n        if(d > depth[v]) return -1;\n        while(d){\n            v =\
    \ parent[std::__lg(d & -d)][v];\n            d -= d & -d;\n        }\n       \
    \ return v;\n    }\n    int dist(int u, int v){\n        assert(0 <= u && u <\
    \ n);\n        assert(0 <= v && v < n);\n        int lcav = lca(u, v);\n     \
    \   return depth[u] + depth[v] - 2 * depth[lcav];\n    }\n    bool on_path(int\
    \ u, int v, int w){\n        return dist(u, w) + dist(w, v) == dist(u, v);\n \
    \   }\n    int min_edge(std::vector<int> &ver){\n        int ret = 0, m = ver.size();\n\
    \        std::sort(ver.begin(), ver.end(), [&](int va, int vb) {return id[va]\
    \ < id[vb];});\n        for(int i = 0; i < m; i++){\n            ret += depth[ver[i]];\n\
    \            ret -= depth[lca(ver[i], ver[i + 1 == m ? 0 : i + 1])];\n       \
    \ }\n        return ret;\n    }\n};\n"
  code: "struct LCA_tree {\n    int n, LOGV, root;\n    std::vector<std::vector<int>>\
    \ &g, parent;\n    std::vector<int> depth, id;\n    LCA_tree(std::vector<std::vector<int>>\
    \ &_g) : LCA_tree(_g, 0){}\n    LCA_tree(std::vector<std::vector<int>> &_g, int\
    \ r) : n(_g.size()), g(_g), root(r), depth(n, -1), id(n, -1) {\n        LOGV =\
    \ std::__lg(std::max(1, n - 1));\n        parent.resize(LOGV + 1, std::vector<int>(n,\
    \ -1));\n        std::vector<int> stk;\n        stk.reserve(n);\n        stk.emplace_back(root);\n\
    \        depth[root] = 0;\n        int cnt = 0;\n        while(!stk.empty()){\n\
    \            int v = stk.back();\n            if(id[v] == -1){\n             \
    \   id[v] = cnt++;\n                for(int i = 1; (1 << i) <= depth[v]; i++){\n\
    \                    parent[i][v] = parent[i - 1][parent[i - 1][v]];\n       \
    \         }\n                for(auto &&u : g[v]){\n                    if(u ==\
    \ parent[0][v]) continue;\n                    parent[0][u] = v;\n           \
    \         depth[u] = depth[v] + 1;\n                    stk.emplace_back(u);\n\
    \                }\n            }else stk.pop_back();\n        }\n    }\n    int\
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
    \ }\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Tree/lca_doubling.hpp
  requiredBy: []
  timestamp: '2023-06-24 15:07:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Library Checker/lca01.test.cpp
documentation_of: Tree/lca_doubling.hpp
layout: document
redirect_from:
- /library/Tree/lca_doubling.hpp
- /library/Tree/lca_doubling.hpp.html
title: Tree/lca_doubling.hpp
---
