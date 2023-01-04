#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  int n, q;
  scanf("%d %d", &n, &q);
  int arr[n + 5];
  for (int i = 1; i <= n; i++)
    scanf("%d", &arr[i]);
  for (int i = 0; i < q; i++)
  {
    char cmd;
    scanf("%c", &cmd);
    if (cmd == 'C')
    {
      // count
      int s, t, k;
      scanf("%d %d %d", &s, &t, &k);
      int count = 0;
      for (int j = s; j <= t; j++)
        if (arr[j] <= k)
          count++;
      printf("%d\n", count);
    }
    else
    {
      // update
      int x, y;
      scanf("%d %d", &x, &y);
      arr[x] = y;
    }
  }
  return 0;
}