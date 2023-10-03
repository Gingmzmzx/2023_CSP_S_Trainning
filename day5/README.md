# 第五天
| 笔记信息 |  |
|----|----|
| 作者 | [Gingmzmzx](https://github.com/Gingmzmzx) |
| 时间 | 2023-10-2 |
| 教师 | 张尊喆 |

## 日常膜拜
- 新老师：  
    ![](images/IMG_20231003_083543.jpg)
- 523大佬：  
    ![](images/IMG_6191.JPG)

## 上午

### 一、并查集
#### 启发式合并
启发式合并 + 路径压缩$O(m \alpha )$

不使用启发式合并、只使用路径压缩的最坏时间复杂度是$O(m log n)$。不使用启发式合并、只使用路径压缩，在平均情况下，时间复杂度依然是$O(m \alpha (m, n))$。

如果只使用启发式合并，而不使用路径压缩，时间复杂度为$O(m log n)$。由于路径压缩单次合并可能造成大量修改，有时路径压缩并不适合使用。例如，在可持久化并查集、线段树分治 + 并查集中，一般使用只启发式合并的并查集。

#### \# [P5937 Parity Game](https://www.luogu.com.cn/problem/P5937) 带权并查集 / 种类并查集
转化为前缀和，每次询问相当于得知 $S[r]$ 和 $S[l-1]$ 是否是同奇同偶。种类并查集，或者带权并查集。

种类并查集：对于每个位置建立两个点 $i$, $i + n$ 分别代表，$S[r]$ 为奇，$S[l-1]$ 为偶。得知两个位置同奇同偶，那么 $i$ 和 $j$ 连，$i + n$ 和 $j + n$ 连，否则 $i$ 和 $j + n$ 连，$j$ 和 $i + n$连。一个集合内部的布尔变量相同，当 $i$ 和 $i + n$ 在同一集合时矛盾。

带权并查集：相等连一条权值为 $0$ 的边，否则连一条权值为 $1$ 的边，要求两个点的路径异或和要么都为 $1$ （奇偶性不同），要么都为 $0$（奇偶性相同）。实现时维护到达集合代表点的距离即可。

#### \# [P6185 序列](https://www.luogu.com.cn/problem/P6185) 带权并查集 & 二分图
把每个位置看成一个点。

首先对于 $2$ 操作连边。每次操作可以在一个连通块内部任选一个点加一，任选一个点减一。

再对于 $1$ 操作连边。

如果形成的图是二分图，则可以在保证左部点总和与右部点总和的差不变的情况下任意的加减。

如果形成的图不是二分图，则可以在保证总和奇偶性不变的情况下任意的加减。

#### \# [P2391 白雪皑皑](https://www.luogu.com.cn/problem/P2391) 序列并查集
倒序操作，需要支持将区间没有染色的地方染色。

并查集：暴力染色，并删除染过的地方。令 $f[i]$ 从 $i$ 开始第一个没有染色的地方。染色后将 $f[i]$ 设置为 $f[i] + 1$，利用并查集维护。

#### \# [P1640 连续攻击游戏](https://www.luogu.com.cn/problem/P1640) 建图分析


#### \# [CF571D Campus](https://www.luogu.com.cn/problem/CF571D) 启发式并查集

### 二、最小生成树
#### \# [P1396 营救](https://www.luogu.com.cn/problem/P1396) 最小生成树思想

#### \# [CF1245D Shichikuji and Power Grid](https://www.luogu.com.cn/problem/CF1245D) 建图

#### \# [P8074 SVEMIR](https://www.luogu.com.cn/problem/P8074) 去除冗边

#### \# [P8207 最小公倍树](https://www.luogu.com.cn/problem/P8207) 去除冗边

#### \# [P5994 Kuglarz](https://www.luogu.com.cn/problem/P5994) （思维题）

#### \# [P1967 货车运输](https://www.luogu.com.cn/problem/P1967)

#### \# [P4180 严格次小生成树](https://www.luogu.com.cn/problem/P4180)

#### \# [CF827D Best Edge Weight](https://www.luogu.com.cn/problem/CF827D)

#### \# [P4667]

#### \# [P1462 通往奥格瑞玛的道路](https://www.luogu.com.cn/problem/P1462)

## 下午

### 一、图论
#### \# [P1144 最短路计数](https://www.luogu.com.cn/problem/P1144)

#### \# [P1119 灾后重建](https://www.luogu.com.cn/problem/P1119) Floyd理解

#### \# [P4822 冻结](https://www.luogu.com.cn/problem/P4822) （分层图）

#### \# [P]()

#### \# [P]()

#### \# [P]()

#### \# [P]()

#### \# [P]()