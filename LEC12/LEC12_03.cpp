#include <bits/stdc++.h>

using namespace std;

int n;
int a[20005];

int main()
{
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i < n; i++)
    cin >> a[i];
  int mx = -2e9, s = 0, e = 0, len = -2e9;
  int ans = -2e9, mx_len = -2e9, mx_s, mx_e;
  for (int i = 1; i < n; i++)
  {
    if (mx + a[i] < a[i])
    {
      s = i;
      e = i + 1;
      len = 1;
      mx = a[i];
    }
    else
    {
      e = i + 1;
      mx += a[i];
      len += 1;
    }
    if (mx > ans || (mx == ans && len > mx_len))
    {
      mx_s = s;
      mx_e = e;
      ans = mx;
      mx_len = len;
    }
  }
  if (ans >= 0)
  {
    cout << mx_s << " " << mx_e << endl;
  }
  else
  {
    cout << "no" << endl;
  }
  return 0;
}