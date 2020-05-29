#include <bits/stdc++.h>
using namespace std;

int n;
char a[205][205];
bool visited[205][205], f;
int dx[] = {-1, -1, 0, 0, 1, 1};
int dy[] = {-1, 0, -1, 1, 0, 1};

void dfs(int x, int y) {

  visited[x][y] = true;

  for (int i = 0; i < 6; i++) {
    int xx = x + dx[i];
    int yy = y + dy[i];
    if (visited[xx][yy] == false && a[xx][yy] == 'b' && xx >= 0 && yy >= 0 &&
        yy < n && xx < n) {
      if (xx == n - 1) {
        f = true;
        return;
      }
      dfs(xx, yy);
    }
  }
}

int main() {

  int t = 0;
  while (cin >> n) {
    if (n == 0)
      break;

    t++;

    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++) {
      scanf("%s", &a[i]);
    }

    f = false;
    for (int i = 0; i < n; i++) {
      dfs(0, i);
      if (f == true)
        break;
    }
    if (f == true)
      printf("%d B\n", t);
    else
      printf("%d W\n", t);
  }

  return 0;
}