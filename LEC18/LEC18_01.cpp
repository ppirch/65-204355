#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using piii = pair<int, pii>;

int main()
{
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int prices[n + 5];
  for (int i = 0; i < n; i++)
  {
    cin >> prices[i];
  }
  vector<vector<pii>> g(n + 5);

  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  int q, c, s, t;
  cin >> q;
  while (q--)
  {
    cin >> c >> s >> t;
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    vector<vector<int>> dist(n + 5, vector<int>(c + 5, 1e9));
    vector<vector<bool>> visited(n + 5, vector<bool>(c + 5, false));
    dist[s][0] = 0;
    pq.push({dist[s][0], {s, 0}});
    while (!pq.empty())
    {
      auto top = pq.top();
      int cost = top.first;
      auto curr = top.second;
      pq.pop();
      int u = curr.first;
      int curr_c = curr.second;
      if (u == t && curr_c == 0)
        break;
      if (visited[u][curr_c])
        continue;
      visited[u][curr_c] = true;

      for (auto it : g[u])
      {
        int v = it.first;
        int w = it.second;
        int new_c = curr_c - w;
        if (new_c >= 0 && visited[v][new_c])
          continue;
        if (new_c >= 0 && dist[v][new_c] > cost)
        {
          dist[v][new_c] = cost;
          pq.push({dist[v][new_c], {v, new_c}});
        }
      }
      int new_c = curr_c + 1;
      if (new_c <= c && visited[u][new_c])
        continue;
      if (new_c <= c && dist[u][new_c] > cost + prices[u])
      {
        dist[u][new_c] = cost + prices[u];
        pq.push({dist[u][new_c], {u, new_c}});
      }
    }
    if (dist[t][0] == 1e9)
      cout << "impossible" << endl;
    else
      cout << dist[t][0] << endl;
  }
  return 0;
}