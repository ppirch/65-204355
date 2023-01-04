#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> h(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> h[i];
  }

  double avg = accumulate(h.begin(), h.end(), 0.0) / n;

  int cnt = 0;
  for (int i : h)
  {
    if (i > avg)
    {
      cnt += (i - avg);
    }
  }

  cout << cnt << endl;
  return 0;
}