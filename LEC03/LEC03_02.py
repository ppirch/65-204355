def gcd(a: int, b: int) -> int:
    if b == 0:
        return a
    return gcd(b, a % b)


arr = list(map(int, input().split()))
mx = -1
for i, a in enumerate(arr):
    for j, b in enumerate(arr):
        if j > i:
            mx = max(mx, gcd(a, b))
print(mx)
