#include <bits/stdc++.h>

using namespace std;

int arr[100005];
int b;
vector<vector<int>> segments;

int query(int l, int r, int x)
{
  int res = 0, ls = l / b, rs = r / b;
  if (ls == rs)
  {
    for (int i = l; i < r + 1; i++)
      res += (arr[i] <= x);
    return res;
  }
  for (int i = l; i < ls * b + b; i++)
    if (arr[i] <= x)
      res++;
  for (int i = rs * b; i < r + 1; i++)
    if (arr[i] <= x)
      res++;
  for (int i = ls + 1; i < rs; i++)
  {
    res += (int)((upper_bound(segments[i].begin(), segments[i].end(), x)) - segments[i].begin());
  }
  return res;
}

void update(int pos, int val)
{
  int s = pos / b;
  int x = segments[s].size();
  for (int i = 0; i < x; i++)
    if (segments[s][i] == arr[pos])
    {
      segments[s][i] = val;
      break;
    }
  arr[pos] = val;
  sort(segments[s].begin(), segments[s].end());
  return;
}

int main()
{
  int n, q;
  scanf("%d %d", &n, &q);

  for (int i = 1; i <= n; i++)
    scanf("%d", &arr[i]);

  b = ceil(sqrt(n));
  segments.resize(n + 1);
  for (int i = 1; i <= n; i++)
    segments[i / b].push_back(arr[i]);

  for (int i = 0; i <= b; i++)
    sort(segments[i].begin(), segments[i].end());

  for (int i = 0; i < q; i++)
  {
    char cmd;
    scanf(" %c", &cmd);
    if (cmd == 'C')
    {
      // count number of elements in range [s, t] <= k
      int s, t, k;
      scanf("%d %d %d", &s, &t, &k);
      printf("%d\n", query(s, t, k));
    }
    else
    {
      // update arr[x] = y
      int x, y;
      scanf("%d %d", &x, &y);
      update(x, y);
    }
  }
  return 0;
}