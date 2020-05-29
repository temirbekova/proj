#include <iostream>
#include <set>

using namespace std;

int main() {
  int n, m;
  while (cin >> n && cin >> m) {
    if (n == 0 && m == 0) {
      break;
    }
    set<int> sell;
    int a;
    for (int i = 0; i < n; i++) {
      cin >> a;
      sell.insert(a);
    }
    int sum = 0;
    for (int i = 0; i < m; i++) {
      cin >> a;
      if (sell.find(a) == sell.end()) {
        sell.insert(a);
      } else {
        sum++;
      }
    }
    cout << sum << '\n';
  }
}