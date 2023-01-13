from itertools import combinations

n = int(input())
a = list(map(int, input().split()))

for comb in combinations(a, 6):
    for val in comb:
        print(val, end=" ")
    print()
