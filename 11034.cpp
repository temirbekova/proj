#include <iostream>
#include <queue>

using namespace std;

int main() {
  int c;
  cin >> c;
  while (c--) {
    int l, m;
    cin >> l >> m;
    l *= 100;
    queue<int> q[2];
    for (int i = 0; i < m; i++) {
      int x;
      string s;
      cin >> x >> s;
      if (s == "left") {
        q[0].push(x);
      } else {
        q[1].push(x);
      }
    }
    int t = 0, ans = 0;
    while (q[0].size() + q[1].size() > 0) {
      int sm = 0;
      while (q[t].size() > 0 && q[t].front() + sm <= l) {
        sm += q[t].front();
        q[t].pop();
      }
      if (sm != 0 || q[t ^ 1].size() != 0) {
        t ^= 1;
        ans++;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}