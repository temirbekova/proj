#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
  vector<int> v;
  map<int, int> m;
  int n;
  while (cin >> n) {
    v.push_back(n);
    m[n]++;
  }
  set<int> s;
  for (int e : v) {
    if (s.find(e) == s.end()) {
      cout << e << " " << m[e] << "\n";
      s.insert(e);
    }
  }
}