def countWays(N, K, a):
    # 初始化dp数组
    dp = [[0] * (K+1) for _ in range(N+1)]
    # 初始化max_taste和min_taste数组
    max_taste = [-float('inf')] * (K+1)
    min_taste = [float('inf')] * (K+1)

    # 初始化边界条件
    dp[0][0] = 1
    max_taste[0] = float('inf')
    min_taste[0] = -float('inf')

    # 遍历糖果
    for i in range(1, N+1):
        # 更新max_taste和min_taste数组
        for j in range(K, 0, -1):
            max_taste[j] = max(max_taste[j], a[i-1])
            min_taste[j] = min(min_taste[j], a[i-1])
        # 更新dp数组
        for j in range(1, K+1):
            # 选择第i颗糖
            if a[i-1] > max_taste[j-1]:
                dp[i][j] += dp[i-1][j-1]
            # 不选择第i颗糖
            dp[i][j] += dp[i-1][j]

    return dp[N][K]

if __name__ == '__main__':
    N, K = input().split()
    N, K = int(N), int(K)
    a = list(map(int, input().split()))
    print(countWays(N, K, a))