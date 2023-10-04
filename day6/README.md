# 第六天
| 笔记信息 |  |
|----|----|
| 作者 | [Gingmzmzx](https://github.com/Gingmzmzx) |
| 时间 | 2023-10-4 |
| 教师 | 张尊喆、钟皓曦 |

膜拜24班dalao _杨昊臻_
![](images/IMG_20231004_143331.jpg)

## 上午
### 参见[10.4上午.pdf](10.4上午.pdf)

## 下午
膜拜新老师 _钟皓曦_  
![Alt text](images/3A0997DFBD09B0F6A8309FE71166733F.jpg)  

课件：[n42.pdf](n42.pdf)

### 一、矩阵
- 简单理解：n行，m列的数组
- 运算
    - 加/减
        对应位置相加/减即可
    - 乘/除
        对于$A \times B = C$，其中
        - $A$：$n$行$m$列
        - $B$：$j$行$k$列
        - $C$：$n$行$k$列

        必须满足条件
        - $m = j$
        - $C$的行数为$A$的行数，列数为$B$的列数

        对于$C$中的第$a$行第$b$列的数，取出$A$矩阵的第$a$行，$B$矩阵的第$b$列，对应位置相乘，然后相加。

        举个栗子：
        $$
        \begin{bmatrix}
            1 & 2 \\
            3 & 4 \\
        \end{bmatrix} \times
        \begin{bmatrix}
            1 & 2 & 3 \\
            4 & 5 & 6 \\
        \end{bmatrix} =
        \begin{bmatrix}
            9 & 12 & 15 \\
            19 & 26 & 33 \\
        \end{bmatrix}
        $$

### 二、基本计数原理
$C(n, m) = \frac{n(n-1)(n-2)...(n-m+1)}{m!} = \frac{n!}{(n-m)!m!} \\
C(n, m) = C(n-1, m-1) + C(n-1, m)$

接下来与信息学结合一下
#### 例题
- 题目描述：  
    已知$n, m, p$，求$C(n, m)\ \%\ P$
- 图解：  
    ![](images/IMG_20231004_154701.jpg)

### 三、逆元
定义：在模意义下，一个数$N$，有$N \div a = N \times a^{P-2}$

### 四、概率和期望
- 概率：  
    $P(A) = \frac{A出现的次数}{总次数}$
- 期望：
    - 类型：
        - 离散型：  
            $E(X) = \sum_{i=1}^n x_i \times P(x_i)$
        - 连续型：  
            $E(X) = \int_{-\infty}^{+\infty} x \times f(x) dx$
    - 性质：
        - $E(x_1 + x_2) = E(x_1) + E(x_2)$
        - $E(ax) = aE(x)$
        - $E(x_1 \times x_2) = E(x_1) \times E(x_2)$
        - $E(x^2) = E(x)^2 + D(x)$
        - $D(x) = E(x^2) - E(x)^2$
        - $D(ax) = a^2D(x)$
        - $D(x_1 + x_2) = D(x_1) + D(x_2)$
        - $D$是什么？
            - $D$是方差，表示随机变量的离散程度
            - $D(x) = \sum_{i=1}^n (x_i - E(x))^2 \times P(x_i)$
            - $D(x) = \int_{-\infty}^{+\infty} (x - E(x))^2 \times f(x) dx$