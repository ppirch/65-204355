n = int(input())
if n == 0:
    print(0)
else:
    arr = []
    for _ in range(n):
        arr.append(int(input()))

    mx = max(arr)
    for i in range(n):
        for j in range(i+1, n):
            mx = max(mx, sum(arr[i:j+1]))
    mx = max(mx, 0)
    print(mx)
