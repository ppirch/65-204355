from queue import Queue

src = 38
snk = 39
INF = 2e9

gph = [[] for _ in range(40)]
p = [-1] * 40
rgph = [[0] * 40 for _ in range(40)]


def bfs():
    global p
    p = [-1] * 40
    p[src] = -2
    q = Queue()
    q.put((src, INF))
    while not q.empty():
        u, f = q.get()
        for v in gph[u]:
            if p[v] != -1 or rgph[u][v] == 0:
                continue
            p[v] = u
            nf = min(f, rgph[u][v])
            if v == snk:
                return nf
            q.put((v, nf))
    return 0


def addEdge(u, v):
    gph[u].append(v)
    gph[v].append(u)


# main function
t = int(input())
# t = 1
rqr = 0
for I in range(t):
    c, n, s = input().split()
    # c, n, s = 'A', 3, '0B9'
    n = int(n)
    u = ord(c) - ord('A')
    rqr += rgph[src][u] = n
    addEdge(src, u)
    for i in range(len(s)):
        if not s[i].isalnum():
            break
        v = 26 + int(s[i])
        rgph[u][v] = rgph[v][snk] = 1

for u in range(40):
    for v in range(u+1, 40):
        if rgph[u][v]:
            addEdge(u, v)

nf, mxf = 0, 0
while (nf := bfs()):
    mxf += nf
    u = snk
    while u != src:
        v = p[u]
        rgph[v][u] -= nf
        rgph[u][v] += nf
        u = v

if mxf != rqr:
    print("!")
else:
    rlt = ['_' for _ in range(11)]
    for i in range(26):
        if not gph[i]:
            continue
        for j in range(26, 26+10):
            idx = j - 26
            if rlt[idx] == '_':
                rlt[idx] = chr(i + ord('A'))
            if rgph[j][i] and rlt[idx] == '_':
                rlt[idx] = chr(i + ord('A'))
    print(''.join(rlt))
