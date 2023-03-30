#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main()
{
  int n;
  vector<iii> old_edges;
  vector<iii> new_edges;
  cin >> n;
  int old_cost = 0;
  for (int i = 0; i < n - 1; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    old_edges.push_back(iii(c, ii(a, b)));
    old_cost += c;
  }
  int k;
  cin >> k;
  for (int i = 0; i < k; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    new_edges.push_back(iii(c, ii(a, b)));
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    new_edges.push_back(iii(c, ii(a, b)));
  }
  sort(new_edges.begin(), new_edges.end());
  int new_cost = 0;
  int cnt = 0;

  vector<bool> visited(n + 1, false);
  priority_queue<iii, vector<iii>, greater<iii>> pq;
  pq.push(iii(0, ii(1, 1)));
  while (!pq.empty())
  {
    iii front = pq.top();
    pq.pop();
    int u = front.second.first;
    int w = front.first;
    if (visited[u])
      continue;
    visited[u] = true;
    new_cost += w;
    cnt++;
    for (int i = 0; i < new_edges.size(); i++)
    {
      int v = new_edges[i].second.first;
      int w = new_edges[i].first;
      if (u == v)
      {
        v = new_edges[i].second.second;
        if (!visited[v])
          pq.push(iii(w, ii(v, u)));
      }
      else if (u == new_edges[i].second.second)
      {
        if (!visited[v])
          pq.push(iii(w, ii(v, u)));
      }
    }
  }
  cout << old_cost << endl;
  cout << new_cost << endl;
  return 0;
}