#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
  string inp;
  cin >> inp;

  // Create a set of characters from the input string
  set<char> chars(inp.begin(), inp.end());

  // Get the size of the set
  int cnt = chars.size();

  cout << cnt << endl;
  return 0;
}
