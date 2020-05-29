#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  string s;
  int count = 1;
  while (cin >> s) {
    if (s == "end") {
      break;
    }
    vector<stack<char>> v;
    for (char i : s) {
      bool n = true;
      for (int j = 0; j < (int)v.size(); j++) {
        if (v[j].top() >= i) {
          v[j].push(i);
          n = false;
          break;
        }
      }
      if (n) {
        v.push_back(stack<char>({i}));
      }
    }
    cout << "Case " << count << ": " << v.size() << "\n";
    count++;
  }
}