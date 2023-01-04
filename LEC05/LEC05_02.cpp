#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(const string &str, char delim)
{
  vector<string> tokens;
  string token;
  istringstream token_stream(str);
  while (getline(token_stream, token, delim))
  {
    tokens.push_back(token);
  }
  return tokens;
}

int main()
{
  string sentence;
  getline(cin, sentence);

  // Split the sentence into words
  vector<string> words = split(sentence, ' ');

  // Join the reversed words into a single string
  string reversed_sentence;
  for (size_t i = 0; i < words.size(); i++)
  {
    reverse(words[i].begin(), words[i].end());
    reversed_sentence += words[i];
    if (i < words.size() - 1)
    {
      reversed_sentence += ' ';
    }
  }

  cout << reversed_sentence << endl;
  return 0;
}