n, t = map(int, input().split())
box = list(map(int, input().split()))
box = [-1] + box
for i in range(t):
    inp = input().split()
    if inp[0] == "1":
        a, b = map(int, inp[1:])
        if box[a] < b:
            box[a] += 1
    elif inp[0] == "2":
        a, b = map(int, inp[1:])
        if box[a] >= b:
            box[a] -= 1
    elif inp[0] == "3":
        a, b = map(int, inp[1:])
        curr = [0 for _ in box]
        if box[a] >= b:
            curr[a] += 1
        for x, y in zip((1, 0, -1, 1, -1, 1, 0, -1), (-1, -1, - 1, 0, 0, 1, 1, 1)):
            pos_x, pos_y = a + x, b + y
            if pos_x > 0 and pos_y > 0 and box[pos_x] > 0 and box[pos_x] >= pos_y:
                curr[pos_x] += 1
        for idx, c in enumerate(curr):
            box[idx] -= c
            box[idx] = max(box[idx], 0)
    elif inp[0] == "4":
        val = int(inp[1])
        curr = [0 for _ in box]
        for idx, h in enumerate(box):
            if h >= val:
                curr[idx] += 1
        for idx, c in enumerate(curr):
            box[idx] -= c
            box[idx] = max(box[idx], 0)
    print(" ".join([str(b) for b in box[1:]]))
