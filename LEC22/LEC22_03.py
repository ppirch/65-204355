# tilling 2xN with tromino and domino (2x1)
n = int(input())
dp = [0] * (1000 + 1)
dp[0] = 1
dp[1] = 1
dp[2] = 2
dp[3] = 5
dp[4] = 11
for i in range(5, n + 1):
    dp[i] = 2 * dp[i - 1] + dp[i - 3]
print(dp[n] % (1000000007))
