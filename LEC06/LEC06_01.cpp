#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  // create  min priority queue for storing
  priority_queue<long long, vector<long long>, greater<long long>> pq;
  for (int i = 0; i < n; i++)
  {
    long long x;
    cin >> x;
    pq.push(x);
  }
  if (n == 1)
  {
    cout << 0 << endl;
    return 0;
  }
  long long ans = 0;
  while (!pq.empty() && pq.size() >= 2)
  {
    // pop two largest integers
    long long x = pq.top();
    pq.pop();
    long long y = pq.top();
    pq.pop();
    // add their sum to the answer
    ans += x + y;
    // push their sum back to the queue if there are numbers left
    if (!pq.empty())
      pq.push(x + y);
  }
  // if there are numbers left in the queue
  if (!pq.empty())
    // add the last number to the answer
    ans += pq.top();
  cout << ans << endl;
  return 0;
}