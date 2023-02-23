#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  int n = a.length();
  int m = b.length();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i - 1] == b[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  int x = n;
  int y = m;
  string ans;
  while (dp[x][y] != 0) {
    int p = dp[x][y];
    if (p == dp[x - 1][y]) {
      x -= 1;
      continue;
    }
    if (p == dp[x][y - 1]) {
      y -= 1;
      continue;
    }
    ans.push_back(a[x - 1]);
    x -= 1;
    y -= 1;
  }
  reverse(ans.begin(), ans.end());
  cout << ans.length() << "\n" << ans;
}