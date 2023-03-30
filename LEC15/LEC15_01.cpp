#include <bits/stdc++.h>

using namespace std;

int main()
{
  string a, b;
  cin >> a >> b;
  transform(a.begin(), a.end(), a.begin(), ::tolower);
  transform(b.begin(), b.end(), b.begin(), ::tolower);
  int max_length = max(a.length(), b.length());
  int dp[a.length() + 1][b.length() + 1];
  for (int i = 0; i <= a.length(); i++)
  {
    for (int j = 0; j <= b.length(); j++)
    {
      if (i == 0)
      {
        dp[i][j] = j;
      }
      else if (j == 0)
      {
        dp[i][j] = i;
      }
      else if (a[i - 1] == b[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = min(
                       dp[i - 1][j],
                       min(dp[i][j - 1],
                           dp[i - 1][j - 1])) +
                   1;
      }
    }
  }
  int edit = dp[a.length()][b.length()];
  int isSub = (max(a.length(), b.length()) + 1) / 2;
  if (edit < isSub)
  {
    cout << edit << " " << 1 << endl;
  }
  else
  {
    cout << edit << " " << 0 << endl;
  }
  return 0;
}