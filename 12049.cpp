#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  while (tests--) {
    unordered_multiset<int> s;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      s.insert(x);
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      if (s.count(x)) {
        cnt++;
        s.erase(s.find(x));
      }
    }
    cout << n + m - cnt * 2 << endl;
  }
  return 0;
}