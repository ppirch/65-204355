#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int arr[n + 5];
  vector<int> sum;

  for (int i = 0; i < n; ++i)
  {
    cin >> arr[i];
  }

  for (int i = 0; i < n - 1; ++i)
  {
    for (int j = i + 1; j < n; ++j)
    {
      sum.push_back(arr[i] + arr[j]);
    }
  }

  int q;
  cin >> q;
  while (q--)
  {
    int x;
    cin >> x;
    int diff = 2e9;
    for (auto val : sum)
    {
      if (abs(val - x) < diff)
      {
        diff = abs(val - x);
      }
    }
    cout << diff << "\n";
  }

  return 0;
}