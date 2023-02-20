#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int i = 0;
  int n = s.length();
  int v = 1;
  while (v) {
    string sv = to_string(v);
    for (char c : sv) {
      if (c == s[i]) i++;
      if (i == n) break;
    }
    if (i == n) break;
    v++;
  }
  cout << v;
}