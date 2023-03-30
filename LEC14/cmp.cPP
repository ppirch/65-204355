#include <bits/stdc++.h>

using namespace std;

long long dist(long long x1, long long y1, long long x2, long long y2)
{
  return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
  ios::sync_with_stdio(false);

  long long n, m;
  cin >> n >> m;
  long long st_x, st_y;
  cin >> st_x >> st_y;
  long long t;
  cin >> t;
  vector<pair<long long, long long>> points;
  for (long long i = 0; i < t; i++)
  {
    long long x, y;
    cin >> x >> y;
    points.push_back({x, y});
  }

  long long mn = 2e9;
  do
  {
    long long x = st_x, y = st_y;
    long long total_dist = 0;
    for (auto p : points)
    {
      total_dist += dist(x, y, p.first, p.second);
      x = p.first;
      y = p.second;
    }
    total_dist += dist(x, y, st_x, st_y);
    mn = min(mn, total_dist);
  } while (next_permutation(points.begin(), points.end()));

  cout << mn << endl;
  return 0;
}