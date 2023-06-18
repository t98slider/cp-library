---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Library Checker/Graph/ StronglyConnectedComponents.test.cpp
    title: Test/Library Checker/Graph/ StronglyConnectedComponents.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/scc.hpp\"\nstruct SCC {\n    int n, group_num;\n \
    \   std::vector<std::vector<int>> &g;\n    std::vector<int> ids;\n    SCC(std::vector<std::vector<int>>\
    \ &_g) : n(_g.size()), g(_g), ids(n), group_num(0) {\n        int now_ord = 0;\n\
    \        std::vector<int> visited, low(n), ord(n, -1);\n        visited.reserve(n);\n\
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
    \        }\n        return groups;\n    }\n};\n"
  code: "struct SCC {\n    int n, group_num;\n    std::vector<std::vector<int>> &g;\n\
    \    std::vector<int> ids;\n    SCC(std::vector<std::vector<int>> &_g) : n(_g.size()),\
    \ g(_g), ids(n), group_num(0) {\n        int now_ord = 0;\n        std::vector<int>\
    \ visited, low(n), ord(n, -1);\n        visited.reserve(n);\n        auto dfs\
    \ = [&](auto self, int v) -> void {\n            low[v] = ord[v] = now_ord++;\n\
    \            visited.emplace_back(v);\n            for(auto to : g[v]) {\n   \
    \             if (ord[to] == -1) {\n                    self(self, to);\n    \
    \                low[v] = std::min(low[v], low[to]);\n                } else {\n\
    \                    low[v] = std::min(low[v], ord[to]);\n                }\n\
    \            }\n            if (low[v] == ord[v]) {\n                while (true)\
    \ {\n                    int u = visited.back();\n                    visited.pop_back();\n\
    \                    ord[u] = n;\n                    ids[u] = group_num;\n  \
    \                  if (u == v) break;\n                }\n                group_num++;\n\
    \            }\n        };\n        for (int i = 0; i < n; i++) {\n          \
    \  if (ord[i] == -1) dfs(dfs, i);\n        }\n        for (auto& x : ids) {\n\
    \            x = group_num - 1 - x;\n        }\n    }\n    const int operator[](int\
    \ p) const {\n        assert(0 <= p && p < n);\n        return ids[p];\n    }\n\
    \    int operator[](int p) { \n        assert(0 <= p && p < n);\n        return\
    \ ids[p];\n    }\n    std::vector<std::vector<int>> groups(){\n        std::vector<int>\
    \ counts(group_num);\n        for (auto x : ids) counts[x]++;\n        std::vector<std::vector<int>>\
    \ groups(group_num);\n        for (int i = 0; i < group_num; i++) {\n        \
    \    groups[i].reserve(counts[i]);\n        }\n        for (int i = 0; i < n;\
    \ i++) {\n            groups[ids[i]].emplace_back(i);\n        }\n        return\
    \ groups;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/scc.hpp
  requiredBy: []
  timestamp: '2023-06-18 20:06:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Library Checker/Graph/ StronglyConnectedComponents.test.cpp
documentation_of: Graph/scc.hpp
layout: document
title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3 (SCC, Strongly Connected Component)"
---

## 概要
強連結成分（SCC, Strongly Connected Component）に分解するためのライブラリである。(SCC=有向グラフにおいて、互いに行き来が可能な頂点の集合)

| 関数名など   | 機能        | 計算量    |
| ------------|----------- | --------- |
|`SCC(std::vector<std::vector<int>> g)`| 有向グラフをコンストラクタに渡して初期化する。渡した時点で強連結成分分解される。 | $\text{O} (n)$ | 
|`int scc[p]`|頂点 $p$ の属する強連結成分の `id` を返す。 $0 \leq p < n$  | $\text{O} (1)$ | 
|`std::vector<std::vector<int>> groups()`|	以下の条件を満たすような，「頂点のリスト」のリストを返す．<br>・全ての頂点がちょうど1つずつ，どれかのリストに含まれる．<br>・内側のリストと強連結成分が一対一に対応する．リスト内での頂点の順序は未定義である．<br>・リストはトポロジカルソートされている．異なる強連結成分の頂点 $u$ , $v$ について $u$ から $v$ に到達できる時, $u$ の属するリストは $v$ の属するリストよりも前にある．| $\text{O} (n)$ |
