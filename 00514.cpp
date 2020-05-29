#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

  int n;
  vector<int> b;

  while (cin >> n && n != 0) {
    b.resize(n);
    while (cin >> b[0] && b[0] != 0) {
      stack<int> st;
      for (int i = 1; i < n; i++) {
        cin >> b[i];
      }
      int j = 0;
      for (int i = 1; i <= n; i++) {
        st.push(i);
        while (st.size() > 0 && st.top() == b[j]) {
          st.pop();
          j++;
        }
      }
      cout << (st.empty() ? "Yes\n" : "No\n");
    }
    cout << '\n';
  }
}