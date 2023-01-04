#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;

void update(int idx, int blk, int val, int bit[][MAX])
{
  for (; idx < MAX; idx += (idx & -idx))
    bit[blk][idx] += val;
}

int query(int l, int r, int k, int arr[], int blk_sz,
          int bit[][MAX])
{
  int sum = 0;
  while (l < r && l % blk_sz != 0 && l != 0)
  {
    if (arr[l] <= k)
      sum++;
    l++;
  }

  while (l + blk_sz <= r)
  {
    int idx = k;
    for (; idx > 0; idx -= idx & -idx)
      sum += bit[l / blk_sz][idx];
    l += blk_sz;
  }

  while (l <= r)
  {
    if (arr[l] <= k)
      sum++;
    l++;
  }
  return sum;
}

void preprocess(int arr[], int blk_sz, int n, int bit[][MAX])
{
  for (int i = 0; i < n; i++)
    update(arr[i], i / blk_sz, 1, bit);
}

void preprocessUpdate(int i, int v, int blk_sz,
                      int arr[], int bit[][MAX])
{
  update(arr[i], i / blk_sz, -1, bit);
  update(v, i / blk_sz, 1, bit);
  arr[i] = v;
}

int main()
{

  int n, q;
  scanf("%d %d", &n, &q);

  int arr[n + 5];
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  int blk_sz = sqrt(n);

  int bit[blk_sz + 1][MAX];
  memset(bit, 0, sizeof(bit));

  preprocess(arr, blk_sz, n, bit);

  for (int i = 0; i < q; i++)
  {
    char cmd;
    scanf(" %c", &cmd);
    if (cmd == 'C')
    {
      // query elments less than or equal to k
      int s, t, k;
      scanf("%d %d %d", &s, &t, &k);
      printf("%d\n", query(s - 1, t - 1, k, arr, blk_sz, bit));
    }
    else
    {
      // update element at index x - 1 to value y
      int x, y;
      scanf("%d %d", &x, &y);
      preprocessUpdate(x - 1, y, blk_sz, arr, bit);
    }
  }
  return 0;
}