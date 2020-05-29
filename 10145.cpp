#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  bool bline = false;

  while (tests--) {
    if (bline) {
      cout << "\n";
    } else {
      bline = true;
    }
    unordered_map<int, unordered_set<int>> x, s;
    unordered_set<int> ign;
    while (true) {
      cin.ignore();
      char mode;
      cin >> mode;
      if (mode == '#') {
        break;
      }
      int trid, item;
      cin >> trid >> item;
      if (ign.count(trid)) {
        cout << "IGNORED\n";
        continue;
      }
      if (mode == 'X') {
        if ((x[item].empty() || x[item].count(trid)) &&
            (s[item].empty() || (s[item].size() == 1 && s[item].count(trid)))) {
          cout << "GRANTED\n";
          x[item].insert(trid);
        } else {
          cout << "DENIED\n";
          ign.insert(trid);
        }
      } else {
        if (x[item].empty() || x[item].count(trid)) {
          cout << "GRANTED\n";
          s[item].insert(trid);
        } else {
          cout << "DENIED\n";
          ign.insert(trid);
        }
      }
    }
  }
  return 0;
}