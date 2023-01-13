#include <bits/stdc++.h>

using namespace std;

int n;
int dp[100005];
int arr[100005];

int maxProfit(int k)
{
  if (k < 0)
    return 0;
  if (dp[k] != 0)
    return dp[k];
  for (int i = 1; i <= k; ++i)
    dp[k] = max(dp[k], maxProfit(k - i) + arr[i]);
  return dp[k];
}

int main()
{
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];
  dp[0] = 0;
  dp[1] = arr[1];
  int k;
  cin >> k;
  cout << maxProfit(k);
  return 0;
}