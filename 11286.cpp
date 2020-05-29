#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int n;
  while (cin >> n and n) {
    int max = 0;
    map<vector<int>, int> frosh;
    vector<int> arr(5);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> arr[j];
      }
      sort(arr.begin(), arr.end());
      if (frosh.count(arr) == 1) {
        frosh[arr]++;
      } else {
        frosh[arr] = 1;
      }
    }
    // map<vector<int>, int>::iterator i;
    for (auto i = frosh.begin(); i != frosh.end(); ++i) {
      if ((i->second) > max) {
        max = i->second;
      }
    }
    int count = 0;
    for (auto i = frosh.begin(); i != frosh.end(); ++i) {
      if ((i->second) == max) {
        count++;
      }
    }
    max = max * count;

    cout << max << '\n';

    frosh.clear();
  }

  return 0;
}