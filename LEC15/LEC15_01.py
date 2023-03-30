a = input()
b = input()
a = a.lower()
b = b.lower()
max_length = max(len(a), len(b))
dp = [[0 for _ in range(len(b)+1)] for _ in range(len(a)+1)]

for i in range(0, len(a)+1):
    for j in range(0, len(b)+1):
        if i == 0:
            dp[i][j] = j
        elif j == 0:
            dp[i][j] = i
        elif a[i-1] == b[j-1]:
            dp[i][j] = dp[i-1][j-1]
        else:
            dp[i][j] = min(
                dp[i-1][j],
                dp[i][j-1],
                dp[i-1][j-1]
            ) + 1

edit = dp[len(a)][len(b)]
isSub = (max(len(a), len(b))+1) // 2

if edit < isSub:
    print(edit, 1)
else:
    print(edit, 0)
