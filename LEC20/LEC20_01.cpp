#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define MAX_V 105
#define INF 1000000000
int res[MAX_V][MAX_V], mf, f, s, t; // global variables
vi p;                               // p stores the BFS spanning tree from s
void augment(int v, int minEdge)
{
  // traverse BFS spanning tree from s to t
  if (v == s)
  {
    f = minEdge;
    return;
  }
  // record minEdge in a global variable f
  else if (p[v] != -1)
  {
    augment(p[v], min(minEdge, res[p[v]][v])); // recursive
    res[p[v]][v] -= f;
    res[v][p[v]] += f;
  } // update
}
int main()
{
  int V;
  scanf("%d", &V);
  memset(res, 0, sizeof res);
  int c;
  scanf("%d %d %d", &s, &t, &c);
  for (int i = 0; i < c; i++)
  {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    res[u][v] += w;
    res[v][u] += w;
  }
  mf = 0;
  while (1)
  { // O(VE^2) (actually O(V^3E) Edmonds Karp's algorithm
    f = 0;
    // run BFS
    vi dist(MAX_V, INF);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    p.assign(MAX_V, -1); // record the BFS spanning tree, from s to t!
    while (!q.empty())
    {
      int u = q.front();
      q.pop();
      if (u == t)
        break; // stop BFS if we already reach sink t
      for (int v = 0; v < MAX_V; v++)
        if (res[u][v] > 0 && dist[v] == INF)
        {
          dist[v] = dist[u] + 1;
          q.push(v), p[v] = u;
        }
    }
    augment(t, INF); // find the min edge weight `f' along this path, if any
    if (f == 0)
      break; // we cannot send any more flow (`f' = 0), terminate
    mf += f; // we can still send a flow, increase the max flow!
  }
  printf("%d\n", mf); // this is the max flow value
  return 0;
}