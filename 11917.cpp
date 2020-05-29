#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    unordered_map<string, int> m;
    string text;
    int x;
    for (int j = 0; j < a; j++) {
      cin >> text >> x;
      m.insert(make_pair(text, x));
    }
    cin >> a;    // D
    cin >> text; // subject due
    if (m.find(text) == m.end())
      cout << "Case " << i << ": Do your own homework!" << endl;
    else if (m.find(text)->second <= a)
      cout << "Case " << i << ": Yesss" << endl;
    else if (m.find(text)->second <= (a + 5))
      cout << "Case " << i << ": Late" << endl;
    else
      cout << "Case " << i << ": Do your own homework!" << endl;
  }

  return 0;
}