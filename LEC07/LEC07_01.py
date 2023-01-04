n, m = map(int, input().split())
arr = (list(map(int, input().split())))
dp = [0] * n
dp[0] = arr[0]
for i in range(1, n):
    dp[i] = dp[i - 1] + arr[i]
for i in range(m):
    a, b = map(int, input().split())
    if a == 0:
        print(dp[b])
    else:
        print(dp[b] - dp[a-1])
