---
title: Union Find
documentation_of: ./dsu.hpp
---

## 概要
ほぼ AtCoder Library のパクリ。AtCoder Library に加えて連結成分数の取得ができるようにしてある。

| 関数名など   | 機能        | 計算量    |
| ------------|----------- | ------------- |
|`dsu(int N)`|宣言。 $N$ 頂点 $0$ 辺のグラフを作成する。 | $\text{O} (N)$ | 
|`int merge(int a, int b)`|頂点 $a$ と頂点 $b$ を辺で結ぶ。代表元の頂点番号を返す。 | $\text{O} (\alpha(N))$ | 
|`bool same(int a, int b)`|頂点 $a$ と頂点 $b$ が連結であるかを返す。 | $\text{O} (\alpha(N))$ | 
|`int leader(int a)`|頂点 $a$ の属する連結成分の代表元を返す。| $\text{O} (\alpha(N))$ | 
|`int size(void)`|現在の連結成分の数を返す。(int型であることに注意)| $\text{O} (1)$ | 
|`int size(int a)`|頂点 $a$ の属する連結成分のサイズを返す．| $\text{O} (\alpha(N))$ | 
|`std::vector<std::vector<int>> groups()`|グラフを連結成分に分けてその情報を返す． 返り値は「「一つの連結成分の頂点番号のリスト」のリスト」で， リスト内でどの順番で頂点が格納されているかは未定義である．| $\text{O} (N)$ |
