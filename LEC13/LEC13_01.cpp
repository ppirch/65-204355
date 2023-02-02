#include <bits/stdc++.h>

using namespace std;

int n;
int dp[10005];
int arr[10005];

int minAT(int k)
{
  if (k < 0)
    return 2e9;
  if (dp[k] != 2e9)
    return dp[k];
  for (int i = 1; i <= n; ++i)
    dp[k] = min(dp[k], minAT(k - arr[i]) + 1);
  return dp[k];
}

int main()
{
  int k;
  cin >> k;
  cin >> n;
  for (int i = 1; i <= n; ++i)
  {
    cin >> arr[i];
  }
  for (int i = 1; i <= k; ++i)
  {
    dp[i] = 2e9;
  }
  dp[0] = 0;
  dp[1] = 1;
  cout << minAT(k);
  return 0;
}