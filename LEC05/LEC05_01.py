n = int(input())
h = list(map(int, input().split()))
avg = sum(h) / n
cnt = 0
for i in h:
    if i > avg:
        cnt += (i - avg)
print(int(cnt))
