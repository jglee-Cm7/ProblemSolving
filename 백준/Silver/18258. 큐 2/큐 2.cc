#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  queue<int> q;
  int n;
  cin >> n;
  while (n--) {
    string op;
    cin >> op;
    if (op == "push") {
      int v;
      cin >> v;
      q.push(v);
    } else if (op == "pop") {
      cout << (q.empty() == true ? -1 : q.front()) << "\n";
      if (!q.empty()) q.pop();
    } else if (op == "size") {
      cout << q.size() << "\n";
    } else if (op == "empty") {
      cout << (q.empty() == true ? 1 : 0) << "\n";
    } else if (op == "front") {
      cout << (q.empty() == true ? -1 : q.front()) << "\n";
    } else if (op == "back") {
      cout << (q.empty() == true ? -1 : q.back()) << "\n";
    }
  }
}