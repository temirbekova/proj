#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    if (n == 0) {
      break;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
      q.push(i);
    }

    vector<int> v;
    while (q.size() > 1) {
      v.push_back(q.front());
      q.pop();
      int j = 0;
      j = q.front();
      q.pop();
      q.push(j);
    }

    cout << "Discarded cards:" << (n == 1 ? "" : " ");
    for (int i = 0; i < (int)v.size(); i++) {
      if (i) {
        cout << ", ";
      }
      cout << v[i];
    }

    cout << "\nRemaining card: " << q.front() << '\n';
  }
}