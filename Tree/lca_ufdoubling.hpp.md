---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Library Checker/Tree/lca_ufdoubling.test.cpp
    title: Test/Library Checker/Tree/lca_ufdoubling.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Tree/lca_ufdoubling.hpp\"\nstruct LCA_tree {\n    int n,\
    \ root;\n    std::array<int, 32> log_table{};\n    std::vector<std::vector<int>>\
    \ &g, parent;\n    std::vector<int> depth, id;\n    LCA_tree(std::vector<std::vector<int>>\
    \ &_g) : LCA_tree(_g, 0){}\n    LCA_tree(std::vector<std::vector<int>> &_g, int\
    \ r)\n         : n(_g.size()), g(_g), root(r), depth(n), depth2(n), id(n, -1),\
    \ edge(n),\n           parent_or_size(n, -1), parent(5, std::vector<int>(n)) {\n\
    \        for(int i = 2; i < 32; i++) log_table[i] = log_table[i >> 1] + 1;\n \
    \       std::vector<int> stk, par(n, -1);\n        stk.reserve(n);\n        stk.emplace_back(root);\n\
    \        int cnt = 0, timer = 0;\n        while(!stk.empty()){\n            int\
    \ v = stk.back();\n            if(id[v] == -1){\n                id[v] = cnt++;\n\
    \                for(auto &&u : g[v]){\n                    if(id[u] != -1) continue;\n\
    \                    par[u] = v;\n                    depth[u] = depth[v] + 1;\n\
    \                    stk.emplace_back(u);\n                }\n            }else{\n\
    \                stk.pop_back();\n                if(par[v] == -1) break;\n  \
    \              int x = leader(v), y = leader(par[v]);\n                if(-parent_or_size[x]\
    \ < -parent_or_size[y]) std::swap(x, y);\n                parent_or_size[x] +=\
    \ parent_or_size[y];\n                parent_or_size[y] = x;\n               \
    \ parent[0][y] = x;\n                depth2[y] = 1;\n                edge[y] =\
    \ std::make_pair(timer++, par[v]);\n            }\n        }\n        for(int\
    \ i = 1; i < n; i++) leader(i);\n        parent[0][leader(0)] = -1;\n        for(int\
    \ i = 1; i < 5; i++){\n            for(int j = 0; j < n; j++){\n             \
    \   parent[i][j] = parent[i - 1][j] == -1 ? -1 : parent[i - 1][parent[i - 1][j]];\n\
    \            }\n        }\n    }\n    int lca(int u, int v){\n        assert(0\
    \ <= u && u < n);\n        assert(0 <= v && v < n);\n        if(u == v) return\
    \ v;\n        if(depth2[u] > depth2[v]) std::swap(u, v);\n        int d = std::max(0,\
    \ depth2[v] - depth2[u] - 1);\n        while(d){\n            v = parent[log_table[d\
    \ & -d]][v];\n            d -= d & -d;\n        }\n        if(u == parent[0][v])\
    \ return edge[v].second;\n        if(depth2[u] != depth2[v]) v = parent[0][v];\n\
    \        for(int i = log_table[depth2[v]]; i >= 0; i--){\n            if(parent[i][u]\
    \ != parent[i][v]){\n                u = parent[i][u];\n                v = parent[i][v];\n\
    \            }\n        }\n        if(edge[v].first > edge[u].first) return edge[v].second;\n\
    \        return edge[u].second;\n    }\n    int dist(int u, int v){\n        int\
    \ lcav = lca(u, v);\n        return depth[u] + depth[v] - 2 * depth[lcav];\n \
    \   }\n    bool on_path(int from, int to, int mid){\n        return dist(from,\
    \ mid) + dist(mid, to) == dist(from, to);\n    }\n    int Auxiliary_Tree(std::vector<int>\
    \ &ver){\n        int ret = 0, m = ver.size();\n        std::sort(ver.begin(),\
    \ ver.end(), [&](int va, int vb) {return id[va] < id[vb];});\n        for(int\
    \ i = 0; i < m; i++){\n            ret += depth[ver[i]];\n            ret -= depth[lca(ver[i],\
    \ ver[i + 1 == m ? 0 : i + 1])];\n        }\n        return ret;\n    }\n    private:\n\
    \    std::vector<int> parent_or_size, depth2;\n    std::vector<std::pair<int,int>>\
    \ edge;\n    int leader(int v){\n        if(parent_or_size[v] < 0) return v;\n\
    \        int root = leader(parent_or_size[v]);\n        depth2[v] += depth2[parent_or_size[v]];\n\
    \        return parent_or_size[v] = root;\n    }\n};\n"
  code: "struct LCA_tree {\n    int n, root;\n    std::array<int, 32> log_table{};\n\
    \    std::vector<std::vector<int>> &g, parent;\n    std::vector<int> depth, id;\n\
    \    LCA_tree(std::vector<std::vector<int>> &_g) : LCA_tree(_g, 0){}\n    LCA_tree(std::vector<std::vector<int>>\
    \ &_g, int r)\n         : n(_g.size()), g(_g), root(r), depth(n), depth2(n), id(n,\
    \ -1), edge(n),\n           parent_or_size(n, -1), parent(5, std::vector<int>(n))\
    \ {\n        for(int i = 2; i < 32; i++) log_table[i] = log_table[i >> 1] + 1;\n\
    \        std::vector<int> stk, par(n, -1);\n        stk.reserve(n);\n        stk.emplace_back(root);\n\
    \        int cnt = 0, timer = 0;\n        while(!stk.empty()){\n            int\
    \ v = stk.back();\n            if(id[v] == -1){\n                id[v] = cnt++;\n\
    \                for(auto &&u : g[v]){\n                    if(id[u] != -1) continue;\n\
    \                    par[u] = v;\n                    depth[u] = depth[v] + 1;\n\
    \                    stk.emplace_back(u);\n                }\n            }else{\n\
    \                stk.pop_back();\n                if(par[v] == -1) break;\n  \
    \              int x = leader(v), y = leader(par[v]);\n                if(-parent_or_size[x]\
    \ < -parent_or_size[y]) std::swap(x, y);\n                parent_or_size[x] +=\
    \ parent_or_size[y];\n                parent_or_size[y] = x;\n               \
    \ parent[0][y] = x;\n                depth2[y] = 1;\n                edge[y] =\
    \ std::make_pair(timer++, par[v]);\n            }\n        }\n        for(int\
    \ i = 1; i < n; i++) leader(i);\n        parent[0][leader(0)] = -1;\n        for(int\
    \ i = 1; i < 5; i++){\n            for(int j = 0; j < n; j++){\n             \
    \   parent[i][j] = parent[i - 1][j] == -1 ? -1 : parent[i - 1][parent[i - 1][j]];\n\
    \            }\n        }\n    }\n    int lca(int u, int v){\n        assert(0\
    \ <= u && u < n);\n        assert(0 <= v && v < n);\n        if(u == v) return\
    \ v;\n        if(depth2[u] > depth2[v]) std::swap(u, v);\n        int d = std::max(0,\
    \ depth2[v] - depth2[u] - 1);\n        while(d){\n            v = parent[log_table[d\
    \ & -d]][v];\n            d -= d & -d;\n        }\n        if(u == parent[0][v])\
    \ return edge[v].second;\n        if(depth2[u] != depth2[v]) v = parent[0][v];\n\
    \        for(int i = log_table[depth2[v]]; i >= 0; i--){\n            if(parent[i][u]\
    \ != parent[i][v]){\n                u = parent[i][u];\n                v = parent[i][v];\n\
    \            }\n        }\n        if(edge[v].first > edge[u].first) return edge[v].second;\n\
    \        return edge[u].second;\n    }\n    int dist(int u, int v){\n        int\
    \ lcav = lca(u, v);\n        return depth[u] + depth[v] - 2 * depth[lcav];\n \
    \   }\n    bool on_path(int from, int to, int mid){\n        return dist(from,\
    \ mid) + dist(mid, to) == dist(from, to);\n    }\n    int Auxiliary_Tree(std::vector<int>\
    \ &ver){\n        int ret = 0, m = ver.size();\n        std::sort(ver.begin(),\
    \ ver.end(), [&](int va, int vb) {return id[va] < id[vb];});\n        for(int\
    \ i = 0; i < m; i++){\n            ret += depth[ver[i]];\n            ret -= depth[lca(ver[i],\
    \ ver[i + 1 == m ? 0 : i + 1])];\n        }\n        return ret;\n    }\n    private:\n\
    \    std::vector<int> parent_or_size, depth2;\n    std::vector<std::pair<int,int>>\
    \ edge;\n    int leader(int v){\n        if(parent_or_size[v] < 0) return v;\n\
    \        int root = leader(parent_or_size[v]);\n        depth2[v] += depth2[parent_or_size[v]];\n\
    \        return parent_or_size[v] = root;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Tree/lca_ufdoubling.hpp
  requiredBy: []
  timestamp: '2023-06-26 01:57:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Library Checker/Tree/lca_ufdoubling.test.cpp
