---
title: セグメント木
documentation_of: ./segtree.hpp
---

## 概要
Segment Tree は長さ $n$ の `S` 型の配列において、区間の1点変更、区間の要素の総積の習得を $\text{O}(\log n)$ で行えるデータ構造である．<br><br>
ほぼ AtCoder Library のパクリ。AtCoder Library に加えて`[id]` で値の収得ができるようにしてある。<br>


|関数名など|機能|計算量|
|---------|----|-----|
|(1) `segtree<S, op, e>(int n)` <br> (2) `segtree<S, op, e>(std::vector<S> v)` | 型 `S` /二項演算 `S op(S a, S b)` /単位元 `S e()` を定義する必要がある．<br> (1) 長さ $n$ の配列を作る．初期値は `e()` となる．<br> (2) 長さ `v.size()` の配列を作る．`v` の内容が初期値となる. | $\text{O}(n)$ |
| `void set(int p, S x)` | `a[p]` に `x` を代入する.   $0 \leq p < n$  | $\text{O}(\log n)$ |
|(1) `S get(int p)` <br> (2) `S [p]` | `a[p]` を返す.   $0 \leq p < n$  | $\text{O}(1)$ |
| `S prod(int l, int r)`| $\text{op}(a[l], \ldots, a[r - 1])$ をモノイドの性質を満たしていると仮定して計算する。<br> $l = r$ のときは、`e()` を返す。| $\text{O}(\log n)$ |
