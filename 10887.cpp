#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int cases, n, m;
  string str;

  cin >> cases;
  for (int i = 1; i <= cases; i++) {
    vector<string> vec1, vec2;
    set<string> mySet;
    cin >> n >> m;
    getline(cin, str);

    for (int x = 1; x <= n; x++) {
      getline(cin, str);
      vec1.push_back(str);
    }
    for (int x = 1; x <= m; x++) {
      getline(cin, str);
      vec2.push_back(str);
    }

    string tmp;
    for (int x = 0; x < vec1.size(); x++)
      for (int y = 0; y < vec2.size(); y++) {
        tmp = vec1[x] + vec2[y];
        mySet.insert(tmp);
      }
    cout << "Case " << i << ": " << mySet.size() << "\n";
  }
  return 0;
}
