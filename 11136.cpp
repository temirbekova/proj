#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    if (n == 0) {
      break;
    }
    multiset<int> bills;
    int64_t ans = 0;
    while (n--) {
      int k;
      cin >> k;
      while (k--) {
        int b;
        cin >> b;
        bills.insert(b);
      }
      ans += *bills.rbegin() - *bills.begin();
      bills.erase(bills.begin());
      bills.erase(--bills.end());
    }
    cout << ans << '\n';
  }
}