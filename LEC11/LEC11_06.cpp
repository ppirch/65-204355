#include <bits/stdc++.h>

using namespace std;

int board[9][9] = {0};

set<vector<int>> s;
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
  vector<int> sol;
  for (int j = 1; j <= 8; ++j)
    for (int i = 1; i <= 8; ++i)
      if (board[i][j] == 1)
        sol.push_back(i - 1);
  s.insert(sol);
}

void placeQueen(int r)
{
  if (r >= 9)
  {
    printBoard();
  }
  for (int i = 1; i <= 8; ++i)
  {
    if (isSafe(r, i))
    {
      board[r][i] = 1;
      placeQueen(r + 1);
      board[r][i] = 0;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int c;
  int map[10][10];
  while (n--)
  {
    for (int i = 1; i <= 8; ++i)
      for (int j = 1; j <= 8; ++j)
        board[i][j] = 0;
    for (int i = 0; i < 8; ++i)
      for (int j = 0; j < 8; ++j)
        cin >> map[i][j];
    placeQueen(1);
    int ans = -2e9;
    for (auto it = s.begin(); it != s.end(); ++it)
    {
      int rst = 0;
      for (auto it2 = it->begin(); it2 != it->end(); ++it2)
      {
        rst += map[*it2][it2 - it->begin()];
      }
      ans = max(ans, rst);
    }
    cout << ans << endl;
  }

  return 0;
}