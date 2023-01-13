#include <bits/stdc++.h>

using namespace std;

bool check = false;
int need;
void subsetSums(int arr[], int n)
{
  int total = 1 << n;

  for (int i = 0; i < total; i++)
  {
    int sum = 0;

    for (int j = 0; j < n; j++)
    {
      if (i & (1 << j))
        sum += arr[j];
      if (sum > need)
        break;
    }

    if (sum == need)
      check = true;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin >> need;
  int p;
  cin >> p;
  int arr[p + 5];
  for (int i = 0; i < p; ++i)
  {
    cin >> arr[i];
  }
  subsetSums(arr, p);

  if (check)
  {
    cout << "YES";
  }
  else
  {
    cout << "NO";
  }

  return 0;
}