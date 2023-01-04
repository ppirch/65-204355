#include <bits/stdc++.h>

using namespace std;

int main()
{
  string inp;
  cin >> inp;

  list<char> lst;
  auto it = lst.begin();
  for (char ch : inp)
  {
    if (ch == '[')
      it = lst.begin();
    else if (ch == ']')
      it = lst.end();
    else
      lst.insert(it, ch);
  }
  for (char ch : lst)
    cout << ch;
  return 0;
}
