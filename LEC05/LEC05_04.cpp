#include <bits/stdc++.h>

using namespace std;

int main()
{
  string inp;
  cin >> inp;
  vector<char> v;
  for (int i = 0; i < inp.size(); i++)
  {
    char ch = inp[i];
    if (v.size() == 0)
    {
      v.push_back(ch);
      continue;
    }
    else
    {
      for (int j = 0; j < v.size(); j++)
      {
        char tmp = v[j];
        if (ch == tmp)
        {
          break;
        }
        else if (ch > tmp && j == v.size() - 1)
        {
          v.push_back(ch);
        }
        else if (ch < tmp)
        {
          v[j] = ch;
          break;
        }
      }
    }
  }
  cout << v.size() << endl;
  return 0;
}