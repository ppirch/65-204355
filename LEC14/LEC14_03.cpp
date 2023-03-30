#include <bits/stdc++.h>

using namespace std;

int n, m;
int dist[20][20];
int memo[20][1 << 20];

int tsp(int pos, int bitmask)
{
  // bitmask stores the visited coordinates
  if (bitmask == (1 << (n + 1)) - 1)
    return dist[pos][0]; // กลับไปที่เมืองเริ่มต้น
  if (memo[pos][bitmask] != -1)
    return memo[pos][bitmask];
  int ans = 2000000000;
  for (int nxt = 0; nxt <= n; nxt++) // O(n) here
    if (nxt != pos && !(bitmask & (1 << nxt)))
      // if coordinate nxt is not visited yet
      ans = min(ans, dist[pos][nxt] + tsp(nxt, bitmask | (1 << nxt)));
  return memo[pos][bitmask] = ans;
}

int main()
{
  ios::sync_with_stdio(false);

  cin >> n >> m;
  int st_x, st_y;
  cin >> st_x >> st_y;
  int t;
  cin >> t;
  vector<pair<int, int>> pts;
  for (int i = 0; i < t; i++)
  {
    int x, y;
    cin >> x >> y;
    pts.push_back({x, y});
  }

  memset(dist, 1e9, sizeof dist);
  for (int i = 0; i < t; i++)
  {
    for (int j = 0; j < t; j++)
    {
      dist[i][j] = (abs(pts[i].first - pts[j].first) + abs(pts[i].second - pts[j].second));
    }
  }

  memset(memo, -1, sizeof memo);
  cout << tsp(0, 1) << endl;
  return 0;
}