n, m = map(int, input().split())

if n < m:
    print(1)
    exit()

dp = [0] * (n + 1)
dp[0] = 1
dp[1] = 1
for i in range(2, n + 1):
    if i < m:
        dp[i] = 1
    elif i == m:
        dp[i] = 2
    else:
        dp[i] = dp[i - 1] + dp[i - m]

print(dp[n])
