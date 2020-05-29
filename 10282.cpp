#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<string, string> dic;

  // read in dictionary
  string temp, second;
  getline(cin, temp);
  while (temp != "") {
    stringstream ss(temp);
    ss >> temp >> second;
    dic[second] = temp;
    getline(cin, temp);
  }
  // read in foreign words
  while (cin >> second) {
    if (dic.count(second)) {
      cout << dic[second] << '\n';
    } else {
      cout << "eh\n";
    }
  }
}