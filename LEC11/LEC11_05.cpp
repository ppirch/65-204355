#include <bits/stdc++.h>

using namespace std;

int board[25][25] = {0};
int N;
set<string> s;
bool isSafe(int r, int c)
{
  // check border
  if (r <= 0 || r > N || c <= 0 || c > N)
    return false;
  // check current
  if (board[r][c] == 1 || board[r][c] == -1)
    return false;
  // check row
  for (int i = 1; i <= N; ++i)
    if (board[r][i] == 1)
      return false;
  // check column
  for (int i = 1; i <= N; ++i)
    if (board[i][c] == 1)
      return false;
  // check diagonal
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= N; ++j)
      if (board[i][j] == 1 && abs(i - r) == abs(j - c))
        return false;

  return true;
}

void printBoard()
{
  string sol;
  for (int j = 1; j <= N; ++j)
    for (int i = 1; i <= N; ++i)
      if (board[i][j] == 1)
        sol += to_string(i) + " ";

  s.insert(sol);
}

bool placeQueen(int r, int c)
{
  if (r >= N + 1)
  {
    printBoard();
    return true;
  }
  bool res = false;
  for (int i = 1; i <= N; ++i)
  {
    if (isSafe(r, i))
    {
      board[r][i] = 1;
      res = placeQueen(r + 1, i) || res;
      board[r][i] = 0;
    }
  }
  return res;
}
int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int c;
  while (n--)
  {
    cin >> N;

    for (int i = 1; i <= N; ++i)
      for (int j = 1; j <= N; ++j)
        board[i][j] = 0;

    string row;
    for (int i = 1; i <= N; ++i)
    {
      cin >> row;
      for (int j = 1; j <= N; ++j)
        if (row[j - 1] == '*')
          board[i][j] = -1;
    }
    placeQueen(1, 1);
    cout << s.size() << endl;
    s.clear();
  }

  return 0;
}