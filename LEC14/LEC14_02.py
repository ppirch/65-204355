n = int(input())
wt, val = [], []
for _ in range(n):
    p, w = [int(x) for x in input().split()]
    val.append(p)
    wt.append(w)
g = int(input())
fams = []
for _ in range(g):
    fams.append(int(input()))

sm = 0
for w in fams:
    dp = [[-1] * (w + 1) for _ in range(n + 1)]

    def solve(idx, w, dp):
        if idx == 0 or w == 0:
            return 0
        if dp[idx-1][w] != -1:
            return dp[idx-1][w]

        if wt[idx-1] > w:
            dp[idx-1][w] = solve(idx-1, w, dp)
            return dp[idx-1][w]

        dp[idx-1][w] = max(solve(idx - 1, w,  dp), val[idx-1] + solve(
            idx - 1, w - wt[idx-1], dp))
        return dp[idx-1][w]
    sm += solve(n, w, dp)
print(sm)
