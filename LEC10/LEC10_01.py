a, b, c = map(int, input().split())

sol = False
for x in range(0, 10001):
    for y in range(0, 10001):
        for z in range(0, 10001):
            if set([x, y, z]) != 3:
                continue
            if x + y + z == a and x * y * z == b and x ** 2 + y ** 2 + z ** 2 == c:
                sol = True
                break
        if sol:
            break
    if sol:
        break

if not sol:
    print("No solution.")
