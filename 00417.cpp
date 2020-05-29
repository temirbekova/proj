#include <iostream>
#include <unordered_map>

using namespace std;

void gen(int length, int index, string &a, unordered_map<string, int> &dic,
         int &j) {
  if (index == length) {
    dic[a] = ++j;
  } else {
    int b = index > 0 ? a[index - 1] + 1 : 'a';
    for (char k = b; k <= 'z'; k++) {
      a[index] = k;
      gen(length, index + 1, a, dic, j);
    }
  }
}

int main() {
  string word;
  unordered_map<string, int> dic;
  int j = 0;
  for (int i = 1; i <= 5; i++) {
    word.resize(i);
    gen(i, 0, word, dic, j);
  }
  while (cin >> word) {
    if (dic.count(word)) {
      cout << dic[word] << "\n";
    } else {
      cout << "0\n";
    }
  }
}