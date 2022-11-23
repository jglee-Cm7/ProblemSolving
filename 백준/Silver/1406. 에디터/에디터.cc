#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  int m;
  cin >> s >> m;
  list<char> answer;
  for (auto c : s)
    answer.push_back(c);
  auto pos = answer.end();
  while (m--) {
    char cmd, value;
    cin >> cmd;
    if (cmd == 'P') {
      cin >> value;
      answer.insert(pos, value);
    } else if (cmd == 'L') {
      if (pos != answer.begin())
        pos--;
    } else if (cmd == 'D') {
      if (pos != answer.end())
        pos++;
    } else {
      if (pos != answer.begin()) {
        pos--;
        pos = answer.erase(pos);
      }
    }
  }

  for (auto c : answer)
    cout << c;
}