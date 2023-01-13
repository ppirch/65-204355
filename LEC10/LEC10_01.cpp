#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  for (int i = -100; i <= 100; i++)
  {
    for (int j = -100; j <= 100; j++)
    {
      int k = a - i - j;
      if (i != j && j != k && i != k &&
          i + j + k == a &&
          i * j * k == b &&
          i * i + j * j + k * k == c)
      {
        int arr[] = {i, j, k};
        sort(arr, arr + 3);
        cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << '\n';
        return 0;
      }
    }
  }
  cout << "No solution.\n";
  return 0;
}