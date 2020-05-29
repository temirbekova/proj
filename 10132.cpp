#include <cctype>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  string s;
  int n;
  cin >> n;
  // Skip the first empty line.
  cin.ignore();
  cin.ignore();
  while (n--) {
    vector<string> fragments;

    while (getline(cin, s)) {
      if (s.length() == 0) {
        break;
      }
      fragments.push_back(s);
    }

    // Consider all concatenations of any two strings.
    map<string, int> memo;
    for (size_t i = 0; i < fragments.size(); ++i)
      for (size_t j = i + 1; j < fragments.size(); ++j) {
        ++memo[fragments[i] + fragments[j]];
        ++memo[fragments[j] + fragments[i]];
      }

    // Search for the string of highest count.
    map<string, int>::iterator iter(memo.begin());
    map<string, int>::iterator file(memo.begin());
    for (; iter != memo.end(); ++iter) {
      if (iter->second > file->second)
        file = iter;
    }
    cout << file->first << endl;
    if (n)
      cout << endl;
  }
  return 0;
}