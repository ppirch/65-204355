#include <bits/stdc++.h>

using namespace std;

int parent[100005];
int army[100005];

int find(int x)
{
  if (parent[x] == x)
    return x;
  return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
  int px = find(x);
  int py = find(y);
  if (px == py)
    return;
  if (army[px] > army[py])
  {
    parent[py] = px;
    army[px] += army[py] / 2;
  }
  else if (army[px] < army[py])
  {
    parent[px] = py;
    army[py] += army[px] / 2;
  }
  else
  {
    if (px < py)
    {
      parent[py] = px;
      army[px] += army[py] / 2;
    }
    else
    {
      parent[px] = py;
      army[py] += army[px] / 2;
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    parent[i] = i;
  for (int i = 1; i <= n; i++)
    cin >> army[i];
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    if (find(a) == find(b))
    {
      cout << "-1" << endl;
    }
    else
    {
      merge(a, b);
      cout << find(a) << endl;
    }
  }
  return 0;
}