#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(15);
  for (int i = 0; i < 15; ++i)
  {
    a[i] = pow(2, i);
  }
  int ans = 1;
  for (int i = 0; i < 15; ++i)
  {
    if (a[i] >= n)
    {
      ans = i + 1;
      break;
    }
  }
  cout << ans;
  return 0;
}