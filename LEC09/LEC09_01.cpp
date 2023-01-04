// toggle count using segment tree with lazy propagation

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tree[N * 4] = {0};
bool lazy[N * 4] = {false};

void toggle(int node, int st, int en, int us, int ue)
{
  if (lazy[node])
  {
    lazy[node] = false;
    tree[node] = en - st + 1 - tree[node];

    if (st < en)
    {
      lazy[node << 1] = !lazy[node << 1];
      lazy[(node << 1) + 1] = !lazy[(node << 1) + 1];
    }
  }

  if (st > en || st > ue || en < us)
    return;

  if (st >= us && en <= ue)
  {
    tree[node] = en - st + 1 - tree[node];

    if (st < en)
    {
      lazy[node << 1] = !lazy[node << 1];
      lazy[(node << 1) + 1] = !lazy[(node << 1) + 1];
    }
    return;
  }

  int mid = (st + en) / 2;
  toggle((node << 1), st, mid, us, ue);
  toggle((node << 1) + 1, mid + 1, en, us, ue);

  if (st < en)
    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

int countQuery(int node, int st, int en, int qs, int qe)
{
  if (st > en || st > qe || en < qs)
    return 0;

  if (lazy[node])
  {
    lazy[node] = false;
    tree[node] = en - st + 1 - tree[node];

    if (st < en)
    {
      lazy[node << 1] = !lazy[node << 1];
      lazy[(node << 1) + 1] = !lazy[(node << 1) + 1];
    }
  }

  if (st >= qs && en <= qe)
    return tree[node];

  int mid = (st + en) / 2;
  int p1 = countQuery((node << 1), st, mid, qs, qe);
  int p2 = countQuery((node << 1) + 1, mid + 1, en, qs, qe);
  return p1 + p2;
}

int main()
{
  ios_base::sync_with_stdio(false);
  int n, q;
  scanf("%d %d", &n, &q);
  while (q--)
  {
    int t, l, r;
    scanf("%d %d %d", &t, &l, &r);
    if (t == 0)
      toggle(1, 1, n, l, r);
    else
      cout << countQuery(1, 1, n, l, r) << '\n';
  }
}