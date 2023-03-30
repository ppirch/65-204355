#include <bits/stdc++.h>

using namespace std;

int main()
{
  int nc;
  cin >> nc;
  map<int, vector<int>> m;
  for (int i = 0; i < nc; i++)
  {
    int a, b;
    cin >> a >> b;
    m[a].push_back(b);
    m[b].push_back(a);
  }
  int node, ttl;
  while (1)
  {
    cin >> node >> ttl;
    if (node == 0 && ttl == 0)
      break;
    queue<pair<int, int>> q;
    set<int> visited;
    q.push({node, 0});
    visited.insert(node);
    while (!q.empty())
    {
      int cur = q.front().first;
      int cur_ttl = q.front().second;
      q.pop();
      for (auto v : m[cur])
        if (visited.find(v) == visited.end() and cur_ttl + 1 <= ttl)
        {
          q.push({v, cur_ttl + 1});
          visited.insert(v);
        }
    }
    cout << m.size() - visited.size() << endl;
  }
  return 0;
}