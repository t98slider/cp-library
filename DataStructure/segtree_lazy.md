---
title: 遅延評価セグメント木
documentation_of: ./segtree_lazy.hpp
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
|`fenwick_tree<T>(int N)`| 宣言.  $N$ 個の要素をもつ配列を作る．初期値は0．<br> `T` は `+` と `-` が定義されている構造体を載せることができる。| $\text{O}(N)$ |
|`void add(int p, T x)`| $a[p] += x$ を行う.  $0 \leq p < N$ | $\text{O}(\log N)$|
|`T sum(int l, int r)`| $a[l] + a[l - 1] + \cdots + a[r - 1]$  を返す。 $0 \leq l \leq r < N$ | $\text{O}(\log N)$ |
