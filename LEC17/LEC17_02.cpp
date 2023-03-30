#include <bits/stdc++.h>

using namespace std;

int main()
{
  char largest_node;
  cin >> largest_node;
  map<char, set<char>> graph;
  while (true)
  {
    char u, v;
    cin >> u >> v;
    if (cin.eof())
      break;
    graph[u].insert(v);
    graph[v].insert(u);
  }

  set<char> visited;
  queue<char> q;
  // count the number of components
  int count = 0;
  for (char u = 'A'; u <= largest_node; u++)
    if (visited.find(u) == visited.end())
    {
      count++;
      q.push(u);
      while (!q.empty())
      {
        char u = q.front();
        q.pop();
        visited.insert(u);
        for (char v : graph[u])
          if (visited.find(v) == visited.end())
            q.push(v);
      }
    }
  cout << count << endl;
}