#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  string inp;
  cin >> inp;

  vector<char> curr;
  for (char ch : inp)
  {
    if (curr.empty())
    {
      curr.push_back(ch);
    }
    else
    {
      // Find the maximum character in curr
      char max_ch = curr[0];
      for (size_t i = 1; i < curr.size(); i++)
      {
        if (curr[i] > max_ch)
        {
          max_ch = curr[i];
        }
      }

      if (ch <= max_ch)
      {
        // Replace the maximum character in curr with ch
        for (size_t i = 0; i < curr.size(); i++)
        {
          if (curr[i] == max_ch)
          {
            curr[i] = ch;
            break;
          }
        }
      }
      else
      {
        curr.push_back(ch);
      }
    }
  }
  cout << curr.size() << endl;
  return 0;
}
