---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/segtree_dual.hpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: Tree/hld.hpp
    title: "HL\u5206\u89E3 (HLD, Heavy-Light-Decomposition)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"Test/Library Checker/Tree/vertex_add_subtree_sum01.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\
    \n#include <bits/stdc++.h>\n#line 1 \"Tree/hld.hpp\"\nstruct Heavy_Light_Decomposition{\n\
    \    int N, tim = 0;\n    std::vector<int> sz, ent, leader, order, par;\n    std::vector<std::vector<int>>\
    \ &G;\n    Heavy_Light_Decomposition(std::vector<std::vector<int>> &g) : \n  \
    \          N(g.size()), G(g), sz(N), ent(N), leader(N), order(N), par(N) {\n \
    \       dfs_size(0, -1);\n        dfs_hld(0);\n    }\n    const int operator[](int\
    \ v) const {\n        assert(0 <= v && v < N);\n        return ent[v];\n    }\n\
    \    int operator[](int v) { \n        assert(0 <= v && v < N);\n        return\
    \ ent[v];\n    }\n    int la(int v, int k) {\n        while(true) {\n        \
    \    int u = leader[v];\n            if(ent[v] - k >= ent[u]) return order[ent[v]\
    \ - k];\n            k -= ent[v] - ent[u] + 1;\n            v = par[u];\n    \
    \    }\n    }\n    int la(int from, int to, int d){\n        int d1 = 0, d2 =\
    \ 0;\n        int v = from, u = to;\n        do{\n            if(ent[u] < ent[v]){\n\
    \                if(leader[u] == leader[v]){\n                    d1 += ent[v]\
    \ - ent[u];\n                    break;\n                }\n                d1\
    \ += ent[v] - ent[leader[v]] + 1;\n                v = par[leader[v]];\n     \
    \       }else{\n                if(leader[u] == leader[v]){\n                \
    \    d2 += ent[u] - ent[v];\n                    break;\n                }\n \
    \               d2 += ent[u] - ent[leader[u]] + 1;\n                u = par[leader[u]];\n\
    \            }\n        }while(true);\n        if(d > d1 + d2) return -1;\n  \
    \      return d <= d1 ? la(from, d) : la(to, d1 + d2 - d);\n    }\n    int lca(int\
    \ u, int v) {\n        do{\n            if(ent[u] > ent[v]) std::swap(u, v);\n\
    \            if(leader[u] == leader[v]) return u;\n            v = par[leader[v]];\n\
    \        }while(true);\n    }\n    int dist(int u, int v){\n        int ans =\
    \ 0;\n        do{\n            if(ent[u] > ent[v]) std::swap(u, v);\n        \
    \    if(leader[u] == leader[v]) return ans + ent[v] - ent[u];\n            ans\
    \ += ent[v] - ent[leader[v]] + 1;\n            v = par[leader[v]];\n        }while(true);\n\
    \    }\n    template< typename T, typename Q, typename F >\n    T query(int u,\
    \ int v, const T &identity, const Q &qf, const F &f, bool edge = false) {\n  \
    \      T ans = identity;\n        do{\n            if(ent[u] > ent[v]) std::swap(u,\
    \ v);\n            if(leader[u] == leader[v]) break;\n            ans = f( qf(ent[leader[v]],\
    \ ent[v] + 1), ans);\n            v = par[leader[v]];\n        }while(true);\n\
    \        return f( qf(ent[u] + edge, ent[v] + 1), ans);\n    }\n    template<\
    \ typename T, typename Q1, typename Q2, typename F >\n    T noncom_query(int u,\
    \ int v, const T &identity, const Q1 &up_f, const Q2 &down_f, const F &f, bool\
    \ edge = false) {\n        T sml = identity, smr = identity;\n        do{\n  \
    \          if(leader[u] == leader[v]) break;\n            if(ent[u] < ent[v]){\n\
    \                smr = f( up_f(ent[leader[v]], ent[v] + 1), smr);\n          \
    \      v = par[leader[v]];\n            }else{\n                sml = f( sml,\
    \ down_f(ent[leader[u]], ent[u] + 1));\n                u = par[leader[u]];\n\
    \            }\n        }while(true);\n        if(ent[u] < ent[v]){\n        \
    \    return f(sml,  f( up_f(ent[u] + edge, ent[v] + 1), smr));\n        }else{\n\
    \            return f(f(sml, down_f(ent[v] + edge, ent[u] + 1)), smr);\n     \
    \   }\n    }\n    template< typename Q >\n    void update(int u, int v, const\
    \ Q &q, bool edge = false) {\n        do{\n            if(ent[u] > ent[v]) std::swap(u,\
    \ v);\n            if(leader[u] == leader[v]) break;\n            q(ent[leader[v]],\
    \ ent[v] + 1);\n            v = par[leader[v]];\n        }while(true);\n     \
    \   q(ent[u] + edge, ent[v] + 1);\n    }\n    private:\n    void dfs_size(int\
    \ v, int p){\n        par[v] = p;\n        sz[v] = 1;\n        if(!G[v].empty()\
    \ && G[v][0] == p) std::swap(G[v][0], G[v].back());\n        for(auto &u : G[v]){\n\
    \            if(u == p) continue;\n            dfs_size(u, v);\n            sz[v]\
    \ += sz[u];\n            if(sz[u] > sz[G[v][0]]) std::swap(G[v][0], u);\n    \
    \    }\n    }\n    void dfs_hld(int v){\n        ent[v] = tim++;\n        order[ent[v]]\
    \ = v;\n        for(auto &u : G[v]) {\n            if(u == par[v]) continue;\n\
    \            leader[u] = (G[v][0] == u ? leader[v] : u);\n            dfs_hld(u);\n\
    \        }\n    }\n};\n#line 1 \"DataStructure/segtree_dual.hpp\"\ntemplate <class\
    \ S, S (*mapping)(S, S), S (*id)()> struct dual_segtree {\n    public:\n    dual_segtree()\
    \ : dual_segtree(0) {}\n    dual_segtree(int n) : dual_segtree(std::vector<S>(n,\
    \ id())) {}\n    dual_segtree(const std::vector<S>& v) : _n(int(v.size())) {\n\
    \        log = ceil_pow2(_n);\n        size = 1 << log;\n        d = std::vector<S>(2\
    \ * size, id());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n \
    \   }\n    const S& operator[](int p) const {\n        assert(0 <= p && p < _n);\n\
    \        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n  \
    \      return d[p];\n    }\n    S& operator[](int p) { \n        assert(0 <= p\
    \ && p < _n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p\
    \ >> i);\n        return d[p];\n    }\n    void apply(int p, S f) {\n        assert(0\
    \ <= p && p < _n);\n        p += size;\n        for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n        d[p] = mapping(f, d[p]);\n    }\n    void apply(int l,\
    \ int r, S f) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l ==\
    \ r) return;\n        l += size;\n        r += size;\n        for (int i = log;\
    \ i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n      \
    \      if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n        while\
    \ (l < r) {\n            if (l & 1) all_apply(l++, f);\n            if (r & 1)\
    \ all_apply(--r, f);\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \    }\n    private:\n    int _n, size, log;\n    std::vector<S> d;\n    void\
    \ all_apply(int k, S f) {\n        d[k] = mapping(f, d[k]);\n    }\n    void push(int\
    \ k) {\n        all_apply(2 * k, d[k]);\n        all_apply(2 * k + 1, d[k]);\n\
    \        d[k] = id();\n    }\n    int ceil_pow2(int n) {\n        int x = 0;\n\
    \        while ((1U << x) < (unsigned int)(n)) x++;\n        return x;\n    }\n\
    };\n#line 6 \"Test/Library Checker/Tree/vertex_add_subtree_sum01.test.cpp\"\n\n\
    using namespace std;\nusing ll = long long;\nll op(ll af, ll bf){ return af +\
    \ bf; }\nll e(){return 0;}\n\nint main(){\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(0);\n    int N, Q, cmd, u, v;\n    cin >> N >> Q;\n    vector<ll>\
    \ a(N), b(N);\n    vector<int> par(N);\n    vector<vector<int>> g(N);\n    for(auto\
    \ &&v : a) cin >> v;\n    for(int i = 1; i < N; i++){\n        cin >> par[i];\n\
    \        g[par[i]].emplace_back(i);\n    }\n    Heavy_Light_Decomposition HLD(g);\n\
    \    for(int i = N - 1; i >= 1; i--){\n        a[par[i]] += a[i];\n        b[HLD[i]]\
    \ = a[i];\n    }\n    b[0] = a[0];\n    dual_segtree<ll, op, e> seg(b);\n    auto\
    \ update = [&](int l, int r){\n        seg.apply(l, r, v);\n    };\n    while(Q--){\n\
    \        cin >> cmd >> u;\n        if(cmd == 0){\n            cin >> v;\n    \
    \        HLD.update(0, u, update);\n        }else{\n            cout << seg[HLD[u]]\
    \ << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include <bits/stdc++.h>\n#include \"Tree/hld.hpp\"\n#include \"DataStructure/segtree_dual.hpp\"\
    \n\nusing namespace std;\nusing ll = long long;\nll op(ll af, ll bf){ return af\
    \ + bf; }\nll e(){return 0;}\n\nint main(){\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(0);\n    int N, Q, cmd, u, v;\n    cin >> N >> Q;\n    vector<ll>\
    \ a(N), b(N);\n    vector<int> par(N);\n    vector<vector<int>> g(N);\n    for(auto\
    \ &&v : a) cin >> v;\n    for(int i = 1; i < N; i++){\n        cin >> par[i];\n\
    \        g[par[i]].emplace_back(i);\n    }\n    Heavy_Light_Decomposition HLD(g);\n\
    \    for(int i = N - 1; i >= 1; i--){\n        a[par[i]] += a[i];\n        b[HLD[i]]\
    \ = a[i];\n    }\n    b[0] = a[0];\n    dual_segtree<ll, op, e> seg(b);\n    auto\
    \ update = [&](int l, int r){\n        seg.apply(l, r, v);\n    };\n    while(Q--){\n\
    \        cin >> cmd >> u;\n        if(cmd == 0){\n            cin >> v;\n    \
    \        HLD.update(0, u, update);\n        }else{\n            cout << seg[HLD[u]]\
    \ << '\\n';\n        }\n    }\n}\n"
  dependsOn:
  - Tree/hld.hpp
  - DataStructure/segtree_dual.hpp
  isVerificationFile: true
  path: Test/Library Checker/Tree/vertex_add_subtree_sum01.test.cpp
  requiredBy: []
  timestamp: '2023-06-28 01:28:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Library Checker/Tree/vertex_add_subtree_sum01.test.cpp
layout: document
redirect_from:
- /verify/Test/Library Checker/Tree/vertex_add_subtree_sum01.test.cpp
- /verify/Test/Library Checker/Tree/vertex_add_subtree_sum01.test.cpp.html
title: Test/Library Checker/Tree/vertex_add_subtree_sum01.test.cpp
---
