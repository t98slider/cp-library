---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Library Checker/Tree/lca_doubling.test.cpp
    title: Test/Library Checker/Tree/lca_doubling.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Tree/lca_doubling.hpp\"\nstruct LCA_tree {\n    int n, LOGV,\
    \ root;\n    std::vector<std::vector<int>> &g, parent;\n    std::vector<int> depth,\
    \ id;\n    LCA_tree(std::vector<std::vector<int>> &_g) : LCA_tree(_g, 0){}\n \
    \   LCA_tree(std::vector<std::vector<int>> &_g, int r) : n(_g.size()), g(_g),\
    \ root(r), depth(n), id(n, -1) {\n        LOGV = std::__lg(std::max(1, n - 1));\n\
    \        parent.resize(LOGV + 1, std::vector<int>(n, -1));\n        std::vector<int>\
    \ stk;\n        stk.reserve(n);\n        stk.emplace_back(root);\n        depth[root]\
    \ = 0;\n        int cnt = 0;\n        while(!stk.empty()){\n            int v\
    \ = stk.back();\n            stk.pop_back();\n            id[v] = cnt++;\n   \
    \         for(int i = 1; (1 << i) <= depth[v]; i++){\n                parent[i][v]\
    \ = parent[i - 1][parent[i - 1][v]];\n            }\n            for(auto &&u\
    \ : g[v]){\n                if(id[u] != -1) continue;\n                parent[0][u]\
    \ = v;\n                depth[u] = depth[v] + 1;\n                stk.emplace_back(u);\n\
    \            }\n        }\n    }\n    int lca(int u, int v){\n        assert(0\
    \ <= u && u < n);\n        assert(0 <= v && v < n);\n        if(depth[u] > depth[v])\
    \ std::swap(u, v);\n        int d = depth[v] - depth[u];\n        while(d){\n\
    \            v = parent[std::__lg(d & -d)][v];\n            d -= d & -d;\n   \
    \     }\n        if(u == v) return u;\n        for(int i = std::__lg(depth[v]);\
    \ i >= 0; i--){\n            if(parent[i][u] != parent[i][v]){\n             \
    \   u = parent[i][u];\n                v = parent[i][v];\n            }\n    \
    \    }\n        return parent[0][u];\n    }\n    int la(int v, int d){\n     \
    \   if(d > depth[v]) return -1;\n        while(d){\n            v = parent[std::__lg(d\
    \ & -d)][v];\n            d -= d & -d;\n        }\n        return v;\n    }\n\
    \    int la(int from, int to, int d){\n        int lcav = lca(from, to);\n   \
    \     int len = depth[from] + depth[to] - 2 * depth[lcav];\n        if(d > len)\
    \ return -1;\n        return (d <= depth[from] - depth[lcav] ? la(from, d) : la(to,\
    \ len - d));\n    }\n    int dist(int u, int v){\n        int lcav = lca(u, v);\n\
    \        return depth[u] + depth[v] - 2 * depth[lcav];\n    }\n    bool on_path(int\
    \ from, int to, int mid){\n        return dist(from, mid) + dist(mid, to) == dist(from,\
    \ to);\n    }\n    int Auxiliary_Tree(std::vector<int> &ver){\n        int ret\
    \ = 0, m = ver.size();\n        std::sort(ver.begin(), ver.end(), [&](int va,\
    \ int vb) {return id[va] < id[vb];});\n        for(int i = 0; i < m; i++){\n \
    \           ret += depth[ver[i]];\n            ret -= depth[lca(ver[i], ver[i\
    \ + 1 == m ? 0 : i + 1])];\n        }\n        return ret;\n    }\n};\n"
  code: "struct LCA_tree {\n    int n, LOGV, root;\n    std::vector<std::vector<int>>\
    \ &g, parent;\n    std::vector<int> depth, id;\n    LCA_tree(std::vector<std::vector<int>>\
    \ &_g) : LCA_tree(_g, 0){}\n    LCA_tree(std::vector<std::vector<int>> &_g, int\
    \ r) : n(_g.size()), g(_g), root(r), depth(n), id(n, -1) {\n        LOGV = std::__lg(std::max(1,\
    \ n - 1));\n        parent.resize(LOGV + 1, std::vector<int>(n, -1));\n      \
    \  std::vector<int> stk;\n        stk.reserve(n);\n        stk.emplace_back(root);\n\
    \        depth[root] = 0;\n        int cnt = 0;\n        while(!stk.empty()){\n\
    \            int v = stk.back();\n            stk.pop_back();\n            id[v]\
    \ = cnt++;\n            for(int i = 1; (1 << i) <= depth[v]; i++){\n         \
    \       parent[i][v] = parent[i - 1][parent[i - 1][v]];\n            }\n     \
    \       for(auto &&u : g[v]){\n                if(id[u] != -1) continue;\n   \
    \             parent[0][u] = v;\n                depth[u] = depth[v] + 1;\n  \
    \              stk.emplace_back(u);\n            }\n        }\n    }\n    int\
    \ lca(int u, int v){\n        assert(0 <= u && u < n);\n        assert(0 <= v\
    \ && v < n);\n        if(depth[u] > depth[v]) std::swap(u, v);\n        int d\
    \ = depth[v] - depth[u];\n        while(d){\n            v = parent[std::__lg(d\
    \ & -d)][v];\n            d -= d & -d;\n        }\n        if(u == v) return u;\n\
    \        for(int i = std::__lg(depth[v]); i >= 0; i--){\n            if(parent[i][u]\
    \ != parent[i][v]){\n                u = parent[i][u];\n                v = parent[i][v];\n\
    \            }\n        }\n        return parent[0][u];\n    }\n    int la(int\
    \ v, int d){\n        if(d > depth[v]) return -1;\n        while(d){\n       \
    \     v = parent[std::__lg(d & -d)][v];\n            d -= d & -d;\n        }\n\
    \        return v;\n    }\n    int la(int from, int to, int d){\n        int lcav\
    \ = lca(from, to);\n        int len = depth[from] + depth[to] - 2 * depth[lcav];\n\
    \        if(d > len) return -1;\n        return (d <= depth[from] - depth[lcav]\
    \ ? la(from, d) : la(to, len - d));\n    }\n    int dist(int u, int v){\n    \
    \    int lcav = lca(u, v);\n        return depth[u] + depth[v] - 2 * depth[lcav];\n\
    \    }\n    bool on_path(int from, int to, int mid){\n        return dist(from,\
    \ mid) + dist(mid, to) == dist(from, to);\n    }\n    int Auxiliary_Tree(std::vector<int>\
    \ &ver){\n        int ret = 0, m = ver.size();\n        std::sort(ver.begin(),\
    \ ver.end(), [&](int va, int vb) {return id[va] < id[vb];});\n        for(int\
    \ i = 0; i < m; i++){\n            ret += depth[ver[i]];\n            ret -= depth[lca(ver[i],\
    \ ver[i + 1 == m ? 0 : i + 1])];\n        }\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Tree/lca_doubling.hpp
  requiredBy: []
  timestamp: '2023-06-26 01:44:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Library Checker/Tree/lca_doubling.test.cpp
