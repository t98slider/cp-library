---
title: セグメント木
documentation_of: ./segtree.hpp
---

## 概要
ほぼ AtCoder Library のパクリ。AtCoder Library に加えて`[id]` で値の収得ができるようにしてある。


|関数名など|機能|計算量|
|---------|----|-----|
|(1) `segtree<S, op, e>(int n)` <br> (2) `segtree<S, op, e>(std::vector<S> v)` | 型 `S` /二項演算 `S op(S a, S b)` /単位元 `S e()` を定義する必要がある．<br> (1) 長さ $n$ の配列を作る．初期値はe()となる．<br> (2) 長さ `v.size()` の配列を作る．`v` の内容が初期値となる. | $\text{O}(n)$ |
