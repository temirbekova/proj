#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>

using namespace std;
int main() {
  int n;
  cin >> n;
  cin.ignore();
  cin.ignore();
  for (int i = 0; i < n; i++) {
    map<string, int> a;
    map<string, int>::iterator itr;
    string tree;
    int count = 0;
    while (getline(cin, tree)) {
      if (tree.length() == 0)
        break;
      ++a[tree];
      count++;
    }
    double percent = 100.0 / count;
    for (itr = a.begin(); itr != a.end(); ++itr) {
      double often = itr->second * percent;
      cout << itr->first << " " << setprecision(4) << fixed << often << '\n';
    }
    if (i != n - 1) {
      cout << "\n";
    }
  }
}