#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;

  long long arr[n + 5];
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];

  int k;
  cin >> k;

  long long dp[k + 5];
  dp[0] = 0;
  dp[1] = arr[1];

  for (int i = 2; i <= k; ++i)
    dp[i] = 0;

  for (int i = 2; i <= k; ++i)
    for (int j = 1; j <= n; ++j)
      if (i - j >= 0)
        dp[i] = max(dp[i], dp[i - j] + arr[j]);

  cout << dp[k];

  return 0;
}