
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  stack<int> s;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;

    while (!s.empty() && s.top() > y) {
      s.pop();
      ans++;
    }
    if (y == 0) continue;
    if (s.empty()) {
      s.push(y);
      continue;
    }

    if (s.top() == y) continue;
    s.push(y);
  }

  ans += (int)s.size();
  cout << ans;
}