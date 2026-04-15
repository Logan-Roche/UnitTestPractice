#include "Password.h"
#include <string>
#include <cctype>
#include <set>

using std::set;
using std::string;

int Password::count_leading_characters(string phrase)
{
  int repetition = 1;
  int index = 0;
  while (index < phrase.length() - 1 && phrase[index] == phrase[index + 1])
  {
    repetition++;
    index++;
  }
  return repetition;
}

bool Password::has_mixed_case(string str)
{
  return has_upper(str) && has_lower(str);
}

bool Password::has_upper(string str)
{
  for (char c : str)
  {
    if (c >= 'A' && c <= 'Z')
      return true;
  }
  return false;
}

bool Password::has_lower(string str)
{
  for (char c : str)
  {
    if (c >= 'a' && c <= 'z')
      return true;
  }
  return false;
}

unsigned int Password::unique_characters(string phrase)
{
  set<char> seen;
  for (char c : phrase)
  {
    seen.insert(c);
  }
  return seen.size();
}