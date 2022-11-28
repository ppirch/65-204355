#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  long long mx = a[0];
  long long ans = a[0];

  for (int i = 1; i < n; i++)
  {
    mx = max(a[i], mx + a[i]);
    ans = max(ans, mx);
  }
  cout << max(0LL, ans);
  return 0;
}