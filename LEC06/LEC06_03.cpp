#include <bits/stdc++.h>

using namespace std;

int main()
{

  // get string until EOF
  string s;
  set<string> words;
  while (getline(cin, s))
  {
    // replace all non-alphabetic characters with spaces
    replace_if(
        s.begin(), s.end(), [](char c)
        { return !isalpha(c); },
        ' ');
    // split string into words
    stringstream ss(s);
    while (ss >> s)
    {
      // convert string in to lower case
      transform(s.begin(), s.end(), s.begin(), ::tolower);
      words.insert(s);
    }
  }
  // display all words in lexicographical order
  for (auto word : words)
  {
    cout << word << endl;
  }
  return 0;
}