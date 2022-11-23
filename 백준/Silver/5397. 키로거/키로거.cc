#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  list<char> p;

  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    auto cursor = p.begin();
    for (auto c : s) {
      if (c == '<') {
        if (cursor != p.begin()) cursor--;
      } else if (c == '>') {
        if (cursor != p.end()) cursor++;
      } else if (c == '-') {
        if (cursor != p.begin()) {
          cursor--;
          cursor = p.erase(cursor);
        }
      } else {
        p.insert(cursor, c);
      }
    }
    for (auto c : p)
      cout << c;
    cout << "\n";
    p.clear();
  }
}