#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  string a, b;
  int n;
  cin >> n;
  unordered_map<string, string> m;
  for (int i = 0; i < n; i++) {
    getline(cin, a);
    getline(cin, b);
    m.insert(make_pair(a, b));
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    string x;
    getline(cin, x);
    cout << m.find(x)->second << endl;
  }

  return 0;
}