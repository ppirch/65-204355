#include <bits/stdc++.h>

using namespace std;

int main()
{
  int nc;
  cin >> nc;
  map<int, vector<int>> m;
  for (int i = 0; i < nc; i++)
  {
    int a, b;
    cin >> a >> b;
    m[a].push_back(b);
    m[b].push_back(a);
  }
  for (auto i : m)
  {
    cout << i.first << ": ";
    for (auto j : i.second)
      cout << j << " ";
    cout << endl;
  }
  return 0;
}