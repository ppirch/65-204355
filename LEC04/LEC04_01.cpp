#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin >> n;

  vector<int> primes(n + 10);
  iota(primes.begin(), primes.end(), 0);
  for (int i = 2; i * i <= n; ++i)
  {
    if (primes[i] == i)
    {
      for (int j = i * i; j <= n; j += i)
      {
        primes[j] = i;
      }
    }
  }
  for (int i = 2; i <= n; ++i)
  {
    if (primes[i] == i)
    {
      cout << i << " ";
    }
  }
  return 0;
}