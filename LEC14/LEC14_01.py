def solve(arr, idx, sm, dp):
    if sm == 0:
        return 1
    if idx == 0 and sm != 0:
        return 0
    if dp[idx][sm] != -1:
        return dp[idx][sm]

    if arr[idx] > sm:
        dp[idx][sm] = solve(arr, idx - 1, sm, dp)
        return dp[idx][sm]

    dp[idx][sm] = solve(arr, idx - 1, sm, dp) or solve(arr,
                                                       idx - 1, sm - arr[idx], dp)
    return dp[idx][sm]


n = int(input())
arr = [int(x) for x in input().split()]

sm = sum(arr)
dp = [[-1] * (sm + 1) for _ in range(n + 1)]

if sm % 2 != 0:
    print("NO")
else:
    print("YES" if solve(arr, n - 1, sm//2, dp) else "NO")
