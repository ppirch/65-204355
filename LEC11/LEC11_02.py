from itertools import combinations

n = int(input())
p = int(input())
arr = list(map(int, input().split()))

possible = set()
for k in range(1, p+1):
    for comb in combinations(arr, k):
        print(comb)
        s = 0
        for val in comb:
            s += val
        possible.add(s)

if n in possible:
    print("YES")
else:
    print("NO")
