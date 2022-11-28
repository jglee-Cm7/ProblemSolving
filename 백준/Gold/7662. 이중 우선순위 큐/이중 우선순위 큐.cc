#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    multiset<int> s;
    while (k--) {
      char op;
      int v;
      cin >> op >> v;
      if (op == 'I') s.insert(v);
      if (!s.empty() && op == 'D') {
        if (v == 1)
          s.erase(prev(s.end()));
        else if (v == -1)
          s.erase(s.begin());
        else
          s.erase(v);
      }
    }
    if (s.empty())
      cout << "EMPTY\n";
    else
      cout << *prev(s.end()) << " " << *s.begin() << "\n";
  }
}