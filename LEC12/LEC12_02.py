n = int(input())
arr = list(map(int, input().split()))
k = int(input())

arr = [0] + arr
dp = [0] * (100005)

dp[0] = 0
dp[1] = arr[1]


def maxProfit(k):
    if k < 0:
        return 0
    if dp[k] != 0:
        return dp[k]
    for i in range(1, k+1):
        dp[k] = max(dp[k], maxProfit(k-i) + arr[i])
    return dp[k]


print(maxProfit(k))
