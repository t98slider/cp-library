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
  bundledCode: "#line 1 \"DataStructure/segtree_lazy.hpp\"\ntemplate <class S,\n \
    \           S (*op)(S, S),\n            S (*e)(),\n            class F,\n    \
    \        S (*mapping)(F, S),\n            F (*composition)(F, F),\n          \
    \  F (*id)()>\nstruct lazy_segtree {\n    public:\n    lazy_segtree() : lazy_segtree(0)\
    \ {}\n    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}\n    lazy_segtree(const\
    \ std::vector<S>& v) : _n(int(v.size())) {\n        log = ceil_pow2(_n);\n   \
    \     size = 1 << log;\n        d = std::vector<S>(2 * size, e());\n        lz\
    \ = std::vector<F>(size, id());\n        for (int i = 0; i < _n; i++) d[size +\
    \ i] = v[i];\n        for (int i = size - 1; i >= 1; i--) {\n            update(i);\n\
    \        }\n    }\n    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n\
    \        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n  \
    \      d[p] = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n   \
    \ }\n    S get(int p) {\n        assert(0 <= p && p < _n);\n        p += size;\n\
    \        for (int i = log; i >= 1; i--) push(p >> i);\n        return d[p];\n\
    \    }\n    const S operator[](int p) const { return get(p); }\n    S operator[](int\
    \ p) { return get(p); }\n    S prod(int l, int r) {\n        assert(0 <= l &&\
    \ l <= r && r <= _n);\n        if (l == r) return e();\n        l += size;\n \
    \       r += size;\n        for (int i = log; i >= 1; i--) {\n            if (((l\
    \ >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r) push(r\
    \ >> i);\n        }\n        S sml = e(), smr = e();\n        while (l < r) {\n\
    \            if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1) smr = op(d[--r],\
    \ smr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ op(sml, smr);\n    }\n    S all_prod() { return d[1]; }\n    void apply(int\
    \ p, F f) {\n        assert(0 <= p && p < _n);\n        p += size;\n        for\
    \ (int i = log; i >= 1; i--) push(p >> i);\n        d[p] = mapping(f, d[p]);\n\
    \        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n    void apply(int\
    \ l, int r, F f) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l\
    \ == r) return;\n        l += size;\n        r += size;\n        for (int i =\
    \ log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n \
    \           if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n       \
    \ {\n            int l2 = l, r2 = r;\n            while (l < r) {\n          \
    \      if (l & 1) all_apply(l++, f);\n                if (r & 1) all_apply(--r,\
    \ f);\n                l >>= 1;\n                r >>= 1;\n            }\n   \
    \         l = l2;\n            r = r2;\n        }\n        for (int i = 1; i <=\
    \ log; i++) {\n            if (((l >> i) << i) != l) update(l >> i);\n       \
    \     if (((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n    template\
    \ <bool (*g)(S)> int max_right(int l) {\n        return max_right(l, [](S x) {\
    \ return g(x); });\n    }\n    template <class G> int max_right(int l, G g) {\n\
    \        assert(0 <= l && l <= _n);\n        assert(g(e()));\n        if (l ==\
    \ _n) return _n;\n        l += size;\n        for (int i = log; i >= 1; i--) push(l\
    \ >> i);\n        S sm = e();\n        do {\n            while (l % 2 == 0) l\
    \ >>= 1;\n            if (!g(op(sm, d[l]))) {\n                while (l < size)\
    \ {\n                    push(l);\n                    l = (2 * l);\n        \
    \            if (g(op(sm, d[l]))) {\n                        sm = op(sm, d[l]);\n\
    \                        l++;\n                    }\n                }\n    \
    \            return l - size;\n            }\n            sm = op(sm, d[l]);\n\
    \            l++;\n        } while ((l & -l) != l);\n        return _n;\n    }\n\
    \    template <bool (*g)(S)> int min_left(int r) {\n        return min_left(r,\
    \ [](S x) { return g(x); });\n    }\n    template <class G> int min_left(int r,\
    \ G g) {\n        assert(0 <= r && r <= _n);\n        assert(g(e()));\n      \
    \  if (r == 0) return 0;\n        r += size;\n        for (int i = log; i >= 1;\
    \ i--) push((r - 1) >> i);\n        S sm = e();\n        do {\n            r--;\n\
    \            while (r > 1 && (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm)))\
    \ {\n                while (r < size) {\n                    push(r);\n      \
    \              r = (2 * r + 1);\n                    if (g(op(d[r], sm))) {\n\
    \                        sm = op(d[r], sm);\n                        r--;\n  \
    \                  }\n                }\n                return r + 1 - size;\n\
    \            }\n            sm = op(d[r], sm);\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n    private:\n    int _n, size, log;\n    std::vector<S>\
    \ d;\n    std::vector<F> lz;\n    void update(int k) { d[k] = op(d[2 * k], d[2\
    \ * k + 1]); }\n    void all_apply(int k, F f) {\n        d[k] = mapping(f, d[k]);\n\
    \        if (k < size) lz[k] = composition(f, lz[k]);\n    }\n    void push(int\
    \ k) {\n        all_apply(2 * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n\
    \        lz[k] = id();\n    }\n    int ceil_pow2(int n) {\n        int x = 0;\n\
    \        while ((1U << x) < (unsigned int)(n)) x++;\n        return x;\n    }\n\
    };\n"
  code: "template <class S,\n            S (*op)(S, S),\n            S (*e)(),\n \
    \           class F,\n            S (*mapping)(F, S),\n            F (*composition)(F,\
    \ F),\n            F (*id)()>\nstruct lazy_segtree {\n    public:\n    lazy_segtree()\
    \ : lazy_segtree(0) {}\n    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n,\
    \ e())) {}\n    lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {\n\
    \        log = ceil_pow2(_n);\n        size = 1 << log;\n        d = std::vector<S>(2\
    \ * size, e());\n        lz = std::vector<F>(size, id());\n        for (int i\
    \ = 0; i < _n; i++) d[size + i] = v[i];\n        for (int i = size - 1; i >= 1;\
    \ i--) {\n            update(i);\n        }\n    }\n    void set(int p, S x) {\n\
    \        assert(0 <= p && p < _n);\n        p += size;\n        for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n        d[p] = x;\n        for (int i = 1; i <=\
    \ log; i++) update(p >> i);\n    }\n    S get(int p) {\n        assert(0 <= p\
    \ && p < _n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p\
    \ >> i);\n        return d[p];\n    }\n    const S operator[](int p) const { return\
    \ get(p); }\n    S operator[](int p) { return get(p); }\n    S prod(int l, int\
    \ r) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return\
    \ e();\n        l += size;\n        r += size;\n        for (int i = log; i >=\
    \ 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n           \
    \ if (((r >> i) << i) != r) push(r >> i);\n        }\n        S sml = e(), smr\
    \ = e();\n        while (l < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n\
    \            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n       \
    \     r >>= 1;\n        }\n        return op(sml, smr);\n    }\n    S all_prod()\
    \ { return d[1]; }\n    void apply(int p, F f) {\n        assert(0 <= p && p <\
    \ _n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n\
    \        d[p] = mapping(f, d[p]);\n        for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n    }\n    void apply(int l, int r, F f) {\n        assert(0 <= l &&\
    \ l <= r && r <= _n);\n        if (l == r) return;\n        l += size;\n     \
    \   r += size;\n        for (int i = log; i >= 1; i--) {\n            if (((l\
    \ >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n        }\n        {\n            int l2 = l, r2 = r;\n       \
    \     while (l < r) {\n                if (l & 1) all_apply(l++, f);\n       \
    \         if (r & 1) all_apply(--r, f);\n                l >>= 1;\n          \
    \      r >>= 1;\n            }\n            l = l2;\n            r = r2;\n   \
    \     }\n        for (int i = 1; i <= log; i++) {\n            if (((l >> i) <<\
    \ i) != l) update(l >> i);\n            if (((r >> i) << i) != r) update((r -\
    \ 1) >> i);\n        }\n    }\n    template <bool (*g)(S)> int max_right(int l)\
    \ {\n        return max_right(l, [](S x) { return g(x); });\n    }\n    template\
    \ <class G> int max_right(int l, G g) {\n        assert(0 <= l && l <= _n);\n\
    \        assert(g(e()));\n        if (l == _n) return _n;\n        l += size;\n\
    \        for (int i = log; i >= 1; i--) push(l >> i);\n        S sm = e();\n \
    \       do {\n            while (l % 2 == 0) l >>= 1;\n            if (!g(op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    push(l);\n\
    \                    l = (2 * l);\n                    if (g(op(sm, d[l]))) {\n\
    \                        sm = op(sm, d[l]);\n                        l++;\n  \
    \                  }\n                }\n                return l - size;\n  \
    \          }\n            sm = op(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return _n;\n    }\n    template <bool (*g)(S)> int\
    \ min_left(int r) {\n        return min_left(r, [](S x) { return g(x); });\n \
    \   }\n    template <class G> int min_left(int r, G g) {\n        assert(0 <=\
    \ r && r <= _n);\n        assert(g(e()));\n        if (r == 0) return 0;\n   \
    \     r += size;\n        for (int i = log; i >= 1; i--) push((r - 1) >> i);\n\
    \        S sm = e();\n        do {\n            r--;\n            while (r > 1\
    \ && (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm))) {\n                while\
    \ (r < size) {\n                    push(r);\n                    r = (2 * r +\
    \ 1);\n                    if (g(op(d[r], sm))) {\n                        sm\
    \ = op(d[r], sm);\n                        r--;\n                    }\n     \
    \           }\n                return r + 1 - size;\n            }\n         \
    \   sm = op(d[r], sm);\n        } while ((r & -r) != r);\n        return 0;\n\
    \    }\n    private:\n    int _n, size, log;\n    std::vector<S> d;\n    std::vector<F>\
    \ lz;\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n    void\
    \ all_apply(int k, F f) {\n        d[k] = mapping(f, d[k]);\n        if (k < size)\
    \ lz[k] = composition(f, lz[k]);\n    }\n    void push(int k) {\n        all_apply(2\
    \ * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n        lz[k] = id();\n\
    \    }\n    int ceil_pow2(int n) {\n        int x = 0;\n        while ((1U <<\
    \ x) < (unsigned int)(n)) x++;\n        return x;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/segtree_lazy.hpp
  requiredBy: []
  timestamp: '2023-06-23 15:05:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/segtree_lazy.hpp
