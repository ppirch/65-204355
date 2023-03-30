nodes = int(input())
graphs = []
for _ in range(nodes):
    graphs.append(input().split())

queue = []
visited = [False for _ in range(nodes)]

dominator = {}

start = 0

queue.append(start)
visited[start] = True
parents = {}
while queue:
    node = queue.pop(0)
    try:
        parents[node] = parents[node] | set([node])
    except:
        parents[node] = set([node])
    for i in range(nodes):
        if graphs[node][i] == '1' and not visited[i]:
            parents[i] = parents[node] | set([i])
            queue.append(i)
            visited[i] = True
childs = {}
for i in range(nodes):
    for j in range(nodes):
        if i in parents[j]:
            try:
                childs[i] = childs[i] | set([j])
            except:
                childs[i] = set([j])
print(childs)
