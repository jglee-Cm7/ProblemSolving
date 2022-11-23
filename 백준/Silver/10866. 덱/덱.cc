#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  deque<int> q;
  int n;
  cin >> n;

  while (n--) {
    string op;
    int v;
    cin >> op;

    if (op == "push_front") {
      cin >> v;
      q.push_front(v);
    } else if (op == "push_back") {
      cin >> v;
      q.push_back(v);
    } else if (op == "pop_front") {
      if (q.empty()) {
        cout << -1 << "\n";
      } else {
        cout << q.front() << "\n";
        q.pop_front();
      }
    } else if (op == "pop_back") {
      if (q.empty()) {
        cout << -1 << "\n";
      } else {
        cout << q.back() << "\n";
        q.pop_back();
      }
    } else if (op == "size") {
      cout << q.size() << "\n";
    } else if (op == "empty") {
      cout << q.empty() << "\n";
    } else if (op == "front") {
      if (q.empty())
        cout << -1 << "\n";
      else
        cout << q.front() << "\n";
    } else if (op == "back") {
      if (q.empty())
        cout << -1 << "\n";
      else
        cout << q.back() << "\n";
    }
  }
}