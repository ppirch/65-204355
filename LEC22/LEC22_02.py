T = int(input())
N = 30
dp = [0] * (N + 1)
dp[0] = 1
dp[1] = 0
dp[2] = 3
dp[3] = 0
dp[4] = 11
for i in range(5, N + 1):
    dp[i] = 4 * dp[i - 2] - dp[i - 4]
for _ in range(T):
    n = int(input())
    print(dp[n])
