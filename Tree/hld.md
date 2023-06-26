---
title: HL分解 (HLD, Heavy-Light-Decomposition)
documentation_of: ./hld.hpp
---

## 概要
HL分解 (HLD, Heavy-Light-Decomposition) を行うためのライブラリ。<br>
それぞれの頂点に対して、 子の頂点のうち部分木の頂点数が最も大きい頂点を1つ選択して Heavy Edge で結ぶことで $\log N$ 個程度のパスに分解でき、パスの更新クエリに対して高速に処理できる。<br>
<a href = "https://ei1333.github.io/luzhiled/snippets/tree/heavy-light-decomposition.html"> HL分解(Heavy-Light-Decomposition) | Luzhiled's memo </a> をかなり参考にした。<br>

| 関数名など   | 機能        | 計算量    |
| ------------|----------- | --------- |
|`Heavy_Light_Decomposition(std::vector<std::vector<int>> g)`| コンストラクタに木を渡すと、HL分解される。| $\text{O} (N)$ | 
