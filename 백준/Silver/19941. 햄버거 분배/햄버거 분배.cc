#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;
  vector<bool> eat(n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'H') continue;
    for (int j = i - k; j <= i + k; j++) {
      if (j < 0 || j >= n || i == j) continue;
      if (s[j] == 'P') continue;
      if (eat[j]) continue;
      eat[j] = true;
      ans++;
      break;
    }
  }
  cout << ans;
}