#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  int b, n;
  cin >> b >> n;

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

  int cnt = 0;
  for (int i = b; i <= n; ++i)
  {
    if (primes[i] == i)
    {
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}