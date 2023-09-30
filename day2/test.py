n = int(input())
shoes = list(map(int, input().split()))

# 统计左脚鞋和右脚鞋的数量
left_count = 0
right_count = 0
for shoe in shoes:
    if shoe < 0:
        left_count += 1
    else:
        right_count += 1

# 如果左右脚鞋的数量不相等，则无法构成合法排列
if left_count != right_count:
    print(-1)
else:
    # 统计需要对调的次数
    count = 0
    for i in range(n):
        left_shoe = shoes.index(-(i+1))
        right_shoe = shoes.index(i+1)
        # 如果左右脚鞋的位置编号差为奇数，则无法构成合法排列
        if abs(left_shoe - right_shoe) % 2 == 1:
            print(-1)
            break
        count += abs(left_shoe - right_shoe) // 2
    else:
        print(count)