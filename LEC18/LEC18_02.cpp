#include <bits/stdc++.h>

using namespace std;

int adjMat[105][105];

void floydWarshall(int mx)
{
  for (int k = 1; k <= mx; k++)
    for (int i = 1; i <= mx; i++)
      for (int j = 1; j <= mx; j++)
        adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
}

int main()
{
  int T;
  cin >> T;
  int a, b;
  int mx = -1;
  while (T--)
  {

    for (int i = 0; i < 105; i++)
      for (int j = 0; j < 105; j++)
        adjMat[i][j] = 2e6;
    while (1)
    {
      cin >> a >> b;
      mx = max(mx, a);
      mx = max(mx, b);
      if (a == 0 and b == 0)
      {
        double sm = 0;
        double cnt = 0;
        floydWarshall(mx);
        for (int i = 1; i <= mx; i++)
        {
          for (int j = 1; j <= mx; j++)
            if (i != j & adjMat[i][j] != 2e6)
            {
              sm += adjMat[i][j];
              cnt++;
            }
        }
        cout << fixed << setprecision(3) << sm / cnt << endl;
        break;
      }
      else
        adjMat[a][b] = 1;
    }
  }
  return 0;
}