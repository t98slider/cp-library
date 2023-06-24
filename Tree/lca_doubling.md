---
title: 最小共通祖先 (LCA, Lowest Common Ancestor) (タブリング)
documentation_of: ./lca_doubling.hpp
---

## 概要
構築 $\text{O}(N\log N)$ 、クエリ $\text{O}(\log N)$ で最小共通祖先 (Lowest Common Ancestor) を習得できるライブラリである。<br>
実装はDFSの行きがけ順のみを使用していて場合分けを簡潔にしている。<br>

|関数名など|機能|計算量|
|---------|----|-----|
|`LCA_tree(std::vector<std::vector<int>> G, int root)`|`root` を根とする LCA のダブリングテーブルを構築する。<br>・第1引数には無向辺の木もしくは根付き木を G としてコンストラクタに渡す。<br>・第2引数は省略可能。省略した場合 `0` を根とする。| $\text{O}(N\log N)$ |
|`int lca(int u, int v)`|頂点 $u$ と頂点 $v$ のLCAを返す。| $\text{O}(\log N)$ |
|`int la(int v, int d)`|頂点 $v$ から根に向かって距離 $d$ を進んだ頂点を返す。存在しない場合は `-1` を返す。| $\text{O}(\log N)$ |
|`int dist(int u, int v)`|頂点 $u$ と頂点 $v$ の距離を出力する。| $\text{O}(\log N)$ |
|`bool on_path(int u, int v, int w)`|頂点 $w$ が頂点 $u$ と頂点 $v$ の単純パス上にあるかを判定する。| $\text{O}(\log N)$ |
|`int min_edge(std::vector<int> ver)`|頂点集合 $\text{ver}$ を連結にするために必要な辺の数を出力する。|頂点集合の大きさを $\|S\|$ として<br> $\text{O}(\|S\|\log N)$|
