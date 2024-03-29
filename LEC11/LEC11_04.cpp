#include <bits/stdc++.h>

using namespace std;

int board[9][9] = {0};
int rp = -1;

set<string> s;
bool isSafe(int r, int c)
{
  // check border
  if (r <= 0 || r > 8 || c <= 0 || c > 8)
    return false;
  // check current
  if (board[r][c] == 1)
    return false;
  // check row
  for (int i = 1; i <= 8; ++i)
    if (board[r][i] == 1)
      return false;
  // check column
  for (int i = 1; i <= 8; ++i)
    if (board[i][c] == 1)
      return false;
  // check diagonal
  for (int i = 1; i <= 8; ++i)
    for (int j = 1; j <= 8; ++j)
      if (board[i][j] == 1 && abs(i - r) == abs(j - c))
        return false;

  return true;
}

void printBoard()
{
  string sol;
  for (int j = 1; j <= 8; ++j)
    for (int i = 1; i <= 8; ++i)
      if (board[i][j] == 1)
        sol += to_string(i) + " ";
  s.insert(sol);
}

bool placeQueen(int r)
{
  if (r >= 9)
  {
    printBoard();
    return true;
  }
  bool res = false;
  for (int i = 1; i <= 8; ++i)
  {
    if (isSafe(r, i))
    {
      board[r][i] = 1;
      res = placeQueen(r + 1) || res;
      board[r][i] = 0;
    }
    else if (r == rp)
    {
      res = placeQueen(r + 1) || res;
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
    for (int i = 1; i <= 8; ++i)
      for (int j = 1; j <= 8; ++j)
        board[i][j] = 0;
    cin >> rp >> c;
    board[rp][c] = 1;
    placeQueen(1);
    for (auto it = s.begin(); it != s.end(); ++it)
      cout << *it << endl;
    s.clear();
    cout << endl;
  }

  return 0;
}