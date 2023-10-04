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

fi fi-1

1 1
1 0

fi+1 fi
