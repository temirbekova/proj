#include <iostream>
#include <vector>

using namespace std;

int REQ, KOLVO, best = 0;
int tracks[30];
vector<int> bestpath;

void dfs(vector<int> path, int sum, int n) {
  sum += tracks[n];
  path.push_back(tracks[n]);
  if (sum > best) {
    best = sum;
    bestpath = path;
  }
  for (int i = n + 1; i < KOLVO; i++) {
    if (sum + tracks[i] <= REQ)
      dfs(path, sum, i);
  }
}

int main() {
  while (cin >> REQ) {
    cin >> KOLVO;
    for (int i = 0; i < KOLVO; i++) {
      cin >> tracks[i];
    }
    best = 0;
    for (int i = 0; i < KOLVO; i++) {
      vector<int> path;
      dfs(path, 0, i);
    }
    for (int j = 0; j < bestpath.size(); j++)
      cout << bestpath[j] << " ";
    cout << "sum:" << best << "\n";
  }
#include <iostream>
#include <vector>

using namespace std;

int REQ, KOLVO, best = 0;
int tracks[30];
vector<int> bestpath;

void dfs(vector<int> path, int sum, int n) {
  sum += tracks[n];
  path.push_back(tracks[n]);
  if ((sum > best) || ((sum == best) && (path.size() > bestpath.size()))) {
    best = sum;
    bestpath = path;
  }
  for (int i = n + 1; i < KOLVO; i++) {
    if (sum + tracks[i] <= REQ)
      dfs(path, sum, i);
  }
}

int main() {
  while (cin >> REQ) {
    cin >> KOLVO;
    for (int i = 0; i < KOLVO; i++) {
      cin >> tracks[i];
    }
    best = 0;
    for (int i = 0; i < KOLVO; i++) {
      vector<int> path;
      dfs(path, 0, i);
    }
    for (int j = 0; j < bestpath.size(); j++)
      cout << bestpath[j] << " ";
    cout << "sum:" << best << "\n";
  }
}