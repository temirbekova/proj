#include <cctype>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  string w;
  set<string> d;
  while (cin >> w) {
    string s;
    for (char e : w) {
      if (isalpha(e)) {
        s += tolower(e);
      } else if (!s.empty()) {
        d.insert(s);
        s.clear();
      }
    }
    if (!s.empty()) {
      d.insert(s);
    }
  }
  for (const string &e : d) {
    cout << e << '\n';
  }
  return 0;
}