#include <bits/stdc++.h>

using namespace std;

int main()
{

  int m, n, q;
  cin >> m >> n >> q;
  vector<string> land;

  for (int i = 0; i < m; ++i)
  {
    string row;
    cin >> row;
    land.push_back(row);
  }

  int r, c;
  while (q--)
  {
    cin >> r >> c;
    if (r == 0 || r == m - 1)
    {
      cout << 1 << "\n";
    }
    else if (c == 0 || c == n - 1)
    {
      cout << 1 << "\n";
    }
    else
    {
      int ans = 0;
      char own = land[r][c];
      bool ch = true;
      while (true)
      {
        if (r - ans < 0 || r + ans >= m || c - ans < 0 || c + ans >= n)
        {
          ans -= 1;
          break;
        }
        for (int i = r - ans; i <= r + ans; ++i)
        {
          for (int j = c - ans; j <= c + ans; ++j)
          {
            if (land[i][j] != own)
            {
              ch = false;
            }
          }
        }
        if (ch == false)
        {
          ans -= 1;
          break;
        }
        ans += 1;
      }
      cout << ans * 2 + 1 << "\n";
    }
  }
  return 0;
}

// 1 2
// 2 4
// 4 6
// 5 8