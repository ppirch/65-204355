import sys
largest_node = input()
graph = {}
while True:
    input_ = sys.stdin.readline()
    if input_ == '':
        break
    u, v = input_[0], input_[1]
    if u not in graph:
        graph[u] = set()
    graph[u].add(v)
    if v not in graph:
        graph[v] = set()
    graph[v].add(u)


def dfs(graph, start, visited):
    visited.add(start)
    for node in graph[start]:
        if node not in visited:
            dfs(graph, node, visited)
    return visited


visited = dfs(graph, largest_node, set())
print(len(visited))
