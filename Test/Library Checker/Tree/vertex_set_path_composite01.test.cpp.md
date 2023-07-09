---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/segtree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: Math/modint.hpp
    title: Math/modint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"Test/Library Checker/Tree/vertex_set_path_composite01.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include <bits/stdc++.h>\n#line 1 \"Tree/hld.hpp\"\nstruct Heavy_Light_Decomposition{\n\
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
    \ int v, const T &identity, \n                   const Q1 &qf, const Q2 &rev_qf,\
    \ const F &f, bool edge = false) {\n        T sml = identity, smr = identity;\n\
    \        do{\n            if(leader[u] == leader[v]) break;\n            if(ent[u]\
    \ < ent[v]){\n                smr = f( qf(ent[leader[v]], ent[v] + 1), smr);\n\
    \                v = par[leader[v]];\n            }else{\n                sml\
    \ = f( sml, rev_qf(ent[leader[u]], ent[u] + 1));\n                u = par[leader[u]];\n\
    \            }\n        }while(true);\n        if(ent[u] < ent[v]){\n        \
    \    return f(sml,  f( qf(ent[u] + edge, ent[v] + 1), smr));\n        }else{\n\
    \            return f(f(sml, rev_qf(ent[v] + edge, ent[u] + 1)), smr);\n     \
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
    \        }\n    }\n};\n#line 1 \"DataStructure/segtree.hpp\"\ntemplate <class\
    \ S, S (*op)(S, S), S (*e)()> struct segtree {\n    public:\n    segtree() : segtree(0)\
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
    \ }\n};\n#line 1 \"Math/modint.hpp\"\ntemplate<const unsigned int MOD> struct\
    \ prime_modint {\n    using mint = prime_modint;\n    unsigned int v;\n    prime_modint()\
    \ : v(0) {}\n    prime_modint(unsigned int a) { a %= MOD; v = a; }\n    prime_modint(unsigned\
    \ long long a) { a %= MOD; v = a; }\n    prime_modint(int a) { a %= (int)(MOD);\
    \ if(a < 0)a += MOD; v = a; }\n    prime_modint(long long a) { a %= (int)(MOD);\
    \ if(a < 0)a += MOD; v = a; }\n    static constexpr int mod() { return MOD; }\n\
    \    mint& operator++() {v++; if(v == MOD)v = 0; return *this;}\n    mint& operator--()\
    \ {if(v == 0)v = MOD; v--; return *this;}\n    mint operator++(int) { mint result\
    \ = *this; ++*this; return result; }\n    mint operator--(int) { mint result =\
    \ *this; --*this; return result; }\n    mint& operator+=(const mint& rhs) { v\
    \ += rhs.v; if(v >= MOD) v -= MOD; return *this; }\n    mint& operator-=(const\
    \ mint& rhs) { if(v < rhs.v) v += MOD; v -= rhs.v; return *this; }\n    mint&\
    \ operator*=(const mint& rhs) {\n        v = (unsigned int)((unsigned long long)(v)\
    \ * rhs.v % MOD);\n        return *this;\n    }\n    mint& operator/=(const mint&\
    \ rhs) { return *this = *this * rhs.inv(); }\n    mint operator+() const { return\
    \ *this; }\n    mint operator-() const { return mint() - *this; }\n    mint pow(long\
    \ long n) const {\n        assert(0 <= n);\n        mint r = 1, x = *this;\n \
    \       while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n   \
    \         n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const\
    \ { assert(v); return pow(MOD - 2); }\n    friend mint operator+(const mint& lhs,\
    \ const mint& rhs) { return mint(lhs) += rhs; }\n    friend mint operator-(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }\n    friend bool operator==(const\
    \ mint& lhs, const mint& rhs) { return (lhs.v == rhs.v); }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return (lhs.v != rhs.v); }\n    friend std::ostream&\
    \ operator << (std::ostream &os, const mint& rhs) noexcept { return os << rhs.v;\
    \ }\n};\n#line 7 \"Test/Library Checker/Tree/vertex_set_path_composite01.test.cpp\"\
    \n\n//using mint = prime_modint<1000000007>;\nusing mint = prime_modint<998244353>;\n\
    \nusing namespace std;\n\nusing S = pair<mint, mint>;\nS op1(S lhs, S rhs){\n\
    \    return {rhs.first * lhs.first, rhs.first * lhs.second + rhs.second};\n}\n\
    S op2(S lhs, S rhs){\n    return {lhs.first * rhs.first, lhs.first * rhs.second\
    \ + lhs.second};\n}\nS e(){\n    return make_pair(1, 0);\n}\n\nint main(){\n \
    \   ios::sync_with_stdio(false);\n    cin.tie(0);\n    int N, Q, cmd, u, v, x;\n\
    \    cin >> N >> Q;\n    vector<pair<mint,mint>> a(N), b(N);\n    vector<vector<int>>\
    \ g(N);\n    for(int i = 0; i < N; i++){\n        cin >> a[i].first.v >> a[i].second.v;\n\
    \    }\n    for(int i = 1; i < N; i++){\n        cin >> u >> v;\n        g[u].emplace_back(v);\n\
    \        g[v].emplace_back(u);\n    }\n\n    Heavy_Light_Decomposition HLD(g);\n\
    \n    for(int i = 0; i < N; i++){\n        b[HLD[i]] = a[i];\n    }\n    segtree<S,\
    \ op1, e> seg1(b);\n    segtree<S, op2, e> seg2(b);\n\n    auto qf = [&](int l,\
    \ int r){\n        return seg1.prod(l, r);\n    };\n    auto rev_qf = [&](int\
    \ l, int r){\n        return seg2.prod(l, r);\n    };\n    auto f = [&](S lhs,\
    \ S rhs){\n        return make_pair(rhs.first * lhs.first, rhs.first * lhs.second\
    \ + rhs.second);\n    };\n\n    while(Q--){\n        cin >> cmd >> u >> v >> x;\n\
    \        if(cmd == 0){\n            seg1.set(HLD[u], make_pair(v, x));\n     \
    \       seg2.set(HLD[u], make_pair(v, x));\n        }else{\n            auto pa\
    \ = HLD.noncom_query(u, v, e(), qf, rev_qf, f);\n            cout << pa.first\
    \ * x + pa.second << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include <bits/stdc++.h>\n#include \"Tree/hld.hpp\"\n#include \"DataStructure/segtree.hpp\"\
    \n#include \"Math/modint.hpp\"\n\n//using mint = prime_modint<1000000007>;\nusing\
    \ mint = prime_modint<998244353>;\n\nusing namespace std;\n\nusing S = pair<mint,\
    \ mint>;\nS op1(S lhs, S rhs){\n    return {rhs.first * lhs.first, rhs.first *\
    \ lhs.second + rhs.second};\n}\nS op2(S lhs, S rhs){\n    return {lhs.first *\
    \ rhs.first, lhs.first * rhs.second + lhs.second};\n}\nS e(){\n    return make_pair(1,\
    \ 0);\n}\n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(0);\n \
    \   int N, Q, cmd, u, v, x;\n    cin >> N >> Q;\n    vector<pair<mint,mint>> a(N),\
    \ b(N);\n    vector<vector<int>> g(N);\n    for(int i = 0; i < N; i++){\n    \
    \    cin >> a[i].first.v >> a[i].second.v;\n    }\n    for(int i = 1; i < N; i++){\n\
    \        cin >> u >> v;\n        g[u].emplace_back(v);\n        g[v].emplace_back(u);\n\
    \    }\n\n    Heavy_Light_Decomposition HLD(g);\n\n    for(int i = 0; i < N; i++){\n\
    \        b[HLD[i]] = a[i];\n    }\n    segtree<S, op1, e> seg1(b);\n    segtree<S,\
    \ op2, e> seg2(b);\n\n    auto qf = [&](int l, int r){\n        return seg1.prod(l,\
    \ r);\n    };\n    auto rev_qf = [&](int l, int r){\n        return seg2.prod(l,\
    \ r);\n    };\n    auto f = [&](S lhs, S rhs){\n        return make_pair(rhs.first\
    \ * lhs.first, rhs.first * lhs.second + rhs.second);\n    };\n\n    while(Q--){\n\
    \        cin >> cmd >> u >> v >> x;\n        if(cmd == 0){\n            seg1.set(HLD[u],\
    \ make_pair(v, x));\n            seg2.set(HLD[u], make_pair(v, x));\n        }else{\n\
    \            auto pa = HLD.noncom_query(u, v, e(), qf, rev_qf, f);\n         \
    \   cout << pa.first * x + pa.second << '\\n';\n        }\n    }\n}\n"
  dependsOn:
  - Tree/hld.hpp
  - DataStructure/segtree.hpp
  - Math/modint.hpp
  isVerificationFile: true
  path: Test/Library Checker/Tree/vertex_set_path_composite01.test.cpp
  requiredBy: []
  timestamp: '2023-07-09 14:26:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Library Checker/Tree/vertex_set_path_composite01.test.cpp
layout: document
redirect_from:
- /verify/Test/Library Checker/Tree/vertex_set_path_composite01.test.cpp
- /verify/Test/Library Checker/Tree/vertex_set_path_composite01.test.cpp.html
title: Test/Library Checker/Tree/vertex_set_path_composite01.test.cpp
---
