#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;

  int ans = INT_MAX;
  for (int i = 0; i <= n / 5; i++) {
    int cnt = i;
    int v = n - 5 * i;
    if (v % 2 == 0) {
      cnt += v / 2;
      ans = min(ans, cnt);
    }
  }

  if (ans == INT_MAX)
    cout << -1;
  else
    cout << ans;
}