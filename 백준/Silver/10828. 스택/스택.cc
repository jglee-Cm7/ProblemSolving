#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  stack<int> s;
  int n;

  cin >> n;
  while (n--) {
    string op;
    int v;

    cin >> op;
    if (op == "push") {
      cin >> v;
      s.push(v);
    } else if (op == "top") {
      cout << (s.empty() == true ? -1 : s.top()) << "\n";
    } else if (op == "size") {
      cout << s.size() << "\n";
    } else if (op == "empty") {
      cout << (s.empty() == true ? 1 : 0) << "\n";
    } else if (op == "pop") {
      cout << (s.empty() == true ? -1 : s.top()) << "\n";
      if (!s.empty()) s.pop();
    }
  }
}