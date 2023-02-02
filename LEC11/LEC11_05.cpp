#include <bits/stdc++.h>

using namespace std;

char board[20][20];
int N;

bool isSafe(int r, int c)
{
  int i, j;
  // check border
  if (r < 0 || r >= N || c < 0 || c >= N)
    return false;
  // check current
  if (board[r][c] == 'Q' || board[r][c] == '*')
    return false;

  // check column
  for (i = 0; i < N; ++i)
    if (board[i][c] == 'Q')
      return false;

  /* Check upper diagonal on left side */
  for (i = r, j = c; i >= 0 && j >= 0; --i, --j)
    if (board[i][j] == 'Q')
      return false;

  /* Check lower diagonal on left side */
  for (i = r, j = c; j >= 0 && i < N; ++i, --j)
    if (board[i][j] == 'Q')
      return false;

  /* Check upper diagonal on right side */
  for (i = r, j = c; i >= 0 && j < N; --i, ++j)
    if (board[i][j] == 'Q')
      return false;

  return true;
}

int placeQueen(int r)
{
  if (r >= N)
    return 1;
  int cnt = 0;
  for (int i = 0; i < N; ++i)
  {
    if (isSafe(r, i))
    {
      board[r][i] = 'Q';
      cnt += placeQueen(r + 1);
      board[r][i] = '.';
    }
  }
  return cnt;
}

int main()
{
  ios::sync_with_stdio(false);
  int n;
  scanf("%d", &n);

  while (n--)
  {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
      scanf(" %s", &board[i]);
    printf("%d\n", placeQueen(0));
  }

  return 0;
}