#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    unordered_map<int, int> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    for (int l = 0, r = 0; l < n; l++) {
      while (r < n && m[a[r]] == 0) {
        m[a[r]]++;
        r++;
      }
      ans = max(ans, r - l);
      m.erase(a[l]);
    }
    cout << ans << '\n';
  }
  return 0;
}