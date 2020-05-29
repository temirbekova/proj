#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int n;
  vector<queue<int>> v;
  for (int test = 1; cin >> n && n != 0; test++) {
    v.assign(n, queue<int>());
    queue<int> q;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      for (int j = 0; j < x; j++) {
        int y;
        cin >> y;
        m[y] = i;
      }
    }
    cout << "Scenario #" << test << "\n";
    string s;
    while (cin >> s) {
      if (s == "STOP") {
        break;
      } else if (s == "ENQUEUE") {
        int x;
        cin >> x;
        int c_x = m[x];
        if (v[c_x].empty()) {
          q.push(c_x);
        }
        v[c_x].push(x);
      } else {
        int nameOfTeam = q.front();
        int x = v[nameOfTeam].front();
        cout << x << "\n";
        v[nameOfTeam].pop();
        if (v[nameOfTeam].empty()) {
          q.pop();
        }
      }
    }
    cout << "\n";
  }
}