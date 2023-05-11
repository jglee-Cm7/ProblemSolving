#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int idx = -1;
  string x = "XXXX";
  while (1) {
    idx = s.find(x);
    if (idx != -1) {
      s.replace(idx, x.length(), "AAAA");
    } else {
      break;
    }
  }

  x = "XX";
  while (1) {
    idx = s.find(x);
    if (idx != -1) {
      s.replace(idx, x.length(), "BB");
    } else {
      break;
    }
  }
  for (char c : s) {
    if (c == 'X') {
      cout << -1;
      return 0;
    }
  }

  cout << s;
}