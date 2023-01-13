dp = [0] * 55


def kways(n):
    if n < 0:
        return 0
    if n == 0 or n == 1:
        return 1
    if dp[n] != 0:
        return dp[n]
    dp[n] = kways(n-1) + kways(n-3) + kways(n-4)
    return dp[n]


n = int(input())
print(kways(n))
