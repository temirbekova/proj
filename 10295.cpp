#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  int m, n;
  cin >> m >> n;
  unordered_map<string, double> dic;
  string s;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> s >> x;
    dic[s] = x;
  }
  while (n--) {
    int sum = 0;
    while (cin >> s && s[0] != '.') {
      if (dic.count(s)) {
        sum += dic[s];
      }
    }
    cout << sum << '\n';
  }
  return 0;
}