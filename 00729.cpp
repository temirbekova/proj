#include <iostream>

using namespace std;

char s[20];
int n, h;
void dfs(int i, int h) {
  if (h > i || h < 0)
    return;
  if (!i) {
    s[n] = '\0';
    cout << s << endl;
    return;
  }
  s[n - i] = '0';
  dfs(i - 1, h);
  s[n - i] = '1';
  dfs(i - 1, h - 1);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> h;
    dfs(n, h);
    if (t)
      cout << "\n";
  }
  return 0;
}