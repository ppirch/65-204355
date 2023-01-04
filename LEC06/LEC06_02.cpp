#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> playes(m);
  for (int i = 0; i < m; i++)
    cin >> playes[i];
  int players_left = 1 << n;
  bitset<1025> bs;
  bs.set();
  for (int i = 0; i < m; i++)
    bs.set(playes[i] - 1, 0);
  int ans = 0;
  while (players_left > 1)
  {
    // cout << "players_left: " << players_left << endl;
    // for (int i = 0; i < players_left; i++)
    //   cout << bs[i] << " ";
    // cout << endl;
    int curr = 0;
    for (int i = 0; i < players_left; i += 2)
      if (bs[i] && bs[i + 1])
      {
        // cout << bs[i] << " " << bs[i + 1] << endl;
        bs[curr] = 1;
        curr += 1;
      }
      else if (bs[i] || bs[i + 1])
      {
        // cout << bs[i] << " " << bs[i + 1] << endl;
        bs[curr] = 1;
        ans += 1;
        curr += 1;
      }
      else
      {
        // cout << bs[i] << " " << bs[i + 1] << endl;
        bs[curr] = 0;
        curr += 1;
      }
    players_left = players_left / 2;
  }
  cout << ans << endl;
  return 0;
}