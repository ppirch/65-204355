#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[100005];
long long arr[100005];

long long maxSub(int n)
{
  for (int i = 1; i <= n; ++i)
  {
    dp[i] = max(arr[i], dp[i - 1] + arr[i]);
  }
  return *max_element(dp + 1, dp + n + 1);
}

int main()
{
  cin >> n;
  for (int i = 1; i <= n; ++i)
  {
    cin >> arr[i];
  }
  dp[0] = 0;
  dp[1] = arr[1];

  cout << maxSub(n);
  return 0;
}