#include <bits/stdc++.h>

using namespace std;

int main()
{
  string s;
  getline(cin, s);
  if (next_permutation(s.begin(), s.end()))
  {
    cout << s << endl;
  }
  else
  {
    cout << "No Successor" << endl;
  }
  return 0;
}