layout: document
title: "\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---

## 概要
遅延評価セグメント木はモノイド $(S, \cdot: S \times S \to S, e \in S)$ と， $S$ から $S$ への写像の集合 $F$ であって，以下の条件を満たすようなものについて使用できるデータ構造である．
- $F$ は恒等写像 $\mathrm{id}$ を含む．つまり，任意の $x \in S$ に対し $\mathrm{id}(x) = x$ をみたす．
- $F$ は写像の合成について閉じている．つまり，任意の $f, g \in F$ に対し $f \circ g \in F$ である．
- 任意の $f \in F, x, y \in S$ に対し $f(x \cdot y) = f(x) \cdot f(y)$ をみたす．

長さ $N$ の $S$ の配列に対し、<br>

- 区間の要素に一括で $F$ の要素\(f\)を作用 ( $x = f(x)$ )
- 区間の要素の総積の取得

を $\text{O}(\log N)$ で行うことが出来る．<br>

また，このライブラリはオラクルとしてop, e, mapping, composition, idを使用するが、これらが定数時間で動くものと仮定したときの計算量を記述する．オラクル内部の計算量が $\text{O}(f(n))$ である場合はすべての計算量が $O(f(n))$ 倍となる．<br>

テンプレート引数の例 (区間min演算・区間min更新)。適宜書き換えて使用する。
```
// lazy_segtree<S, op, e, F, mapping, composition, id> seg(200000);

using S = int;
using F = int;
// 単位元
S e(){return 1 << 30;}
// 区間演算
S op(S lhs, S rhs){ return min(lhs, rhs); }
// x に f を作用させた時の変化
S mapping(F f, S x){return min(x, f);}
// bf を作用させた後に af を作用させる
F composition(F af, F bf){return min(af, bf);}
// 恒等写像
F id(){return 1 << 30;}
```

|関数名など|機能|計算量|
|---------|----|-----|
|(1) `lazy_segtree<S, op, e, F, mapping, composition, id>(int N)` <br>(2) ` lazy_segtree<S, op, e, F, mapping, composition, id>(std::vector<T> v)`|(1) 長さ $N$ の配列を作る。<br>(2) 長さ `v.size()` の配列を作る。`v` の内容が初期値になる。<br>・モノイドの型`S` <br>・ $\cdot: S \times S \to S$ を計算する関数 `S op(S a, S b)` <br>・ $e$ を返す関数 `S e()` <br>・写像の型 `F` <br>・ $f(x)$ を返す関数 `S mapping(F f, S x)` <br>・ $f \circ g$ を返す関数 `F composition(F f, F g)` <br>・ $id$ を返す関数 `F id()` <br> を定義する必要がある。| $\text{O}(N)$ |
