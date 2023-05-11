#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  int ans = 1;

  while (a < b) {
    if (b % 2) {
      if (b % 10 == 1)
        b /= 10;
      else
        break;
    } else
      b /= 2;
    ans++;
  }
  if (a != b)
    cout << -1;
  else
    cout << ans;
}