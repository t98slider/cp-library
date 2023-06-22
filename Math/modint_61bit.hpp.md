---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/Aizu Online Judge/ALDS1/ALDS1_14_C.test.cpp
    title: Test/Aizu Online Judge/ALDS1/ALDS1_14_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/modint_61bit.hpp\"\ntemplate<const long long MOD =\
    \ 2305843009213693951, \n        const long long MASK31 = (1ll << 31) - 1, const\
    \ long long MASK30 = (1ll << 30) - 1>\nstruct modint61 {\n    using mint = modint61;\n\
    \    long long v;\n    modint61() : v(0) {}\n    template<class T> modint61(T\
    \ x) { \n        while(x < 0) x += MOD;\n        while(x >= MOD) x -= MOD;\n \
    \       v = x;\n    }\n    long long safe_mod(long long x){\n        x = (x >>\
    \ 61) + (x & MOD);\n        if (x >= MOD) x -= MOD;\n        return x;\n    }\n\
    \    static constexpr long long mod() { return MOD; }\n    mint& operator++()\
    \ {v++; if(v == MOD)v = 0; return *this;}\n    mint& operator--() {if(v == 0)v\
    \ = MOD; v--; return *this;}\n    mint operator++(int) { mint result = *this;\
    \ ++*this; return result; }\n    mint operator--(int) { mint result = *this; --*this;\
    \ return result; }\n    mint& operator+=(const mint& rhs) { v += rhs.v; if(v >=\
    \ MOD) v -= MOD; return *this; }\n    mint& operator-=(const mint& rhs) { if(v\
    \ < rhs.v) v += MOD; v -= rhs.v; return *this; }\n    mint& operator*=(const mint&\
    \ rhs) {\n        long long u = v >> 31, d = v & MASK31;\n        long long ru\
    \ = rhs.v >> 31, rd = rhs.v & MASK31;\n        long long mid = d * ru + u * rd;\n\
    \        v = safe_mod(u * ru * 2 + (mid >> 30) + ((mid & MASK30) << 31) + d *\
    \ rd);\n        return *this;\n    }\n    mint& operator/=(const mint& rhs) {\
    \ return *this = *this * rhs.inv(); }\n    mint operator+() const { return *this;\
    \ }\n    mint operator-() const { return mint() - *this; }\n    mint pow(long\
    \ long n) const {\n        assert(0 <= n);\n        mint r = 1, x = *this;\n \
    \       while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n   \
    \         n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const\
    \ { assert(v); return pow(MOD - 2); }\n    friend mint operator+(const mint& lhs,\
    \ const mint& rhs) { return mint(lhs) += rhs; }\n    friend mint operator-(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }\n    friend bool operator<(const\
    \ mint& lhs, const mint& rhs) { return lhs.v < rhs.v; }\n    friend bool operator==(const\
    \ mint& lhs, const mint& rhs) { return (lhs.v == rhs.v); }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return (lhs.v != rhs.v); }\n    friend std::istream&\
    \ operator >> (std::istream& is, mint& rhs) noexcept {\n        long long tmp;\n\
    \        rhs = mint{(is >> tmp, tmp)};\n        return is;\n    }\n    friend\
    \ std::ostream& operator << (std::ostream &os, const mint& rhs) noexcept { return\
    \ os << rhs.v; }\n};\nusing mint61 = modint61<2305843009213693951>;\n"
  code: "template<const long long MOD = 2305843009213693951, \n        const long\
    \ long MASK31 = (1ll << 31) - 1, const long long MASK30 = (1ll << 30) - 1>\nstruct\
    \ modint61 {\n    using mint = modint61;\n    long long v;\n    modint61() : v(0)\
    \ {}\n    template<class T> modint61(T x) { \n        while(x < 0) x += MOD;\n\
    \        while(x >= MOD) x -= MOD;\n        v = x;\n    }\n    long long safe_mod(long\
    \ long x){\n        x = (x >> 61) + (x & MOD);\n        if (x >= MOD) x -= MOD;\n\
    \        return x;\n    }\n    static constexpr long long mod() { return MOD;\
    \ }\n    mint& operator++() {v++; if(v == MOD)v = 0; return *this;}\n    mint&\
    \ operator--() {if(v == 0)v = MOD; v--; return *this;}\n    mint operator++(int)\
    \ { mint result = *this; ++*this; return result; }\n    mint operator--(int) {\
    \ mint result = *this; --*this; return result; }\n    mint& operator+=(const mint&\
    \ rhs) { v += rhs.v; if(v >= MOD) v -= MOD; return *this; }\n    mint& operator-=(const\
    \ mint& rhs) { if(v < rhs.v) v += MOD; v -= rhs.v; return *this; }\n    mint&\
    \ operator*=(const mint& rhs) {\n        long long u = v >> 31, d = v & MASK31;\n\
    \        long long ru = rhs.v >> 31, rd = rhs.v & MASK31;\n        long long mid\
    \ = d * ru + u * rd;\n        v = safe_mod(u * ru * 2 + (mid >> 30) + ((mid &\
    \ MASK30) << 31) + d * rd);\n        return *this;\n    }\n    mint& operator/=(const\
    \ mint& rhs) { return *this = *this * rhs.inv(); }\n    mint operator+() const\
    \ { return *this; }\n    mint operator-() const { return mint() - *this; }\n \
    \   mint pow(long long n) const {\n        assert(0 <= n);\n        mint r = 1,\
    \ x = *this;\n        while (n) {\n            if (n & 1) r *= x;\n          \
    \  x *= x;\n            n >>= 1;\n        }\n        return r;\n    }\n    mint\
    \ inv() const { assert(v); return pow(MOD - 2); }\n    friend mint operator+(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }\n    friend mint operator-(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }\n    friend bool operator<(const\
    \ mint& lhs, const mint& rhs) { return lhs.v < rhs.v; }\n    friend bool operator==(const\
    \ mint& lhs, const mint& rhs) { return (lhs.v == rhs.v); }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return (lhs.v != rhs.v); }\n    friend std::istream&\
    \ operator >> (std::istream& is, mint& rhs) noexcept {\n        long long tmp;\n\
    \        rhs = mint{(is >> tmp, tmp)};\n        return is;\n    }\n    friend\
    \ std::ostream& operator << (std::ostream &os, const mint& rhs) noexcept { return\
    \ os << rhs.v; }\n};\nusing mint61 = modint61<2305843009213693951>;\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/modint_61bit.hpp
  requiredBy: []
  timestamp: '2023-06-21 17:57:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Aizu Online Judge/ALDS1/ALDS1_14_C.test.cpp
documentation_of: Math/modint_61bit.hpp
layout: document
redirect_from:
- /library/Math/modint_61bit.hpp
- /library/Math/modint_61bit.hpp.html
title: Math/modint_61bit.hpp
---
