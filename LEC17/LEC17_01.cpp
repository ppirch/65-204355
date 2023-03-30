#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main()
{
  vector<string> graph;
  vector<pii> pos;
  while (true)
  {
    string line;
    getline(cin, line);
    if (isdigit(line[0]))
    {
      int x, y;
      istringstream ss(line);
      ss >> x >> y;
      pos.push_back({x, y});
    }
    else
      graph.push_back(line);
    if (cin.eof())
      break;
  }

  for (auto p : pos)
  {
    set<pii> visited;
    queue<pii> q;
    q.push({p.first, p.second});
    while (!q.empty())
    {
      pii u = q.front();
      q.pop();
      visited.insert(u);
      char start = graph[u.first][u.second];
      for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
        {
          pii v = {u.first + i, u.second + j};
          if (v.first < 0 || v.first >= graph.size() || v.second < 0 || v.second >= graph[0].size())
            continue;
          if ((graph[v.first][v.second] == 'W') && visited.find(v) == visited.end())
            q.push(v);
        }
    }
    int count = 0;
    for (auto u : visited)
      if (graph[u.first][u.second] == 'W')
        count++;
    cout << count << endl;
  }
}