inp = input()
curr = []
for ch in inp:
    if len(curr) == 0:
        curr.append(ch)
    else:
        max_idx = curr.index(max(curr))
        if ch <= curr[max_idx]:
            curr[max_idx] = ch
        else:
            curr.append(ch)
print(len(curr))