documentation_of: Tree/lca_doubling.hpp
layout: document
title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 (LCA, Lowest Common Ancestor) (\u30BF\
  \u30D6\u30EA\u30F3\u30B0)"
---

## 概要
構築 $\text{O}(N\log N)$ 、クエリ $\text{O}(\log N)$ で最小共通祖先 (Lowest Common Ancestor) を習得できるライブラリである。<br>
実装はDFSの行きがけ順のみを使用していて場合分けを簡潔にしている。<br>

|関数名など|機能|計算量|
|---------|----|-----|
|`LCA_tree(std::vector<std::vector<int>> G, int root)`|`root` を根とする LCA のダブリングテーブルを構築する。<br>・第1引数には無向辺の木もしくは根付き木を G としてコンストラクタに渡す。<br>・第2引数は省略可能。省略した場合 `0` を根とする。| $\text{O}(N\log N)$ |
|`int lca(int u, int v)`|頂点 $u$ と頂点 $v$ のLCAを返す。| $\text{O}(\log N)$ |
|(1) `int la(int v, int d)` <br>(2) `int la(int from, int to, int d)`|(1)頂点 $v$ から根に向かって距離 $d$ 進んだ頂点を返す。<br>(2)頂点 $\text{from}$ から頂点 $\text{to}$ に向かって距離 $d$ 進んだ頂点を返す。<br> 存在しない場合は `-1` を返す。| $\text{O}(\log N)$ |
|`int dist(int u, int v)`|頂点 $u$ と頂点 $v$ の距離を出力する。| $\text{O}(\log N)$ |
|`bool on_path(int from, int to, int mid)`|頂点 $\text{mid}$ が頂点 $\text{from}$ と頂点 $\text{to}$ の単純パス上にあるかを判定する。| $\text{O}(\log N)$ |
|`int Auxiliary_Tree(std::vector<int> ver)`|頂点集合 $\text{ver}$ を連結にするために必要な辺の数を出力する。|頂点集合の大きさを $\|S\|$ として<br> $\text{O}(\|S\|\log N)$|
