#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m;
  cin >> m;
  int s = 0;

  while (m--) {
    string op;
    int x;
    cin >> op;
    if (op == "all") {
      s |= (1 << 20) - 1;
      continue;
    } else if (op == "empty") {
      s = 0;
      continue;
    }
    cin >> x;
    if (op == "add") {
      s |= 1 << (x - 1);
    } else if (op == "remove") {
      s &= ~(1 << (x - 1));
    } else if (op == "check") {
      if (s & (1 << (x - 1)))
        cout << "1\n";
      else
        cout << "0\n";
    } else if (op == "toggle") {
      s ^= 1 << (x - 1);
    }
  }
}