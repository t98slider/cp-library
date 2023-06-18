---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/scc.hpp
layout: document
redirect_from:
- /library/Graph/scc.hpp
- /library/Graph/scc.hpp.html
title: Graph/scc.hpp
---
