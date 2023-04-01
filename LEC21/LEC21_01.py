from collections import deque

source = ord("+")
sink = ord("-")
g = [[] for _ in range(256)]


def bfs():
    prev = [-1] * 256
    prev[source] = -2
    q = deque()
    q.append(source)
    while q:
        u = q.popleft()
        for v, cap in g[u]:
            if cap > 0 and prev[v] == -1:
                prev[v] = u
                q.append(v)
                if v == sink:
                    return find_augment(prev)
    return None


def find_augment(prev):
    flow = float("inf")
    v = sink
    while v != source:
        u = prev[v]
        for i, (iv, icap) in enumerate(g[u]):
            if iv == v:
                flow = min(flow, icap)
                g[u][i] = (iv, icap - flow)
                found = False
                for j, (jv, jcap) in enumerate(g[v]):
                    if jv == u:
                        g[v][j] = (jv, jcap + flow)
                        found = True
                        break
                if not found:
                    g[v].append((u, flow))
        v = u
    return flow


n = int(input())
nump = 0
for _ in range(n):
    app, user, comp = input().split()
    user = int(user)
    nump += user
    g[source].append((ord(app), user))
    for com in comp:
        if com == ";":
            break
        g[ord(app)].append((ord(com), 1))
for com in "0123456789":
    if com.isdigit():
        g[ord(com)].append((sink, 1))

max_flow = 0
while True:
    path = bfs()
    if path is None:
        break
    max_flow += path

if max_flow != nump:
    print("!")
else:
    answer = ["_"] * 10
    for node in range(ord("A"), ord("Z") + 1):
        for edge in g[node]:
            if edge[0] in range(ord("0"), ord("9") + 1) and edge[1] == 0:
                answer[edge[0] - ord("0")] = chr(node)
    print("".join(answer))
