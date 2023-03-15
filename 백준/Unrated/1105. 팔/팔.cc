#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string l, r;
  cin >> l >> r;
  int ans = 0;
  if (l.size() != r.size()) {
    cout << "0";
    return 0;
  }
  for (int i = 0; i < (int)l.size(); i++) {
    if (l[i] == r[i] && l[i] == '8') ans++;
    if (l[i] != r[i]) break;
  }
  cout << ans;
}