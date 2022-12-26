#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

  for (int i = 1; i <= n; i++) {
    int prev = 0;
    for (int j = 1; j <= n; j++) {
      int v;
      cin >> v;
      dp[i][j] = prev + v;
      prev += v;
    }
  }
  for (int i = 0; i < m; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int ans = 0;
    for (int j = x1; j <= x2; j++)
      ans += dp[j][y2] - dp[j][y1 - 1];
    cout << ans << "\n";
  }
}