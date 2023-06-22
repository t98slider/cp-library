---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/CumulativeSum2D.hpp
    title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
  - icon: ':heavy_check_mark:'
    path: Math/modint_61bit.hpp
    title: Math/modint_61bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_C
  bundledCode: "#line 1 \"Test/Aizu Online Judge/ALDS1/ALDS1_14_C.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_C\"\n\n#include\
    \ <bits/stdc++.h>\n#line 1 \"DataStructure/CumulativeSum2D.hpp\"\ntemplate <class\
    \ T> struct CumulativeSum2D{\n    int h, w;\n    std::vector<std::vector<T>> dat;\n\
    \    CumulativeSum2D(int H, int W) : h(H), w(W), dat(H + 1, std::vector<T>(W +\
    \ 1, 0)) {}\n    CumulativeSum2D(std::vector<std::vector<T>> &A) \n        : h(A.size()),\
    \ w(A[0].size()), dat(h + 1, std::vector<T>(w + 1, 0)) {\n        for(int y =\
    \ 1; y <= h; y++){\n            for(int x = 1; x <= w; x++){\n               \
    \ dat[y][x] = A[y - 1][x - 1] + dat[y][x - 1] + dat[y - 1][x] - dat[y - 1][x -\
    \ 1];\n            }\n        }\n    }\n    void add(int y, int x, T z){\n   \
    \     assert(0 <= y && y < h);\n        assert(0 <= x && x < w);\n        dat[y\
    \ + 1][x + 1] += z;\n    }\n    void build(){\n        for(int y = 1; y <= h;\
    \ y++) {\n            for(int x = 1; x <= w; x++) {\n                dat[y][x]\
    \ += dat[y][x - 1] + dat[y - 1][x] - dat[y - 1][x - 1];\n            }\n     \
    \   }\n    }\n    T query(int ly, int lx, int ry, int rx){\n        assert(0 <=\
    \ ly && ly <= ry && ry <= h);\n        assert(0 <= lx && lx <= rx && rx <= w);\n\
    \        return dat[ry][rx] - dat[ly][rx] - dat[ry][lx] + dat[ly][lx];\n    }\n\
    };\n#line 1 \"Math/modint_61bit.hpp\"\ntemplate<const long long MOD = 2305843009213693951,\
    \ \n        const long long MASK31 = (1ll << 31) - 1, const long long MASK30 =\
    \ (1ll << 30) - 1>\nstruct modint61 {\n    using mint = modint61;\n    long long\
    \ v;\n    modint61() : v(0) {}\n    template<class T> modint61(T x) { \n     \
    \   while(x < 0) x += MOD;\n        while(x >= MOD) x -= MOD;\n        v = x;\n\
    \    }\n    long long safe_mod(long long x){\n        x = (x >> 61) + (x & MOD);\n\
    \        if (x >= MOD) x -= MOD;\n        return x;\n    }\n    static constexpr\
    \ long long mod() { return MOD; }\n    mint& operator++() {v++; if(v == MOD)v\
    \ = 0; return *this;}\n    mint& operator--() {if(v == 0)v = MOD; v--; return\
    \ *this;}\n    mint operator++(int) { mint result = *this; ++*this; return result;\
    \ }\n    mint operator--(int) { mint result = *this; --*this; return result; }\n\
    \    mint& operator+=(const mint& rhs) { v += rhs.v; if(v >= MOD) v -= MOD; return\
    \ *this; }\n    mint& operator-=(const mint& rhs) { if(v < rhs.v) v += MOD; v\
    \ -= rhs.v; return *this; }\n    mint& operator*=(const mint& rhs) {\n       \
    \ long long u = v >> 31, d = v & MASK31;\n        long long ru = rhs.v >> 31,\
    \ rd = rhs.v & MASK31;\n        long long mid = d * ru + u * rd;\n        v =\
    \ safe_mod(u * ru * 2 + (mid >> 30) + ((mid & MASK30) << 31) + d * rd);\n    \
    \    return *this;\n    }\n    mint& operator/=(const mint& rhs) { return *this\
    \ = *this * rhs.inv(); }\n    mint operator+() const { return *this; }\n    mint\
    \ operator-() const { return mint() - *this; }\n    mint pow(long long n) const\
    \ {\n        assert(0 <= n);\n        mint r = 1, x = *this;\n        while (n)\
    \ {\n            if (n & 1) r *= x;\n            x *= x;\n            n >>= 1;\n\
    \        }\n        return r;\n    }\n    mint inv() const { assert(v); return\
    \ pow(MOD - 2); }\n    friend mint operator+(const mint& lhs, const mint& rhs)\
    \ { return mint(lhs) += rhs; }\n    friend mint operator-(const mint& lhs, const\
    \ mint& rhs) { return mint(lhs) -= rhs; }\n    friend mint operator*(const mint&\
    \ lhs, const mint& rhs) { return mint(lhs) *= rhs; }\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }\n    friend bool operator<(const\
    \ mint& lhs, const mint& rhs) { return lhs.v < rhs.v; }\n    friend bool operator==(const\
    \ mint& lhs, const mint& rhs) { return (lhs.v == rhs.v); }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return (lhs.v != rhs.v); }\n    friend std::istream&\
    \ operator >> (std::istream& is, mint& rhs) noexcept {\n        long long tmp;\n\
    \        rhs = mint{(is >> tmp, tmp)};\n        return is;\n    }\n    friend\
    \ std::ostream& operator << (std::ostream &os, const mint& rhs) noexcept { return\
    \ os << rhs.v; }\n};\nusing mint61 = modint61<2305843009213693951>;\n#line 6 \"\
    Test/Aizu Online Judge/ALDS1/ALDS1_14_C.test.cpp\"\n\nusing namespace std;\n\n\
    int main() {\n    ios::sync_with_stdio(false);\n    cin.tie(0);\n    int h, w;\n\
    \    cin >> h >> w;\n    vector<mint61> Y(1001), X(1001);\n    Y[0] = X[0] = 1;\n\
    \    for(int y = 0; y < 1000; y++){\n        Y[y + 1] = Y[y] * 334;\n    }\n \
    \   for(int x = 0; x < 1000; x++){\n        X[x + 1] = X[x] * 114514;\n    }\n\
    \    CumulativeSum2D<mint61> A(h, w);\n    for(int y = 0; y < h; y++){\n     \
    \   string s;\n        cin >> s;\n        for(int x = 0; x < w; x++){\n      \
    \      A.add(y, x, Y[y] * X[x] * s[x]);\n        }\n    }\n    A.build();\n\n\
    \    int h2, w2;\n    mint61 hash;\n    cin >> h2 >> w2;\n    for(int y = 0; y\
    \ < h2; y++){\n        string s;\n        cin >> s;\n        for(int x = 0; x\
    \ < w2; x++){\n            hash += Y[y] * X[x] * s[x];\n        }\n    }\n\n \
    \   for(int y = 0; y + h2 <= h; y++){\n        for(int x = 0; x + w2 <= w; x++){\n\
    \            if(hash * Y[y] * X[x] == A.query(y, x, y + h2, x + w2)){\n      \
    \          cout << y << ' ' << x << '\\n';\n            }\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_C\"\n\
    \n#include <bits/stdc++.h>\n#include \"DataStructure/CumulativeSum2D.hpp\"\n#include\
    \ \"Math/modint_61bit.hpp\"\n\nusing namespace std;\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(0);\n    int h, w;\n    cin >> h >> w;\n    vector<mint61> Y(1001),\
    \ X(1001);\n    Y[0] = X[0] = 1;\n    for(int y = 0; y < 1000; y++){\n       \
    \ Y[y + 1] = Y[y] * 334;\n    }\n    for(int x = 0; x < 1000; x++){\n        X[x\
    \ + 1] = X[x] * 114514;\n    }\n    CumulativeSum2D<mint61> A(h, w);\n    for(int\
    \ y = 0; y < h; y++){\n        string s;\n        cin >> s;\n        for(int x\
    \ = 0; x < w; x++){\n            A.add(y, x, Y[y] * X[x] * s[x]);\n        }\n\
    \    }\n    A.build();\n\n    int h2, w2;\n    mint61 hash;\n    cin >> h2 >>\
    \ w2;\n    for(int y = 0; y < h2; y++){\n        string s;\n        cin >> s;\n\
    \        for(int x = 0; x < w2; x++){\n            hash += Y[y] * X[x] * s[x];\n\
    \        }\n    }\n\n    for(int y = 0; y + h2 <= h; y++){\n        for(int x\
    \ = 0; x + w2 <= w; x++){\n            if(hash * Y[y] * X[x] == A.query(y, x,\
    \ y + h2, x + w2)){\n                cout << y << ' ' << x << '\\n';\n       \
    \     }\n        }\n    }\n}\n"
  dependsOn:
  - DataStructure/CumulativeSum2D.hpp
  - Math/modint_61bit.hpp
  isVerificationFile: true
  path: Test/Aizu Online Judge/ALDS1/ALDS1_14_C.test.cpp
  requiredBy: []
  timestamp: '2023-06-22 23:15:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Aizu Online Judge/ALDS1/ALDS1_14_C.test.cpp
layout: document
redirect_from:
- /verify/Test/Aizu Online Judge/ALDS1/ALDS1_14_C.test.cpp
- /verify/Test/Aizu Online Judge/ALDS1/ALDS1_14_C.test.cpp.html
title: Test/Aizu Online Judge/ALDS1/ALDS1_14_C.test.cpp
---
