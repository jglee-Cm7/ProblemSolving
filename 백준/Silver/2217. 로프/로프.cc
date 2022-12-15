#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> rope(n);
  for (int &r : rope)
    cin >> r;
  sort(rope.begin(), rope.end(), greater<>());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, rope[i] * (i + 1));
  }
  cout << ans;
}