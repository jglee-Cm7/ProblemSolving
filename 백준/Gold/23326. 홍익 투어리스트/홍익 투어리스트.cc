#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  set<int> lm; // 명소의 인덱스
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    if (v) {
      lm.insert(i);
      lm.insert(i + n);
    }
  }

  int pos = 0;

  while (q--) {
    int op, v;
    cin >> op;
    if (op == 1) {
      cin >> v;
      v--;
      if (lm.find(v) == lm.end()) {
        lm.insert(v);
        lm.insert(v + n);
      } else {
        lm.erase(v);
        lm.erase(v + n);
      }
    } else if (op == 2) {
      cin >> v;
      pos = (pos + v) % n;
    } else if (op == 3) {
      auto it = lm.lower_bound(pos);
      if (it == lm.end())
        cout << "-1\n";
      else
        cout << (*it) - pos << "\n";
    }
  }
}