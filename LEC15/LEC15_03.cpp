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
      if (i == 0 or j == 0)
      {
        dp[i][j] = 0;
      }
      else if (a[i - 1] == b[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else
      {
        dp[i][j] = max(
            dp[i - 1][j],
            dp[i][j - 1]);
      }
    }
  }
  int lcs = dp[a.length()][b.length()];
  cout << lcs << endl;
  return 0;
}