---
title: ダブリングLCA
documentation_of: ./lca_doubling.hpp
---

## 概要
構築 $\test{O}(N\log N)$ 、クエリ $\text{O}(\log N)$ で最小共通祖先 (Lowest Common Ancestor) を習得できるライブラリである。<br>
実装はDFSの行きがけ順のみを使用していて場合分けを簡潔にしている。<br>

|関数名など|機能|計算量|
|---------|----|-----|
|`LCA_tree(std::vector<std::vector<int>> G, int root)`|`root` を根とする LCA のダブリングテーブルを構築する。<br>・第1引数には無向辺の木もしくは根付き木を G としてコンストラクタに渡す。<br>・第2引数は省略可能。省略した場合 `0` を根とする。| $\text{O}(N\log N)$ |
