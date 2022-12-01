#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int>> b(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> b[i].second >> b[i].first;
  }
  sort(b.begin(), b.end());
  int lst = 0;
  int cnt = 0;
  for (int i = 0; i < n; ++i)
  {
    if (b[i].second >= lst)
    {
      lst = b[i].first;
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}