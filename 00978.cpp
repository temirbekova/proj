#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int b, sg, sb;
    cin >> b >> sg >> sb;
    multiset<int, greater<int>> gpow;
    for (int i = 0; i < sg; i++) {
      int x;
      cin >> x;
      gpow.insert(x);
    }
    multiset<int, greater<int>> bpow;
    for (int i = 0; i < sb; i++) {
      int x;
      cin >> x;
      bpow.insert(x);
    }

    while (!bpow.empty() && !gpow.empty()) {
      int j = 0;
      int minSize = min(b, (int)min(bpow.size(), gpow.size()));
      vector<int> c, d;
      for (int i = 0; i < minSize; i++) {
        if (*gpow.begin() > *bpow.begin()) {
          j = *gpow.begin() - *bpow.begin();
          c.push_back(j);
          gpow.erase(gpow.begin());
          bpow.erase(bpow.begin());
        } else if (*gpow.begin() < *bpow.begin()) {
          j = *bpow.begin() - *gpow.begin();
          d.push_back(j);
          gpow.erase(gpow.begin());
          bpow.erase(bpow.begin());
        } else {
          gpow.erase(gpow.begin());
          bpow.erase(bpow.begin());
        }
      }
      for (int e : c) {
        gpow.insert(e);
      }
      for (int e : d) {
        bpow.insert(e);
      }
    }

    if (bpow.empty() && gpow.empty()) {
      cout << "green and blue died\n";
    } else if (bpow.size()) {
      cout << "blue wins\n";
      for (int e : bpow) {
        cout << e << '\n';
      }
    } else {
      cout << "green wins\n";
      for (int e : gpow) {
        cout << e << '\n';
      }
    }
    if (n) {
      cout << '\n';
    }
  }
}