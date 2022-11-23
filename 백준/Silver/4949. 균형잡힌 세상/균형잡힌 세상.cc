#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (1) {
    stack<char> s;
    string ss;
    getline(cin, ss);
    if (ss[0] == '.') break;

    bool y = true;
    for (auto c : ss) {
      if (c == '(' || c == '[') {
        s.push(c);
      }

      if (c == ')') {
        if (s.empty() || s.top() != '(') {
          y = false;
          break;
        }
        s.pop();
      }

      if (c == ']') {
        if (s.empty() || s.top() != '[') {
          y = false;
          break;
        }
        s.pop();
      }
    }

    if (!s.empty()) y = false;

    if (y)
      cout << "yes"
           << "\n";
    else
      cout << "no"
           << "\n";
  }
}