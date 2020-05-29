#include <cctype>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; test++) {
    set<string> s;
    vector<string> a;
    unordered_map<string, int> m;
    while (true) {
      string line;
      cin >> line;
      if (line == "END") {
        break;
      }
      string cur;
      int ln = line.length();
      for (int i = 0; i <= ln; i++) {
        if (isalpha(line[i])) {
          cur += line[i];
        } else if (cur.size() > 0) {
          s.insert(cur);
          a.emplace_back(cur);
          cur = "";
        }
      }
    }
    int ansl = 0, ansr = a.size();
    for (int l = 0, r = 0; l < a.size(); l++) {
      while (r < a.size() && m.size() < s.size()) {
        m[a[r]]++;
        r++;
      }
      if (m.size() == s.size() && ansr - ansl > r - l) {
        ansl = l;
        ansr = r;
      }
      m[a[l]]--;
      if (m[a[l]] == 0) {
        m.erase(a[l]);
      }
    }
    cout << "Document " << test << ": " << ansl + 1 << " " << ansr << '\n';
  }
  return 0;
}