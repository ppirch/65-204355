nodes = int(input())
graphs = []
for _ in range(nodes):
    graphs.append(input().split())

answers = [[] for _ in range(nodes)]

mark = [False] * nodes
mark[0] = True
queue = [0]
while queue:
    node = queue.pop(0)
    for i, is_edge in enumerate(graphs[node]):
        if not mark[i] and is_edge == '1':
            mark[i] = True
            queue.append(i)

for skip in range(nodes):
    visited = [False] * nodes
    visited[0] = True
    queue = [0]
    while queue:
        node = queue.pop(0)
        for i, is_edge in enumerate(graphs[node]):
            if not visited[i] and is_edge == '1' and i != skip:
                visited[i] = True
                queue.append(i)
    for i, v in enumerate(visited):
        if not mark[i]:
            answers[skip].append("N")
        elif not v or skip == 0:
            answers[skip].append("Y")
        else:
            answers[skip].append("N")
for answer in answers:
    print("".join(answer))
