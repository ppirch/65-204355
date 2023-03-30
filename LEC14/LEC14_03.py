from itertools import permutations
n, m = map(int, input().split())
st_x, st_y = map(int, input().split())
t = int(input())
points = []
for _ in range(t):
    x, y = map(int, input().split())
    points.append((x, y))


def dist(x1, y1, x2, y2):
    # Manhattan distance
    return abs(x1 - x2) + abs(y1 - y2)


# permutations of the points
perms = list(permutations(points))
mn = 2e9
for perm in perms:
    # start from the initial position
    x, y = st_x, st_y
    # calculate the total distance
    total_dist = 0
    for p in perm:
        total_dist += dist(x, y, p[0], p[1])
        x, y = p[0], p[1]
    total_dist += dist(x, y, st_x, st_y)
    # print the total distance
    mn = min(mn, total_dist)
print(mn)
