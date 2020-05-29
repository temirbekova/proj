#include <iostream>

using namespace std;

int num[5];
bool isAble;
bool vis[5];

void dfs(int numOfElements, int sum) {
  if (sum == 23 && numOfElements == 5) {
    isAble = true;
    return;
  } else {
    for (int i = 0; i < 5; i++) {
      if (!vis[i]) {
        vis[i] = 1;
        dfs(numOfElements + 1, sum + num[i]);
        dfs(numOfElements + 1, sum * num[i]);
        dfs(numOfElements + 1, sum - num[i]);
        vis[i] = 0;
      }
    }
  }
}
int main() {
  while (cin >> num[0] >> num[1] >> num[2] >> num[3] >> num[4]) {

    if (num[0] == 0 && num[1] == 0 && num[2] == 0 && num[3] == 0 && num[4] == 0)
      return 0;

    isAble = false;
    for (int i = 0; i < 5; i++) {
      vis[i] = 1;
      dfs(1, num[i]);
      vis[i] = 0;
    }

    if (isAble)
      printf("Possible\n");
    else
      printf("Impossible\n");
  }
}