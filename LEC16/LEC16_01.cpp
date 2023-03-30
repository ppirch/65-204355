#include <bits/stdc++.h>

using namespace std;

int graph[105][105];
int ans[105][105];

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      cin >> graph[i][j];
      ans[i][j] = 1;
    }

  for (int k = 1; k < n; k++)
  {
    queue<int> q;
    set<int> visited;
    q.push(0);
    visited.insert(0);
    while (!q.empty())
    {
      int cur = q.front();
      q.pop();
      for (int l = 1; l < n; l++)
        if (graph[cur][l] == 1 && l != k && visited.find(l) == visited.end())
        {
          q.push(l);
          visited.insert(l);
        }
    }
    for (auto v : visited)
      ans[k][v] = 0;
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << (ans[i][j] ? "Y" : "N");
    cout << endl;
  }
  return 0;
}