#include <bits/stdc++.h>

using namespace std;

int dp[55];

int kways(int n)
{
  if (n < 0)
    return 0;
  if (n == 0 || n == 1)
    return 1;
  if (dp[n] != 0)
    return dp[n];
  dp[n] = kways(n - 1) + kways(n - 3) + kways(n - 4);
  return dp[n];
}

int main()
{
  int n;
  cin >> n;
  cout << kways(n);
  return 0;
}