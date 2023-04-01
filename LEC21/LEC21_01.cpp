#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int source = '+';
int sink = '-';

vector<pair<int, int>> g[256];

int bfs()
{
  int prev[256];
  memset(prev, -1, sizeof(prev));
  queue<int> q;
  q.push(source);
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    for (auto edge : g[u])
    {
      int v = edge.first;
      int cap = edge.second;
      if (cap > 0 && prev[v] == -1)
      {
        prev[v] = u;
        q.push(v);
        if (v == sink)
        {
          int flow = 1e9;
          for (int v = sink; v != source; v = prev[v])
          {
            int u = prev[v];
            for (auto &edge : g[u])
            {
              if (edge.first == v)
              {
                flow = min(flow, edge.second);
                break;
              }
            }
          }
          for (int v = sink; v != source; v = prev[v])
          {
            int u = prev[v];
            for (auto &edge : g[u])
            {
              if (edge.first == v)
              {
                edge.second -= flow;
                break;
              }
            }
            bool found = false;
            for (auto &edge : g[v])
            {
              if (edge.first == u)
              {
                edge.second += flow;
                found = true;
                break;
              }
            }
            if (!found)
            {
              g[v].push_back({u, flow});
            }
          }
          return flow;
        }
      }
    }
  }
  return 0;
}

int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int nump = 0;
  while (n--)
  {
    char app, comp[15];
    int user;
    cin >> app >> user >> comp;
    nump += user;
    int len = strlen(comp);
    g[source].push_back({(int)app, user});
    for (int i = 0; i < len; i++)
    {
      char com = comp[i];
      if (com == ';')
      {
        break;
      }
      g[(int)app].push_back({(int)com, 1});
    }
  }
  for (auto com : "0123456789")
  {
    if (isdigit(com))
    {
      g[(int)com].push_back({sink, 1});
    }
  }
  int max_flow = 0;
  while (true)
  {
    int flow = bfs();
    if (flow == 0)
    {
      break;
    }
    max_flow += flow;
  }
  if (max_flow != nump)
  {
    cout << "!\n";
    return 0;
  }
  char answer[] = "__________";
  for (auto node : "ABCDEFGHIJKLMNOPQRSTUVWXYZ")
  {
    for (auto edge : g[node])
    {
      if (isdigit(edge.first) && edge.second == 0)
      {
        answer[edge.first - '0'] = node;
      }
    }
  }
  cout << answer << "\n";
  return 0;
}