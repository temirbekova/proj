#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
string a, b;
bool state;
vector<stack<string>> deck;
bool ok(string a, string b) { return a[0] == b[0] || a[1] == b[1]; }
void validate(vector<stack<string>>::iterator Index) {
  if (Index - deck.begin() > 2) {
    if (ok((Index - 3)->top(), Index->top())) {
      state = true;
      (Index - 3)->push(Index->top());
      Index->pop();
      if (Index->empty())
        deck.erase(Index);
      return;
    }
  }
  if (Index > deck.begin()) {
    if (ok((Index - 1)->top(), Index->top())) {
      state = true;
      (Index - 1)->push(Index->top());
      Index->pop();
      if (Index->empty())
        deck.erase(Index);
    }
  }
}

int main() {
  vector<stack<string>>::iterator it;
  while (true) {
    cin >> a;
    if (a == "#")
      return 0; // c[0][0] == '#'
    deck.clear();
    deck.push_back(stack<string>());
    deck.back().push(a);

    for (int i = 1; i < 52; i++) {
      cin >> a; // gets(c[0]);
      deck.push_back(stack<string>());
      deck.back().push(a);
    }

    state = true;
    while (state) {
      state = false;
      for (it = deck.begin(); it != deck.end(); it++) {
        validate(it);
        if (state)
          break;
      }
    }

    cout << deck.size() << " pile";
    if (deck.size() > 1)
      cout << 's';
    cout << " remaining:";
    for (int i = 0; i < int(deck.size()); i++) {
      cout << " " << deck[i].size();
    }
    cout << '\n';
  }
}