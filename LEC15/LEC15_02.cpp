#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);

  int L;
  cin >> L;
  int n;
  cin >> n;
  int c[n + 1];
  for (int i = 0; i < n; i++)
  {
    cin >> c[i];
  }

  int dp[n + 1][L + 1];
  memset(dp, 0, sizeof dp);

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= L; j++)
    {
      if (j >= c[i - 1])
      {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i - 1]] + c[i - 1]);
      }
      else
      {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << dp[n][L] << endl;

  return 0;
}