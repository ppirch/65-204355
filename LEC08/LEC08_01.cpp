#include <bits/stdc++.h>

using namespace std;

int getMid(int s, int e) { return s + (e - s) / 2; }

int getSumUtil(int *st, int ss, int se, int qs, int qe, int si)
{
  if (qs <= ss && qe >= se)
    return st[si];

  if (se < qs || ss > qe)
    return 0;

  int mid = getMid(ss, se);
  return getSumUtil(st, ss, mid, qs, qe, 2 * si + 1) +
         getSumUtil(st, mid + 1, se, qs, qe, 2 * si + 2);
}

void updateValueUtil(int *st, int ss, int se, int i, int diff, int si)
{
  if (i < ss || i > se)
    return;

  st[si] = st[si] + diff;
  if (se != ss)
  {
    int mid = getMid(ss, se);
    updateValueUtil(st, ss, mid, i, diff, 2 * si + 1);
    updateValueUtil(st, mid + 1, se, i, diff, 2 * si + 2);
  }
}

void updateValue(int arr[], int *st, int n, int i, int new_val)
{
  if (i < 0 || i > n - 1)
  {
    cout << "Invalid Input";
    return;
  }

  int diff = new_val - arr[i];

  arr[i] = new_val;

  updateValueUtil(st, 0, n - 1, i, diff, 0);
}

int getSum(int *st, int n, int qs, int qe)
{
  if (qs < 0 || qe > n - 1 || qs > qe)
  {
    cout << "Invalid Input";
    return -1;
  }

  return getSumUtil(st, 0, n - 1, qs, qe, 0);
}

int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
  if (ss == se)
  {
    st[si] = arr[ss];
    return arr[ss];
  }

  int mid = getMid(ss, se);
  st[si] = constructSTUtil(arr, ss, mid, st, si * 2 + 1) +
           constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);
  return st[si];
}

int *constructST(int arr[], int n)
{

  int x = (int)(ceil(log2(n)));

  int max_size = 2 * (int)pow(2, x) - 1;

  int *st = new int[max_size];

  constructSTUtil(arr, 0, n - 1, st, 0);

  return st;
}
int main()
{
  ios::sync_with_stdio(false);
  int n, m, t;
  string fan;
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    string x;
    cin >> t;
    cin >> x;
    for (int j = 0; j < t; j++)
      fan += x;
  }
  n = fan.size();
  int q;
  cin >> q;
  int arr[n + 5];
  for (int i = 0; i < n; ++i)
  {
    if (fan[i] == '1')
      arr[i] = 1;
    else
      arr[i] = 0;
  }
  int *st = constructST(arr, n);

  for (int i = 0; i < q; i++)
  {
    char cmd;
    int l, r;
    cin >> cmd >> l >> r;
    if (cmd == 'F')
    {
      // change to 1
      for (int j = l; j <= r; j++)
        updateValue(arr, st, n, j, 1);
    }
    else if (cmd == 'E')
    {
      // change to 0
      for (int j = l; j <= r; j++)
        updateValue(arr, st, n, j, 0);
    }
    else if (cmd == 'I')
    {
      // change to 1 if 0, 0 if 1
      for (int j = l; j <= r; j++)
        updateValue(arr, st, n, j, 1 - arr[j]);
    }
    else
    {
      // count 1
      cout << getSum(st, n, l, r) << "\n";
    }
  }

  return 0;
}