documentation_of: Tree/lca_ufdoubling.hpp
layout: document
title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 (LCA, Lowest Common Ancestor) (\u30C0\
  \u30D6\u30EA\u30F3\u30B0+UF)"
---

## 概要
構築 $\text{O}(N\log \log N)$ 、クエリ $\text{O}(\log \log N)$ で最小共通祖先 (Lowest Common Ancestor) を習得できるライブラリである。<br>
実装はDFSの行きがけ順と帰りがけ順のみを使用していて場合分けをやや簡潔にしている。<br>

|関数名など|機能|計算量|
|---------|----|-----|
|`LCA_tree(std::vector<std::vector<int>> G, int root)`|`root` を根とする LCA のダブリングテーブルを構築する。<br>・第1引数には無向辺の木もしくは根付き木を G としてコンストラクタに渡す。<br>・第2引数は省略可能。省略した場合 `0` を根とする。| $\text{O}(N\log \log N)$ |
|`int lca(int u, int v)`|頂点 $u$ と頂点 $v$ のLCAを返す。| $\text{O}(\log \log N)$ |
|`int dist(int u, int v)`|頂点 $u$ と頂点 $v$ の距離を出力する。| $\text{O}(\log \log N)$ |
|`bool on_path(int u, int v, int w)`|頂点 $w$ が頂点 $u$ と頂点 $v$ の単純パス上にあるかを判定する。| $\text{O}(\log \log N)$ |
|`int min_edge(std::vector<int> ver)`|頂点集合 $\text{ver}$ を連結にするために必要な辺の数を出力する。|頂点集合の大きさを $\|S\|$ として<br> $\text{O}(\|S\|\log \log N)$|
