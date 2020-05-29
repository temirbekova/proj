#include <cctype>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  char ch;
  set<string> d;
  string s;
  while (cin.get(ch)) {
    if (isalpha(ch)) {
      s += tolower(ch);
    } else if (ch == '-') {
      s += ch;
    } else if (ch == '\n' && !s.empty() && s.back() == '-') {
      s.pop_back();
    } else if (!s.empty()) {
      d.insert(s);
      s = "";
    }
  }
  for (const string &e : d) {
    cout << e << '\n';
  }
  return 0;
}