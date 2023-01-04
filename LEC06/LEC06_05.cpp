#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  map<string, int> mp;
  for (int i = 0; i < n; i++)
  {
    vector<int> s;
    for (int j = 0; j < 5; j++)
    {
      int x;
      cin >> x;
      s.push_back(x);
    }
    sort(s.begin(), s.end());
    string key = "";
    for (int j = 0; j < 5; j++)
    {
      key += to_string(s[j]) + "_";
    }
    mp[key]++;
  }
  // get max value from map
  int max_value = 0;
  for (auto it = mp.begin(); it != mp.end(); it++)
  {
    max_value = max(max_value, it->second);
  }
  int cnt = 0;
  for (auto it = mp.begin(); it != mp.end(); it++)
  {
    if (it->second == max_value)
    {
      cnt++;
    }
  }
  if (cnt == 1)
  {
    cout << max_value << endl;
  }
  else
  {
    cout << cnt << endl;
  }
  return 0;
}